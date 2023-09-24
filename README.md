#The below link is the shell file for the commands regarding CLI tools:
https://github.com/ElyorS/Smart-Mobility-Engineering/blob/7bc19b555c732307071df515ca237a78e47b871a/12204556_cli_tools.sh

                               #CLI TOOLS

#ROS 2 relies on the notion of combining workspaces using the shell environment. “Workspace” is a ROS term for the location on your system where you’re developing with ROS 2. The core ROS 2 workspace is called the underlay. Subsequent local workspaces are called overlays. When developing with ROS 2, you will typically have several workspaces active concurrently.
Combining workspaces makes developing against different versions of ROS 2, or against different sets of packages, easier. It also allows the installation of several ROS 2 distributions (or “distros”, e.g. Dashing and Eloquent) on the same computer and switching between them.
#Using turtlesim and rqt is a great way to learn the core concepts of ROS 2. This is accomplished by sourcing setup files every time you open a new shell, or by adding the source command to your shell startup script once. Without sourcing the setup files, you won’t be able to access ROS 2 commands, or find or use ROS 2 packages. In other words, you won’t be able to use ROS 2.

                         #USING TURTLESIM, ROS2, AND RQT. 
                         
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

                                #Understanding nodes

#A node is a fundamental ROS 2 element that serves a single, modular purpose in a robotics system.In this tutorial, you utilized nodes created in the turtlesim package by running the executables turtlesim_node and turtle_teleop_key.You learned how to use ros2 node list to discover active node names and ros2 node info to introspect a single node. These tools are vital to understanding the flow of data in a complex, real-world robot system.
#ros2 node list will show you the names of all running nodes
ros2 node list


#reassign the name of our /turtlesim node. In a new terminal, run the following command:

ros2 run turtlesim turtlesim_node --ros-args --remap __node:=my_turtle

<img width="1008" alt="Screenshot 2023-09-20 at 10 38 27 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/e77d4a92-47b8-4c5b-81b8-5497f4c2ead9">

#Now that you know the names of your nodes, you can access more information about them with:
ros2 node info /my_turtle

<img width="731" alt="Screenshot 2023-09-20 at 10 41 34 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/959b197b-0c18-42d5-be51-5fbca2891abc">

                                       #Understanding topics

#Nodes publish information over topics, which allows any number of other nodes to subscribe to and access that information. In this tutorial you examined the connections between several nodes over topics using rqt_graph and command line tools. You should now have a good idea of how data moves around a ROS 2 system.


#to run rqt_graph, open a new terminal and enter the command:
rqt_graph

<img width="990" alt="Screenshot 2023-09-21 at 11 28 32 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/3f2ae0d1-5c5b-4a7b-98cb-2daa87e978d1">

                                      #Understandig services
                                    
#Nodes can communicate using services in ROS 2. Unlike a topic - a one way communication pattern where a node publishes information that can be consumed by one or more subscribers - a service is a request/response pattern where a client makes a request to a node providing the service and the service processes the request and generates a response.#This command will clear the turtlesim window of any lines your turtle has drawn.You generally don’t want to use a service for continuous calls; topics or even actions would be better suited.

ros2 service call /clear std_srvs/srv/Empty

<img width="979" alt="Screenshot 2023-09-21 at 11 34 39 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/4a880a58-d439-453e-8bcd-4e8815d1795a">

                                  #Understanding parameters
                                
#Nodes have parameters to define their default configuration values. You can get and set parameter values from the command line. You can also save the parameter settings to a file to reload them in a future session.

#To change /turtlesim’s background color:
ros2 param set /turtlesim background_r 150

<img width="988" alt="Screenshot 2023-09-21 at 11 47 58 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/4791f5bd-c316-4738-983b-9ab8f468e0db">


                          #Using rqt_console to view logs    

#rqt_console can be very helpful if you need to closely examine the log messages from your system. You might want to examine log messages for any number of reasons, usually to find out where something went wrong and the series of events leading up to that.

