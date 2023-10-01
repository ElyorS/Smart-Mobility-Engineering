Saidmurodov Elyor (12204556)

This file explains all the steps for installing the ROS2 Intermediate tutorial

                                   Managing Dependencies with rosdep


rosdep is a dependency management utility that can work with packages and external libraries. It is a command-line utility for identifying and installing dependencies to build or install a package. rosdep is not a package manager in its own right; it is a meta-package manager that uses its own knowledge of the system and the dependencies to find the appropriate package to install on a particular platform. The actual installation is done using the system package manager (e.g. apt on Debian/Ubuntu, dnf on Fedora/RHEL, etc).

The package.xml is the file in your software where rosdep finds the set of dependencies. It is important that the list of dependencies in the package.xml is complete and correct, which allows all of the tooling to determine the packages dependencies. Missing or incorrect dependencies can lead to users not being able to use your package, to packages in a workspace being built out-of-order, and to packages not being able to be released.
The dependencies in the package.xml file are generally referred to as “rosdep keys”. These dependencies are manually populated in the package.xml file by the package’s creators and should be an exhaustive list of any non-builtin libraries and packages it requires.

rosdep will check for package.xml files in its path or for a specific package and find the rosdep keys stored within. These keys are then cross-referenced against a central index to find the appropriate ROS package or software library in various package managers. Finally, once the packages are found, they are installed and ready to go!

<img width="902" alt="Screenshot 2023-10-01 at 2 48 56 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/2b64d38f-1547-44a2-baa9-19583adb4d4b">


                                  Creating an action 

You learned about actions previously in the Understanding actions tutorial. Like the other communication types and their respective interfaces (topics/msg and services/srv), you can also custom-define actions in your packages. This tutorial shows you how to define and build an action that you can use with the action server and action client you will write in the next tutorial.

In this tutorial, you learned the structure of an action definition. You also learned how to correctly build a new action interface using CMakeLists.txt and package.xml, and how to verify a successful build.

<img width="990" alt="Screenshot 2023-10-01 at 2 20 40 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/66177f66-3b2e-4095-8b28-20ebd4a6b1cc">

<img width="1064" alt="Screenshot 2023-10-01 at 3 25 13 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/9f6be4ef-53f8-4a0f-9249-0b8c225fe3e0">



                                Writing an action server and client (C++)

Actions are a form of asynchronous communication in ROS. Action clients send goal requests to action servers. Action servers send goal feedback and results to action clients.

You will need the action_tutorials_interfaces package and the Fibonacci.action interface defined in the previous tutorial, Creating an action.

In this tutorial, you put together a C++ action server and action client line by line, and configured them to exchange goals, feedback, and results.

<img width="1195" alt="Screenshot 2023-10-01 at 3 29 19 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/b0032079-c116-45fd-9fa9-4e88dec4a29e">

<img width="1214" alt="Screenshot 2023-10-01 at 3 29 39 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/d68a019b-d26e-478c-8b84-21d1dad54ff6">



                                Writing an action server and client (Python)

Actions are a form of asynchronous communication in ROS 2. Action clients send goal requests to action servers. Action servers send goal feedback and results to action clients. You will need the action_tutorials_interfaces package and the Fibonacci.action interface defined in the previous tutorial, Creating an action.

In this tutorial, you put together a Python action server and action client line by line, and configured them to exchange goals, feedback, and results.



                             Composing multiple nodes in a single process

f you want to export a composable node as a shared library from a package and use that node in another package that does link-time composition, add code to the CMake file which imports the actual targets in downstream packages.

In ROS 2, components allow for more efficient use of system resources and provide a powerful feature that enables you to create reusable functionality that is not tied to a specific node.

One advantage of using components is that they allow you to create non-node derived functionality as standalone executables or shared libraries that can be loaded into the ROS system as needed.

To create a component that is not derived from a node, follow these guidelines:

Implement a constructor that takes const rclcpp::NodeOptions& as its argument.
Implement the get_node_base_interface() method, which should return a NodeBaseInterface::SharedPtr. You can use the get_node_base_interface() method of a node that you create in your constructor to provide this interface.

<img width="748" alt="Screenshot 2023-10-01 at 3 40 21 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/11e0df7b-a624-4208-a668-f3dea3892f33">

<img width="736" alt="Screenshot 2023-10-01 at 3 40 42 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/ab24319b-112b-4794-85bd-a27ddc527250">

<img width="739" alt="Screenshot 2023-10-01 at 3 43 13 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/67e4a360-4731-461c-b369-33149ccd7e20">

<img width="726" alt="Screenshot 2023-10-01 at 3 43 28 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/c17b0fa2-0527-4488-9c68-9917a0d145c4">


                                 Monitoring for parameter changes (C++)

Often a node needs to respond to changes to its own parameters or another node’s parameters. The ParameterEventHandler class makes it easy to listen for parameter changes so that your code can respond to them. This tutorial will show you how to use the C++ version of the ParameterEventHandler class to monitor for changes to a node’s own parameters as well as changes to another node’s parameters.

