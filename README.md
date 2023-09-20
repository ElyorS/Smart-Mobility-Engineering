# Smart-Mobility-Engineering
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