#To produce log messages for rqt_console to display, let’s have the turtle run into the wall. In a new terminal, enter the ros2 topic pub command (discussed in detail in the topics tutorial) below:
ros2 topic pub -r 1 /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0,y: 0.0,z: 0.0}}"

<img width="1389" alt="Screenshot 2023-09-21 at 11 52 04 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/b44d0697-2e5c-4b4a-be92-1e00f16babf9">

#To run the launch file, which is written in Python, but you can also use XML and YAML to create launch files. You can see a comparison of these different ROS 2 launch formats in Using Python, XML, and YAML for ROS 2 Launch Files.
ros2 launch turtlesim multisim.launch.py

<img width="984" alt="Screenshot 2023-09-21 at 11 54 32 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/a0db0939-a05b-4556-9158-02ed72cba567">

                                   #Launching nodes

#The significance of what you’ve done so far is that you’ve run two turtlesim nodes with one command. Once you learn to write your own launch files, you’ll be able to run multiple nodes - and set up their configuration - in a similar way, with the ros2 launch command.

#Now that these nodes are running, you can control them like any other ROS 2 nodes. For example, you can make the turtles drive in opposite directions by opening up two additional terminals and running the following commands:

#In the second terminal:
ros2 topic pub  /turtlesim1/turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: 1.8}}"

#In the third terminal:
ros2 topic pub  /turtlesim2/turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 2.0, y: 0.0, z: 0.0}, angular: {x: 0.0, y: 0.0, z: -1.8}}"

<img width="987" alt="Screenshot 2023-09-21 at 11 55 33 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/720bce27-135e-40c1-906e-890149e80537">

                              #Recording and playing back data
                              
#You can record data passed on topics in your ROS 2 system using the ros2 bag command. Whether you’re sharing your work with others or introspecting your own experiments, it’s a great tool to know about.

#To see the data that /turtle1/cmd_vel is publishing, run the command:
ros2 topic echo /turtle1/cmd_vel

#Nothing will show up at first because no data is being published by the teleop. Return to the terminal where you ran the teleop and select it so it’s active. Use the arrow keys to move the turtle around, and you will see data being published on the terminal running 

<img width="988" alt="Screenshot 2023-09-21 at 12 02 33 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/f17e142f-9d0e-4bd2-98ab-0650506587e7">

                              #CLIENT LIBRARIES
#Client-Library is an applications programming interface ( API ) for use in writing client applications. Client-Library provides generic building blocks for constructing distributed client applications, including non-database applications.

                                       
                        
#The below link is the github shell file for the commands of Client libraries
https://github.com/ElyorS/Smart-Mobility-Engineering/blob/7a3515c9abab45528d37c9a9fca44868818f11d5/12204556_client_libraries.sh

                        #Using colon to build packages
                        
#When colcon has completed building successfully, the output will be in the install directory. Before you can use any of the installed executables or libraries, you will need to add them to your path and library paths. colcon will have generated bash/bat files in the install directory to help set up the environment. These files will add all of the required elements to your path and library paths as well as provide any bash or shell commands exported by packages.

#With the environment sourced, we can run executables built by colcon. Let’s run a subscriber node from the examples:
ros2 run examples_rclcpp_minimal_subscriber subscriber_member_function

#In another terminal, let’s run a publisher node (don’t forget to source the setup script):
ros2 run examples_rclcpp_minimal_publisher publisher_member_function

<img width="770" alt="Screenshot 2023-09-24 at 1 06 34 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/2f900f8d-1884-4c02-9712-9d390d641093">

<img width="771" alt="Screenshot 2023-09-24 at 1 06 37 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/3aa449ee-812a-49ad-8678-634f09efef74">

                                   #Creating a workspace
                                   
#In this tutorial, you sourced your main ROS 2 distro install as your underlay, and created an overlay by cloning and building packages in a new workspace. The overlay gets prepended to the path, and takes precedence over the underlay, as you saw with your modified turtlesim.Using overlays is recommended for working on a small number of packages, so you don’t have to put everything in the same workspace and rebuild a huge workspace on every iteration.

