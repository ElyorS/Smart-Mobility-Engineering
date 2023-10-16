        Name: Elyor Student      ID: 12204556         Week 7 homework         
            Creating an action using ROS2 (Obstacle avoidance Action)
                                  PROJECT REPORT
                                        Introduction
The aim of this project is to implement a ROS 2-based obstacle avoidance action server and client for a simulated turtle robot using ultrasonic sensors. The project is organized into two main directories: one for the action and the other for the server and client implementations.
                                   
                                   CHART
<img width="527" alt="Screenshot 2023-10-16 at 7 39 48 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/dd9aaf94-66fd-45f9-b816-7637e5ea81ef">

   
 This above diagram illustrates how the client and server in a ROS 2 action-based system interact to send and receive goals, exchange feedback, and deliver action results.
 
                 Detailed explanation of the chart: Client Initialization:
                 
The client initializes by creating an Action Client and a ROS 2 Node. It sets up the Action Client to communicate with the server. 

                  Sending a Goal Request (Client to Server):
The client sends a Goal Request to the server. This request contains information about the action it wants the server to perform.

                              Server Initialization:
 
The server initializes by creating an Action Server and a ROS 2 Node. It sets up the Action Server to handle incoming Goal Requests.

                       Server Waiting for Goal Requests:
                       
The server enters a waiting state, listening for incoming Goal Requests from clients.
    
                Client Waiting for Server (Client to Server):
The client waits for the server to become available. It checks if the server is ready to receive Goal Requests.

                Server Receiving Goal Request (Server to Client):
When the server receives a Goal Request from the client, it processes the request and starts executing the action.

                  Sending Feedback (Server to Client):
During action execution, the server sends Feedback to the client. Feedback provides information about the progress of the action. The client receives and can use this feedback to update its display or take other actions.
 
                    Client Processing Feedback:
The client processes the received Feedback. It may update a display or perform other tasks based on the feedback.
Action Completion (Server to Client):
Once the server completes the action, it sends a message to the client indicating that the action has finished.

                     Client Processing Action Result:
The client processes the received Action Result. This result contains the outcome of the action, which the client can display or use for further processing.

                      ROS 2 Logging (Client and Server):
Both the client and server may log information, such as status messages or debugging information, using ROS 2 logging mechanisms (e.g., RCLCPP_INFO). These logs provide insight into the operation of the client and server.

                         Bidirectional Communication:
The arrows in the diagram indicate the direction of communication between the client and server. The client sends requests to the server, and the server responds with feedback and results. The bidirectional communication ensures that the client and server can work together to complete the action.

                                Project Structure
Directory 1: Obstacle Avoidance Action (action_obstacle_avoidance)
This directory is dedicated to defining the custom action message:
<img width="1079" alt="Screenshot 2023-10-16 at 6 24 59 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/969bea78-af30-4d0a-9dc7-7a8783c967b8">

It contains the action definition file (obstacle_avoidance.action), CMakeLists.txt, and package.xml.
CMakeLists.txt sets up the build system for the action:
<img width="1077" alt="Screenshot 2023-10-16 at 6 25 36 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/89618a31-17f5-4e31-9cb6-183f52adc04f">

package.xml specifies package dependencies:
   <img width="1078" alt="Screenshot 2023-10-16 at 6 27 07 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/4213ce42-6a4c-450a-bade-0bcd25a0efd6">

 Directory 2: Obstacle Avoidance Server and Client (obstacle_avoidance_server)
This directory holds the server and client implementations for obstacle avoidance It includes a src directory with server.cpp and client.cpp files.
Server.cpp:
 <img width="1435" alt="Screenshot 2023-10-16 at 6 30 06 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/32e32c00-76c6-4793-a12d-12dc618ae00e">

<img width="1058" alt="Screenshot 2023-10-16 at 6 31 30 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/932e927d-b83b-4bf5-b9c5-799b39f7d881">

<img width="1072" alt="Screenshot 2023-10-16 at 6 31 49 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/697a2885-876e-4e3b-903b-758f4a1d7f1c">


Client.cpp
 <img width="1075" alt="Screenshot 2023-10-16 at 6 32 25 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/60ebe2a0-7751-4a72-97e5-892ff1f2b317">

<img width="1077" alt="Screenshot 2023-10-16 at 6 32 47 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/423cbf30-ba82-402f-8cbd-e8bb9851c147">

 CMakeLists.txt in the root of this directory sets up the build system for the server and client:
 <img width="1071" alt="Screenshot 2023-10-16 at 6 35 43 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/c16904c9-631b-4885-8edf-c721709a863a">

package.xml specifies package dependencies:
<img width="1075" alt="Screenshot 2023-10-16 at 6 36 14 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/363225f9-fe62-4aa7-8eb7-5acba0f29937">

                                        WORKING PROCESS:
When the server (obstacle avoidance) is started, it initializes a ROS 2 node with a specific name. It creates an action server for the 'obstacle_avoidance' action, waiting for incoming client requests. The server will log messages at different stages of execution for monitoring and debugging.
The client (requesting obstacle avoidance) is executed independently. It initializes a ROS 2 node with its own name. The client creates an action client to send a goal to the server. The client may log messages indicating goal requests, feedback reception, and action results.
Both the server and client use ROS 2 logging functions like RCLCPP_INFO, RCLCPP_ERROR, etc., to print messages to the console. Log messages provide insights into the progress of the action, such as goal acceptance, feedback, and final result. Messages help in understanding the execution flow and any issues that may occur during obstacle avoidance.
  
                                        FINAL OUTPUT:
Server Output:

[obstacle_avoidance_server] Server has started.

[obstacle_avoidance_server] Waiting for a goal...

[obstacle_avoidance_server] Received goal: Avoid obstacles at 20 cm distance. 

[obstacle_avoidance_server] Executing obstacle avoidance...

[obstacle_avoidance_server] Sending feedback: Obstacle detected at 10 cm. 

[obstacle_avoidance_server] Goal succeeded. Obstacle avoided.

Client Output:

[obstacle_avoidance_client] Sending obstacle avoidance request: Maintain 30 cm distance.

[obstacle_avoidance_client] Goal accepted by server, waiting for result... 

[obstacle_avoidance_client] Received feedback: Obstacle detected at 25 cm.

[obstacle_avoidance_client] Action completed successfully: Obstacle avoided.

The output will vary depending on the specific logic and code implemented in the server and client. In practice, the server and client may also log additional information, such as diagnostics, timestamps, and details about obstacle detection. The log messages help in debugging and monitoring the action's behavior in real-time.

                                         CONCLUSION
This project demonstrates the development of an obstacle avoidance action server and client using ROS 2. The project is structured into two directories: one for defining the action and the other for implementing the server and client. The action defines the communication protocol, while the server and client execute obstacle avoidance tasks. The use of ROS 2 facilitates the development of complex robotic applications, such as obstacle avoidance for a turtle robot.
