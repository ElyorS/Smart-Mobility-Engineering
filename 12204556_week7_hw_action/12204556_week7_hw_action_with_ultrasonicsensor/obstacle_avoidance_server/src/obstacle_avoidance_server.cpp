#include <functional>
#include <memory>
#include <thread>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "obstacle_avoidance/action/obstacle_avoidance.hpp"

namespace obstacle_avoidance_server
{
class ObstacleAvoidanceActionServer : public rclcpp::Node
{
public:
  using ObstacleAvoidance = obstacle_avoidance::action::ObstacleAvoidance;
  using GoalHandleObstacleAvoidance = rclcpp_action::ServerGoalHandle<ObstacleAvoidance>;

  ObstacleAvoidanceActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
    : Node("obstacle_avoidance_action_server", options)
  {
    using namespace std::placeholders;

    // Create the action server for the "obstacle_avoidance" action
    action_server_ = rclcpp_action::create_server<ObstacleAvoidance>(
      this,
      "obstacle_avoidance",
      std::bind(&ObstacleAvoidanceActionServer::handle_goal, this, _1, _2),
      std::bind(&ObstacleAvoidanceActionServer::handle_cancel, this, _1),
      std::bind(&ObstacleAvoidanceActionServer::handle_accepted, this, _1));

    RCLCPP_INFO(get_logger(), "Obstacle Avoidance Action Server is ready.");
  }

private:
  // Callback for handling new goal requests
  void handle_goal(const GoalHandleObstacleAvoidance::SharedPtr goal_handle)
  {
    RCLCPP_INFO(get_logger(), "Received goal request. Executing...");

    // Create a separate thread for execution to keep the server responsive
    std::thread{std::bind(&ObstacleAvoidanceActionServer::execute, this, goal_handle)}.detach();
  }

  // Simulated execution of the action
  void execute(const GoalHandleObstacleAvoidance::SharedPtr goal_handle)
  {
    auto feedback_msg = std::make_shared<ObstacleAvoidance::Feedback>();
    auto & feedback = feedback_msg->moving;

    for (int i = 0; i < 100; ++i)
    {
      if (goal_handle->is_canceling())
      {
        feedback = false;
        goal_handle->canceled(feedback_msg);
        RCLCPP_INFO(get_logger(), "Goal was canceled.");
        return;
      }

      // Simulate obstacle detection based on ultrasonic sensor data.
      bool obstacle_detected = (goal_handle->get_goal()->distance <= 10);

      if (obstacle_detected)
      {
        feedback = false;
        goal_handle->succeed(feedback_msg);
        RCLCPP_INFO(get_logger(), "Obstacle detected. Goal succeeded.");
        return;
      }

      feedback = true;
      goal_handle->publish_feedback(feedback_msg);

      // Simulate a delay in moving.
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    feedback = false;
    goal_handle->succeed(feedback_msg);
    RCLCPP_INFO(get_logger(), "Goal completed successfully.");
  }

  // Callback for handling accepted goals
  void handle_accepted(const std::shared_ptr<GoalHandleObstacleAvoidance> goal_handle)
  {
    (void)goal_handle;
    RCLCPP_INFO(get_logger(), "Accepted new goal request.");
  }

  // Callback for handling goal cancellation
  void handle_cancel(const std::shared_ptr<GoalHandleObstacleAvoidance> goal_handle)
  {
    (void)goal_handle;
    RCLCPP_INFO(get_logger(), "Received cancel request.");
  }

  rclcpp_action::Server<ObstacleAvoidance>::SharedPtr action_server_;
};

}  // namespace obstacle_avoidance_server

RCLCPP_COMPONENTS_REGISTER_NODE(obstacle_avoidance_server::ObstacleAvoidanceActionServer)

