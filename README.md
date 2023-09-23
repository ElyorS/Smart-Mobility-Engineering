#The below link is the shell file for the commands regarding CLI tools:
https://github.com/ElyorS/Smart-Mobility-Engineering/blob/7bc19b555c732307071df515ca237a78e47b871a/12204556_cli_tools.sh



<img width="979" alt="Screenshot 2023-09-21 at 11 34 39 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/a180a138-490e-4cac-a97b-e2e8c0e77227"># Smart-Mobility-Engineering
ROS installation bash history shell file

#To start turtlesim, enter the following command in your terminal and the you will see the below window in the image

ros2 run turtlesim turtlesim_node

<img width="987" alt="Screenshot 2023-09-20 at 9 55 11 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/0830395a-97ac-4a8a-bfdf-1ddb79e8a6c6">


#Now you will run a new node to control the turtle in the first node:

ros2 run turtlesim turtle_teleop_key

<img width="984" alt="Screenshot 2023-09-20 at 9 57 27 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/505afc3b-b0f2-4181-a029-cf94cc30d935">

#When running rqt for the first time, the window will be blank. No worries; just select Plugins > Services > Service Caller from the menu bar at the top. Let’s use rqt to call the /spawn service. Next enter some valid coordinates at which to spawn the new turtle, like x = 1.0 and y = 1.0. To spawn turtle2, you then need to call the service by clicking the Call button on the upper right side of the rqt window. 

rqt 

<img width="1253" alt="Screenshot 2023-09-20 at 10 07 37 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/63f28aaa-733a-443c-b92e-aa369f96e04b">

#To have turtle1 draw with a distinct red line, change the value of r to 255, and the value of width to 5.

<img width="1265" alt="Screenshot 2023-09-20 at 10 13 12 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/78b31fa7-eb6e-4a9c-9538-76ab77a935ee">

#You need a second teleop node in order to control turtle2. However, if you try to run the same command as before, you will notice that this one also controls turtle1. The way to change this behavior is by remapping the cmd_vel topic.
In a new terminal, source ROS 2, and run:

ros2 run turtlesim turtle_teleop_key --ros-args --remap turtle1/cmd_vel:=turtle2/cmd_vel

<img width="987" alt="Screenshot 2023-09-20 at 10 16 18 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/e73c55c5-7cb5-462e-8de2-f95193dc0912">

#ros2 node list will show you the names of all running nodes
ros2 node list

#reassign the name of our /turtlesim node. In a new terminal, run the following command:

ros2 run turtlesim turtlesim_node --ros-args --remap __node:=my_turtle

<img width="1008" alt="Screenshot 2023-09-20 at 10 38 27 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/e77d4a92-47b8-4c5b-81b8-5497f4c2ead9">

#Now that you know the names of your nodes, you can access more information about them with:
ros2 node info /my_turtle

<img width="731" alt="Screenshot 2023-09-20 at 10 41 34 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/959b197b-0c18-42d5-be51-5fbca2891abc">

#to run rqt_graph, open a new terminal and enter the command:
rqt_graph

<img width="990" alt="Screenshot 2023-09-21 at 11 28 32 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/3f2ae0d1-5c5b-4a7b-98cb-2daa87e978d1">

#This command will clear the turtlesim window of any lines your turtle has drawn.
ros2 service call /clear std_srvs/srv/Empty

<img width="979" alt="Screenshot 2023-09-21 at 11 34 39 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/4a880a58-d439-453e-8bcd-4e8815d1795a">

#To change /turtlesim’s background color:
ros2 param set /turtlesim background_r 150

<img width="988" alt="Screenshot 2023-09-21 at 11 47 58 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/4791f5bd-c316-4738-983b-9ab8f468e0db">

#To produce log messages for rqt_console to display, let’s have the turtle run into the wall. In a new terminal, enter the ros2 topic pub command (discussed in detail in the topics tutorial) below:
ros2 topic pub -r 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0,y: 0.0,z: 0.0}}"

<img width="1389" alt="Screenshot 2023-09-21 at 11 52 04 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/b44d0697-2e5c-4b4a-be92-1e00f16babf9">

#To run the launch file, which is written in Python, but you can also use XML and YAML to create launch files. You can see a comparison of these different ROS 2 launch formats in Using Python, XML, and YAML for ROS 2 Launch Files.
ros2 launch turtlesim multisim.launch.py

<img width="984" alt="Screenshot 2023-09-21 at 11 54 32 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/a0db0939-a05b-4556-9158-02ed72cba567">

#Now that these nodes are running, you can control them like any other ROS 2 nodes. For example, you can make the turtles drive in opposite directions by opening up two additional terminals and running the following commands:

#In the second terminal:
ros2 topic pub  /turtlesim1/turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"

#In the third terminal:
ros2 topic pub  /turtlesim2/turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: -1.8}}"

<img width="987" alt="Screenshot 2023-09-21 at 11 55 33 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/720bce27-135e-40c1-906e-890149e80537">

#To see the data that /turtle1/cmd_vel is publishing, run the command:
ros2 topic echo /turtle1/cmd_vel

#Nothing will show up at first because no data is being published by the teleop. Return to the terminal where you ran the teleop and select it so it’s active. Use the arrow keys to move the turtle around, and you will see data being published on the terminal running 

<img width="988" alt="Screenshot 2023-09-21 at 12 02 33 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/f17e142f-9d0e-4bd2-98ab-0650506587e7">


#The below link is the github shell file for the commands of Client libraries
https://github.com/ElyorS/Smart-Mobility-Engineering/blob/7a3515c9abab45528d37c9a9fca44868818f11d5/12204556_client_libraries.sh

#When colcon has completed building successfully, the output will be in the install directory. Before you can use any of the installed executables or libraries, you will need to add them to your path and library paths. colcon will have generated bash/bat files in the install directory to help set up the environment. These files will add all of the required elements to your path and library paths as well as provide any bash or shell commands exported by packages.

#With the environment sourced, we can run executables built by colcon. Let’s run a subscriber node from the examples:
ros2 run examples_rclcpp_minimal_subscriber subscriber_member_function

#In another terminal, let’s run a publisher node (don’t forget to source the setup script):
ros2 run examples_rclcpp_minimal_publisher publisher_member_function

<img width="770" alt="Screenshot 2023-09-24 at 1 06 34 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/2f900f8d-1884-4c02-9712-9d390d641093">

<img width="771" alt="Screenshot 2023-09-24 at 1 06 37 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/3aa449ee-812a-49ad-8678-634f09efef74">

#You can modify turtlesim in your overlay by editing the title bar on the turtlesim window. To do this, locate the turtle_frame.cpp file in ~/ros2_ws/src/ros_tutorials/turtlesim/src. Open turtle_frame.cpp with your preferred text editor. On line 52 you will see the function setWindowTitle("TurtleSim");. Change the value "TurtleSim" to "MyTurtleSim", and save the file. Return to the first terminal where you ran colcon build earlier and run it again. Return to the second terminal (where the overlay is sourced) and run turtlesim again:
ros2 run turtlesim turtlesim_node

#Even though your main ROS 2 environment was sourced in this terminal earlier, the overlay of your ros2_ws environment takes precedence over the contents of the underlay. To see that your underlay is still intact, open a brand new terminal and source only your ROS 2 installation. Run turtlesim again:
ros2 run turtlesim turtlesim_node

<img width="987" alt="Screenshot 2023-09-24 at 1 55 22 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/bbedf004-d17c-435e-8bf0-8b7856920f3d">

#From ros2_ws/src/my_package, open package.xml using your preferred text editor:
#Input your name and email on the maintainer line if it hasn’t been automatically populated for you. Then, edit the description line to summarize the package:
<description>Beginner client libraries tutorials practice package</description>

#Then, update the license line. You can read more about open source licenses here. Since this package is only for practice, it’s safe to use any license. We’ll use Apache License 2.0:
<license>Apache License 2.0</license>

<img width="992" alt="Screenshot 2023-09-24 at 2 59 51 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/d6ce8c15-5a22-4212-8eba-1cd2f0c8787f">
# The file can be downloaded 

#To create a simple publisher and subscruber in C++ and Python languages, the commands, which are mentioned in the shell file have to be used so that the neccesssary files will be downloaded once they are entered to the terminal. After that, As mentioned in the previous tutorial, make sure to fill in the <description>, <maintainer> and <license> tags:<description>Examples of minimal publisher/subscriber using rclpy</description> <maintainer email="you@email.com">Your Name</maintainer> <license>Apache License 2.0</license>, 
#After the lines above, add the following dependencies corresponding to your node’s import statements:<exec_depend>rclpy</exec_depend <exec_depend>std_msgs</exec_depend>, maintainer='YourName', maintainer_email='you@email.com', description='Examples of minimal publisher/subscriber using rclpy', license='Apache License 2.0', 

#Once everything is done, it is possible to run the program by the below command: 
ros2 run py_pubsub listener

<img width="992" alt="Screenshot 2023-09-24 at 2 59 51 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/a5b091a8-d31e-4ffa-a70d-376858e9d426">

<img width="988" alt="Screenshot 2023-09-24 at 3 37 58 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/343925fc-f9c4-46fa-ad56-7d283c84a4b3">