#You can modify turtlesim in your overlay by editing the title bar on the turtlesim window. To do this, locate the turtle_frame.cpp file in ~/ros2_ws/src/ros_tutorials/turtlesim/src. Open turtle_frame.cpp with your preferred text editor. On line 52 you will see the function setWindowTitle("TurtleSim");. Change the value "TurtleSim" to "MyTurtleSim", and save the file. Return to the first terminal where you ran colcon build earlier and run it again. Return to the second terminal (where the overlay is sourced) and run turtlesim again:
ros2 run turtlesim turtlesim_node

             
#Even though your main ROS 2 environment was sourced in this terminal earlier, the overlay of your ros2_ws environment takes precedence over the contents of the underlay. To see that your underlay is still intact, open a brand new terminal and source only your ROS 2 installation. Run turtlesim again:
ros2 run turtlesim turtlesim_node

<img width="987" alt="Screenshot 2023-09-24 at 1 55 22 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/bbedf004-d17c-435e-8bf0-8b7856920f3d">

                   #Writing a simple publisher and subscriber using C++ and Pyhton

#You create two nodes to publish and subscribe to data over a topic. Before compiling and running them, you added their dependencies and executables to the package configuration files.

#From ros2_ws/src/my_package, open package.xml using your preferred text editor:
#Input your name and email on the maintainer line if it hasn’t been automatically populated for you. Then, edit the description line to summarize the package:
<description>Beginner client libraries tutorials practice package</description>

#Then, update the license line. You can read more about open source licenses here. Since this package is only for practice, it’s safe to use any license. We’ll use Apache License 2.0:
<license>Apache License 2.0</license>

<img width="992" alt="Screenshot 2023-09-24 at 2 59 51 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/d6ce8c15-5a22-4212-8eba-1cd2f0c8787f">

                                     

#To create a simple publisher and subscruber in C++ and Python languages, the commands, which are mentioned in the shell file have to be used so that the neccesssary files will be downloaded once they are entered to the terminal. After that, As mentioned in the previous tutorial, make sure to fill in the <description>, <maintainer> and <license> tags:<description>Examples of minimal publisher/subscriber using rclpy</description> <maintainer email="you@email.com">Your Name</maintainer> <license>Apache License 2.0</license>, 
#After the lines above, add the following dependencies corresponding to your node’s import statements:<exec_depend>rclpy</exec_depend <exec_depend>std_msgs</exec_depend>, maintainer='YourName', maintainer_email='you@email.com', description='Examples of minimal publisher/subscriber using rclpy', license='Apache License 2.0', 

#Once everything is done, it is possible to run the program by the below command: 
ros2 run py_pubsub listener

<img width="992" alt="Screenshot 2023-09-24 at 2 59 51 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/a5b091a8-d31e-4ffa-a70d-376858e9d426">

<img width="988" alt="Screenshot 2023-09-24 at 3 37 58 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/343925fc-f9c4-46fa-ad56-7d283c84a4b3">

                #Wriiting a simple service and client program using C++ and Python

#You create two nodes to request and respond to data over a service. You added their dependencies and executables to the package configuration files so that you could build and run them, and see a service/client system at work.

#In order to create a simple service and client programm using c++ and python, at first the user has to follow the command from the shell dile. Afterwards, has to download the needed files by entering the commands to the terminal, after doing couple modifications in the program. in name, mail and license part, can run the code by entering command. 

#During this activity, user will learn how to create two nodes to request and respond to data over a service. Adding their dependencies and executables to the package configuration files so that you could build and run them, allowing to see a service/client system at work.

<img width="986" alt="Screenshot 2023-09-24 at 7 39 24 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/b4cf25f2-12d2-4808-bda3-db8f5e8f1cce">

<img width="884" alt="Screenshot 2023-09-24 at 8 09 22 AM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/e9104391-3fb5-4c16-bfa8-2871f306371f">


