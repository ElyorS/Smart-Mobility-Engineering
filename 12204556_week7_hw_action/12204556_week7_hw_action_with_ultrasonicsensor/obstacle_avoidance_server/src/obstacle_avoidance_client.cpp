#include <memory>
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "obstacle_avoidance/action/obstacle_avoidance.hpp"

class ObstacleAvoidanceClient : public rclcpp::Node
{
public:
  using ObstacleAvoidance = obstacle_avoidance::action::ObstacleAvoidance;
  using GoalHandleObstacleAvoidance = rclcpp_action::ClientGoalHandle<ObstacleAvoidance>;

  explicit ObstacleAvoidanceClient(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
    : Node("obstacle_avoidance_client", options)
  {
    client_ = rclcpp_action::create_client<ObstacleAvoidance>(
      this, "obstacle_avoidance");

    // Wait for the action server to become available
    if (!client_->wait_for_action_server(std::chrono::seconds(10))) {
      RCLCPP_ERROR(get_logger(), "Action server not available after waiting.");
    }

    send_goal();
  }

  void send_goal()
  {
    auto goal_msg = ObstacleAvoidance::Goal();
    goal_msg.distance = 5; // Set the desired obstacle distance

    RCLCPP_INFO(get_logger(), "Sending goal request...");

    auto send_goal_options = rclcpp_action::Client<ObstacleAvoidance>::SendGoalOptions();

    // Callback for goal acknowledgment
    send_goal_options.goal_response_callback =
      std::bind(&ObstacleAvoidanceClient::goal_response_callback, this, std::placeholders::_1);

    // Callback for result
    send_goal_options.result_callback =
      std::bind(&ObstacleAvoidanceClient::result_callback, this, std::placeholders::_1);

    // Send the goal
    client_->async_send_goal(goal_msg, send_goal_options);
  }

  void goal_response_callback(std::shared_future<GoalHandleObstacleAvoidance::SharedPtr> future)
  {
    auto goal_handle = future.get();
    if (!goal_handle) {
      RCLCPP_ERROR(get_logger(), "Goal was rejected by the server");
      return;
    }

    RCLCPP_INFO(get_logger(), "Goal accepted by the server, waiting for result...");
  }

  void result_callback(const GoalHandleObstacleAvoidance::WrappedResult & result)
  {
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
        RCLCPP_INFO(get_logger(), "Goal was successful. Obstacle cleared.");
        break;
      case rclcpp_action::ResultCode::ABORTED:
        RCLCPP_ERROR(get_logger(), "Goal was aborted.");
        break;
      case rclcpp_action::ResultCode::CANCELED:
        RCLCPP_ERROR(get_logger(), "Goal was canceled before completion.");
        break;
      default:
        RCLCPP_ERROR(get_logger(), "Unknown result code");
        break;
    }

    rclcpp::shutdown();
  }

private:
  rclcpp_action::Client<ObstacleAvoidance>::SharedPtr client_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ObstacleAvoidanceClient>());
  rclcpp::shutdown();
  return 0;
}