You created a node with a parameter and used the ParameterEventHandler class to set a callback to monitor changes to that parameter. You also used the same class to monitor changes to a remote node. The ParameterEventHandler is a convenient way to monitor for parameter changes so that you can then respond to the updated values.


<img width="1385" alt="Screenshot 2023-10-01 at 3 51 12 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/17baea0f-25d7-423a-99db-ad9e93e1958d">

                                 ---------------------------LAUNCH----------------------------


                                 Creating a Launch file
                                 
The launch system in ROS 2 is responsible for helping the user describe the configuration of their system and then execute it as described. The configuration of the system includes what programs to run, where to run them, what arguments to pass them, and ROS-specific conventions which make it easy to reuse components throughout the system by giving them each a different configuration. It is also responsible for monitoring the state of the processes launched, and reporting and/or reacting to changes in the state of those processes.

Launch files simplify running complex systems with many nodes and specific configuration details. You can create launch files using Python, XML, or YAML, and run them using the ros2 launch command.

<img width="996" alt="Screenshot 2023-10-01 at 4 03 17 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/9e016c42-fe76-4573-b2f8-c4b6750a0719">

<img width="1017" alt="Screenshot 2023-10-01 at 4 04 48 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/e75f2c99-aec2-4a86-a1ff-be3a91d7346b">

<img width="1266" alt="Screenshot 2023-10-01 at 4 05 27 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/53f4be81-3914-4b67-aa77-7cd41cc1b8ed">

                           Integrating launch files into ROS 2 packages
                           
In the previous tutorial, we saw how to write a standalone launch file. This tutorial will show how to add a launch file to an existing package, and the conventions typically used.

The launch documentation provides more details on concepts that are also used in launch_ros


                         Using substitutions

Launch files are used to start nodes, services and execute processes. This set of actions may have arguments, which affect their behavior. Substitutions can be used in arguments to provide more flexibility when describing reusable launch files. Substitutions are variables that are only evaluated during execution of the launch description and can be used to acquire specific information like a launch configuration, an environment variable, or to evaluate an arbitrary Python expression.

In this tutorial, you learned about using substitutions in launch files. You learned about their possibilities and capabilities to create reusable launch files.

You can now learn more about using event handlers in launch files which are used to define a complex set of rules which can be used to dynamically modify the launch file.

<img width="955" alt="Screenshot 2023-10-01 at 4 12 53 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/45686bee-f2d8-4d3b-91f5-e872fb641cc6">

                                    Using event handlers

Launch in ROS 2 is a system that executes and manages user-defined processes. It is responsible for monitoring the state of processes it launched, as well as reporting and reacting to changes in the state of those processes. These changes are called events and can be handled by registering an event handler with the launch system. Event handlers can be registered for specific events and can be useful for monitoring the state of processes. Additionally, they can be used to define a complex set of rules which can be used to dynamically modify the launch file.

In this tutorial, you learned about using event handlers in launch files. You learned about their syntax and usage examples to define a complex set of rules to dynamically modify launch files.
<img width="1429" alt="Screenshot 2023-10-01 at 4 16 02 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/1b904083-0325-42c0-ac10-504fb7e0b4d0">

This will do the following:

Start a turtlesim node with a blue background
Spawn the second turtle
Change the color to purple
Change the color to pink after two seconds if the provided background_r argument is 200 and use_provided_red argument is True
Shutdown the launch file when the turtlesim window is closed
Additionally, it will log messages to the console when:

The turtlesim node starts
The spawn action is executed
The change_background_r action is executed
The change_background_r_conditioned action is executed
The turtlesim node exits
The launch process is asked to shutdown.

            Managng large projects

This tutorial describes some tips for writing launch files for large projects. The focus is on how to structure launch files so they may be reused as much as possible in different situations. Additionally, it covers usage examples of different ROS 2 launch tools, like parameters, YAML files, remappings, namespaces, default arguments, and RViz configs.

Large applications on a robot typically involve several interconnected nodes, each of which can have many parameters. Simulation of multiple turtles in the turtle simulator can serve as a good example. The turtle simulation consists of multiple turtle nodes, the world configuration, and the TF broadcaster and listener nodes. Between all of the nodes, there are a large number of ROS parameters that affect the behavior and appearance of these nodes. ROS 2 launch files allow us to start all nodes and set corresponding parameters in one place. By the end of a tutorial, you will build the launch_turtlesim.launch.py launch file in the launch_tutorial package. This launch file will bring up different nodes responsible for the simulation of two turtlesim simulations, starting TF broadcasters and listener, loading parameters, and launching an RViz configuration. In this tutorial, we’ll go over this launch file and all related features used.

In this tutorial, you learned about various tips and practices of managing large projects using ROS 2 launch files.
<img width="670" alt="Screenshot 2023-10-01 at 4 25 27 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/532964f7-39dc-4538-82a8-63e8a427d291">

                                     ---------------------tf2-----------------------------

                                     Introducing tf2

Run a turtlesim demo and see some of the power of tf2 in a multi-robot example using turtlesim
Now that we’ve installed the turtle_tf2_py tutorial package let’s run the demo. First, open a new terminal and source your ROS 2 installation so that ros2 commands will work. Then run the following command:

Here we can see three frames that are broadcasted by tf2: world, turtle1, and turtle2. The world here is the parent of the turtle1 and turtle2 frames. view_frames also report some diagnostic information about when the oldest and most recent frame transforms were received and how fast the tf2 frame is published to tf2 for debugging purposes.

<img width="1020" alt="Screenshot 2023-10-01 at 4 30 34 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/13e989cc-5acf-4931-9b29-b2b84b17ccdb">
<img width="983" alt="Screenshot 2023-10-01 at 4 31 26 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/cbc7962c-911c-4285-b53d-5c7d11708ea2">
<img width="675" alt="Screenshot 2023-10-01 at 4 32 09 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/f835504f-a895-4aa7-aae4-3ec1495ad444">

                         Writing a static broadcaster (Python) and (C++)

Publishing static transforms is useful to define the relationship between a robot base and its sensors or non-moving parts. For example, it is easiest to reason about laser scan measurements in a frame at the center of the laser scanner.

This is a standalone tutorial covering the basics of static transforms, which consists of two parts. In the first part we will write code to publish static transforms to tf2. In the second part we will explain how to use the commandline static_transform_publisher executable tool in tf2_ros.

In the next two tutorials we will write the code to reproduce the demo from the Introduction to tf2 tutorial. After that, the following tutorials focus on extending the demo with more advanced tf2 features.

In this tutorial you learned how static transforms are useful to define static relationships between frames, like mystaticturtle in relation to the world frame. In addition, you learned how static transforms can be useful for understanding sensor data, such as from laser scanners, by relating the data to a common coordinate frame. Finally, you wrote your own node to publish static transforms to tf2 and learned how to publish required static transformations using static_transform_publisher executable and launch files.

                      Writing a broadcaster (Python) and (C++)

In the next two tutorials we will write the code to reproduce the demo from the Introduction to tf2 tutorial. After that, following tutorials focus on extending the demo with more advanced tf2 features, including the usage of timeouts in transformation lookups and time travel.

This tutorial assumes you have a working knowledge of ROS 2 and you have completed the Introduction to tf2 tutorial. In previous tutorials, you learned how to create a workspace and create a package. You also have created the learning_tf2_py package, which is where we will continue working from.

In this tutorial you learned how to broadcast the pose of the robot (position and orientation of the turtle) to tf2 and how to use the tf2_echo tool. To actually use the transforms broadcasted to tf2, you should move on to the next tutorial about creating a tf2 listener.

                        Writing a listener (Python) and (C++)

This tutorial assumes you have completed the tf2 broadcaster tutorial (Python). In the previous tutorial, we created a learning_tf2_py package, which is where we will continue working from.

To understand how the service behind spawning turtle works, please refer to writing a simple service and client (Python) tutorial.

Now, let’s take a look at the code that is relevant to get access to frame transformations. The tf2_ros package provides an implementation of a TransformListener to help make the task of receiving transforms easier.

this tutorial you learned how to use tf2 to get access to frame transformations. You also have finished writing your own turtlesim demo that you first tried in Introduction to tf2 tutorial.

                       Adding a frame (Python) and (C++)

In previous tutorials, we recreated the turtle demo by writing a tf2 broadcaster and a tf2 listener. This tutorial will teach you how to add extra fixed and dynamic frames to the transformation tree. In fact, adding a frame in tf2 is very similar to creating the tf2 broadcaster, but this example will show you some additional features of tf2.

For many tasks related to transformations, it is easier to think inside a local frame. For example, it is easiest to reason about laser scan measurements in a frame at the center of the laser scanner. tf2 allows you to define a local frame for each sensor, link, or joint in your system. When transforming from one frame to another, tf2 will take care of all the hidden intermediate frame transformations that are introduced.

tf2 builds up a tree structure of frames and, thus, does not allow a closed loop in the frame structure. This means that a frame only has one single parent, but it can have multiple children. Currently, our tf2 tree contains three frames: world, turtle1 and turtle2. The two turtle frames are children of the world frame. If we want to add a new frame to tf2, one of the three existing frames needs to be the parent frame, and the new one will become its child frame.

In this tutorial, you learned about the tf2 transformation tree, its structure, and its features. You also learned that it is easiest to think inside a local frame, and learned to add extra fixed and dynamic frames for that local frame.

                   Using time (Python) and (C++)

In previous tutorials, we recreated the turtle demo by writing a tf2 broadcaster and a tf2 listener. We also learned how to add a new frame to the transformation tree. Now we will learn more about the timeout argument which makes the lookup_transform wait for the specified transform for up to the specified duration before throwing an exception. This tool can be useful to listen for transforms that are published at varying rates or those incoming source with unreliable networking and non negligible latency. This tutorial will teach you how use the timeout in lookup_transform function to wait for a transform to be available on the tf2 tree.

You should notice that lookup_transform() will actually block until the transform between the two turtles becomes available (this will usually take a few milli-seconds). Once the timeout has been reached (one second in this case), an exception will be raised only if the transform is still not available.

In this tutorial you learned more about the lookup_transform function and its timeout features. You also learned how to catch and handle additional exceptions that can be thrown by tf2.