# Learning how to create custom interfaces in their own package and how to utilize those interfaces in other packages.

#interfaces rely on rosidl_default_generators for generating language-specific code, you need to declare a build tool dependency on it. rosidl_default_runtime is a runtime or execution-stage dependency, needed to be able to use the interfaces later. The rosidl_interface_packages is the name of the dependency group that your package, tutorial_interfaces, should be associated with, declared using the <member_of_group> tag.

                       #Creating custom ms and srv files


#In this tutorial, you will learn how to create custom interfaces in their own package and how to utilize those interfaces in other packages.


#For this tutorial you will be creating custom .msg and .srv files in their own package, and then utilizing them in a separate package. Both packages should be in the same workspace.


                       #Implemeting custom interfaces

#In this tutorial, you will try out different field types for defining interfaces, then built an interface in the same package where it’s being used.

#Recall that interfaces can currently only be defined in CMake packages. It is possible, however, to have Python libraries and nodes in CMake packages (using ament_cmake_python), so you could define interfaces and Python nodes together in one package. We’ll use a CMake package and C++ nodes here for the sake of simplicity.

#This tutorial will focus on the msg interface type, but the steps here are applicable to all interface types.

<img width="1022" alt="Screenshot 2023-09-24 at 7 01 29 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/43163d54-1f33-48b5-8996-21bedbf06ab9">

                       #Using paramteres in a class using C++ and Python

#You will create a node with a custom parameter that can be set either from a launch file or the command line. You added the dependencies, executables, and a launch file to the package configuration files so that you could build and run them, and see the parameter in action.


#When making your own nodes you will sometimes need to add parameters that can be set from the launch file.

#This tutorial will show you how to create those parameters in a Python class, and how to set them in a launch file.

<img width="1434" alt="Screenshot 2023-09-24 at 7 04 47 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/448bb385-e835-49fe-8e6b-de35e0e6669f">

<img width="1447" alt="Screenshot 2023-09-24 at 7 15 08 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/7f2622ee-290e-4555-aef7-af1470ea06be">


                          #Using a ROS2doctor to identify the issues

#ros2doctor will inform you of problems in your ROS 2 setup and running systems. You can get a deeper look at information behind those warnings by using the --report argument. Keep in mind, ros2doctor is not a debug tool; it won’t help with errors in your code or on the implementation side of your system.

#When your ROS 2 setup is not running as expected, you can check its settings with the ros2doctor tool. ros2doctor checks all aspects of ROS 2, including platform, version, network, environment, running systems and more, and warns you about possible errors and reasons for issues.

<img width="1045" alt="Screenshot 2023-09-24 at 7 28 11 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/74ee5bf1-c352-4b63-ace9-98fcc200c25d">


                       #Creating and Uisng plugins C++

#pluginlib is a C++ library for loading and unloading plugins from within a ROS package. Plugins are dynamically loadable classes that are loaded from a runtime library (i.e. shared object, dynamically linked library). With pluginlib, you do not have to explicitly link your application against the library containing the classes – instead pluginlib can open a library containing exported classes at any point without the application having any prior awareness of the library or the header file containing the class definition. Plugins are useful for extending/modifying application behavior without needing the application source code.


<img width="1444" alt="Screenshot 2023-09-24 at 8 08 45 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/c911a732-44f6-4df4-8884-a854954545cd">

#When the prgoram is runned with the cmmand:

#It should print:
#Triangle area: 43.30
#Square area: 100.00


#There are a number of ways to instantiate an instance of the class. In this example, we’re using shared pointers. We just need to call createSharedInstance with the fully-qualified type of the plugin class, in this case, polygon_plugins::Square.

#Important note: the polygon_base package in which this node is defined does NOT depend on the polygon_plugins class. The plugins will be loaded dynamically without any dependency needing to be declared. Furthermore, we’re instantiating the classes with hardcoded plugin names, but you can also do so dynamically with parameters, etc.
