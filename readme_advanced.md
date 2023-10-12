                      ROS2 Advanced section readme file
Enabling topic statistics (C++)
Using Fast DDS Discovery Server as discovery protocol [community-contributed]
Implementing a custom memory allocator
Unlocking the potential of Fast DDS middleware [community-contributed]
Recording a bag from a node (C++)
Recording a bag from a node (Python)
Reading from a bag file (C++)
Simulators
Security

                           Enabling topic statistics (C++)

This is a short tutorial on how to enable topic statistics in ROS 2 and view the published statistics output using command line tools (ros2topic).

ROS 2 provides the integrated measurement of statistics for messages received by any subscription, called Topic Statistics. With Topic Statistics enabled for your subscription, you can characterize the performance of your system or use the data to help diagnose any present issues.

For more details please see the Topic Statistics Concepts Page.

You created a subscriber node with topic statistics enabled, which published statistics data from the C++’s publisher node. You were able to compile and run this node. While running, you were able to observe the statistics data.

<img width="1389" alt="Screenshot 2023-10-12 at 4 46 43 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/0baf6dff-dca7-4096-8947-f0a970aa368f">

<img width="1331" alt="Screenshot 2023-10-12 at 4 47 40 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/600c383c-23c2-4184-8dc4-14cd49a93028">



                            Using Fast DDS Discovery Server as discovery protocol [community-contributed]

Starting from ROS 2 Eloquent Elusor, the Fast DDS Discovery Server protocol is a feature that offers a centralized dynamic discovery mechanism, as opposed to the distributed mechanism used in DDS by default. This tutorial explains how to run some ROS 2 examples using the Fast DDS Discovery Server feature as discovery communication.

The Fast DDS Discovery Server provides a Client-Server Architecture that allows nodes to connect with each other using an intermediate server. Each node functions as a discovery client, sharing its info with one or more discovery servers and receiving discovery information from it. This reduces discovery-related network traffic and it does not require multicasting capabilities.

Communication with discovery servers can be split to create virtual partitions in the discovery information. This means that two endpoints will only know about each other if there is a shared discovery server or a network of discovery servers between them. We are going to execute an example with two independent servers. The following figure shows the architecture.

The new Fast DDS Discovery Server v2 is available since Fast DDS v2.0.2, replacing the old discovery server. In this new version, those nodes that do not share topics will automatically not discover each other, saving the whole discovery data required to connect them and their endpoints. The experiment above does not show this case, but even so the massive reduction in traffic can be appreciated due to the hidden infrastructure topics of ROS 2 nodes.

                                 Implementing a custom memory allocator

Suppose you want to write real-time safe code, and you’ve heard about the many dangers of calling “new” during the real-time critical section, because the default heap allocator on most platforms is nondeterministic.

By default, many C++ standard library structures will implicitly allocate memory as they grow, such as std::vector. However, these data structures also accept an “Allocator” template argument. If you specify a custom allocator to one of these data structures, it will use that allocator for you instead of the system allocator to grow or shrink the data structure. Your custom allocator could have a pool of memory preallocated on the stack, which might be better suited to real-time applications.

In the ROS 2 C++ client library (rclcpp), we are following a similar philosophy to the C++ standard library. Publishers, subscribers, and the Executor accept an Allocator template parameter that controls allocations made by that entity during execution.

The IntraProcessManager is a class that is usually hidden from the user, but in order to pass a custom allocator to it we need to expose it by getting it from the rclcpp Context. The IntraProcessManager makes use of several standard library structures, so without a custom allocator it will call the default new.


                         Unlocking the potential of Fast DDS middleware [community-contributed]

The interface between the ROS 2 stack and Fast DDS is provided by the ROS 2 middleware implementation rmw_fastrtps. This implementation is available in all ROS 2 distributions, both from binaries and from sources.

ROS 2 RMW only allows for the configuration of certain middleware QoS (see ROS 2 QoS policies). However, rmw_fastrtps offers extended configuration capabilities to take full advantage of the features in Fast DDS. This tutorial will guide you through a series of examples explaining how to use XML files to unlock this extended configuration.

This tutorial assumes that you know how to create a package. It also assumes you know how to write a simple publisher and subscriber and a simple service and client. Although the examples are implemented in C++, the same concepts apply to Python packages.

Although we have created a node with two publishers with different configuration, it is not easy to check that they are behaving differently. Now that the basics of XML profiles have been covered, let us use them to configure something which has some visual effect on the nodes. Specifically, a maximum number of matching subscribers on one of the publishers and a partition definition on the other will be set. Note that these are only very simple examples among all the configuration attributes that can be tuned on rmw_fastrtps through XML files. Please refer to *Fast DDS* documentation to see the whole list of attributes that can be configured through XML files.
<img width="1434" alt="Screenshot 2023-10-12 at 5 00 23 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/83b39cba-64fd-4562-95bc-1e64194cb3ab">

<img width="884" alt="Screenshot 2023-10-12 at 5 10 14 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/edff9f4b-72fd-42e6-9e91-ec4f2432d7fd">


                                        
                          Recording a bag from a node (C++)

Rosbag2 doesn’t just provide the ros2 bag command line tool. It also provides a C++ API for reading from and writing to a bag from your own source code. This allows you to subscribe to a topic and save the received data to a bag at the same time as performing any other processing of your choice on that data.

Any data can be recorded into a bag, not just data received over a topic. A common use case for writing to a bag from your own node is to generate and store synthetic data. In this section you will learn how to write a node that generates some data and stores it in a bag. We will demonstrate two approaches for doing this. The first uses a node with a timer; this is the approach that you would use if your data generation is external to the node, such as reading data directly from hardware (e.g. a camera). The second approach does not use a node; this is the approach you can use when you do not need to use any functionality from the ROS infrastructure.

You created a node that records data it receives on a topic into a bag. You tested recording a bag using the node, and verified the data was recorded by playing back the bag. You then went on to create a node and an executable to generate synthetic data and store it in a bag.

<img width="1179" alt="Screenshot 2023-10-12 at 5 15 15 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/a498c6f6-79c2-4acf-aed9-d7c8307d946c">

<img width="1014" alt="Screenshot 2023-10-12 at 5 18 34 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/546978d6-61a5-4464-978e-68bbc074b39e">

<img width="1420" alt="Screenshot 2023-10-12 at 5 20 33 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/6166b9f1-8785-48bd-909d-60d1b74f1a71">



                      Recording a bag from a node (Python)

rosbag2 doesn’t just provide the ros2 bag command line tool. It also provides a Python API for reading from and writing to a bag from your own source code. This allows you to subscribe to a topic and save the received data to a bag at the same time as performing any other processing of your choice on that data. You may do this, for example, to save data from a topic and the result of processing that data without needing to send the processed data over a topic just to record it. Because any data can be recorded in a bag, it is also possible to save data generated by another source than a topic, such as synthetic data for training sets. This is useful, for example, for quickly generating a bag that contains a large number of samples spread over a long playback time.

You should have the rosbag2 packages installed as part of your regular ROS 2 setup.

If you’ve installed from Debian packages on Linux, it may be installed by default. If it is not, you can install it using this command.

You created a node that records data it receives on a topic into a bag. You tested recording a bag using the node, and verified the data was recorded by playing back the bag. This approach can be used to record a bag with additional data than it received over a topic, for example with results obtained from processing the received data. You then went on to create a node and an executable to generate synthetic data and store it in a bag. The latter approaches are useful especially for generating synthetic data that can be used, for example, as training sets.

<img width="1179" alt="Screenshot 2023-10-12 at 5 15 15 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/eb123b5d-e1b6-41fa-bdce-f0adda0c83ad">
<img width="1420" alt="Screenshot 2023-10-12 at 5 20 33 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/28bfd62f-e2d8-4141-821f-2445bfbcf63b">



                     Reading from a bag file (C++)

rosbag2 doesn’t just provide the ros2 bag command line tool. It also provides a C++ API for reading from and writing to a bag from your own source code. This allows you to read the contents from a bag without having to play the bag, which can sometimes be useful.

You should have the rosbag2 packages installed as part of your regular ROS 2 setup.

If you’ve installed from Debian packages on Linux, it may be installed by default. If it is not, you can install it using this command.

You created a C++ executable that reads data from a bag. You then compiled and ran the executable which printed some information from the bag to the console.

<img width="1162" alt="Screenshot 2023-10-12 at 5 30 57 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/10c9dae1-3b44-4090-9658-5d8fddb6548e">

<img width="885" alt="Screenshot 2023-10-12 at 5 25 29 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/a5286505-09ce-458f-92d9-de1d7a23011e">

                   Installation (Ubuntu)

The webots_ros2 package provides an interface between ROS 2 and Webots. It includes several sub-packages, including webots_ros2_driver, which allows you to start Webots and communicate with it. This interface is used in most of the following tutorials, so it is required to install it beforehand. Other sub-packages are mainly examples that show multiple possible implementations using the interface. In this tutorial, you are going to install the package and learn how to run one of these examples.

It is recommended to understand basic ROS principles covered in the beginner Tutorials. In particular, Creating a workspace and Creating a package are useful prerequisites.

The Webots software should be installed in order to use the webots_ros2 interface. You can follow the installation procedure or build it from sources.

Alternatively, you can also let webots_ros2 download and install Webots automatically. This option appears when you launch an example of the package and no Webots installation is found.

<img width="736" alt="Screenshot 2023-10-12 at 5 44 24 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/4b7ffaf9-078c-4f31-88e0-1aa50c639be9">

<img width="727" alt="Screenshot 2023-10-12 at 5 46 20 PM" src="https://github.com/ElyorS/Smart-Mobility-Engineering/assets/115398604/713040eb-a367-475d-907a-3f425e4cb808">

                  Installation (Windows)

The webots_ros2 package provides an interface between ROS 2 and Webots. It includes several sub-packages, including webots_ros2_driver, which allows ROS nodes to communicate with Webots. Other sub-packages are mainly examples that show multiple possible implementations using the interface. In this tutorial, you are going to install the package and learn how to run one of these examples.

It is recommended to understand basic ROS principles covered in the beginner Tutorials. In particular, Creating a workspace and Creating a package are useful prerequisites.

Webots is a prerequisite to use the webots_ros2 package. You can follow the installation procedure or build it from sources.

Alternatively, you can also let webots_ros2 download Webots automatically. This option appears when you launch an example of the package and no Webots installation is found.

                Installation (macOS)

The webots_ros2 package provides an interface between ROS 2 and Webots. It includes several sub-packages, including webots_ros2_driver, which allows you to start Webots and communicate with it. Other sub-packages are mainly examples that show multiple possible implementations using the interface. In this tutorial, you are going to install the package and learn how to run one of these examples.

It is recommended to understand basic ROS principles covered in the beginner Tutorials. In particular, Creating a workspace and Creating a package are useful prerequisites.

It is necessary to install Webots natively on the mac in order to use the webots_ros2 package in the virtual machine as explained below. You can follow the installation procedure or build it from sources.

            Setting up a robot simulation (Basic)

  In this tutorial, you are going to use the Webots robot simulator to set-up and run a very simple ROS 2 simulation scenario.

The webots_ros2 package provides an interface between ROS 2 and Webots. It includes several sub-packages, but in this tutorial, you are going to use only the webots_ros2_driver sub-package to implement a Python or C++ plugin controlling a simulated robot. Some other sub-packages contain demos with different robots such as the TurtleBot3. They are documented in the Webots ROS 2 examples page.

It is recommended to understand basic ROS principles covered in the beginner Tutorials. In particular, Using turtlesim, ros2, and rqt, Understanding topics, Creating a workspace, Creating a package and Creating a launch file are useful prerequisites.

In this tutorial, you set-up a realistic robot simulation with Webots and implemented a custom plugin to control the motors of the robot.

               Setting up a robot simulation (Advanced)

In this tutorial you will extend the package created in the first part of the tutorial: Setting up a robot simulation (Basic). The aim is to implement a ROS 2 node that avoids obstacles using the robot’s distance sensors. This tutorial focuses on using robot devices with the webots_ros2_driver interface.

This is a continuation of the first part of the tutorial: Setting up a robot simulation (Basic). It is mandatory to start with the first part to set up the custom packages and necessary files.

This tutorial is compatible with version 2023.1.0 of webots_ros2 and Webots R2023b, as well as upcoming versions.

In this tutorial, you extended the basic simulation with a obstacle avoider ROS 2 node that publishes velocity commands based on the distance sensor values of the robot.

                The Ros2Supervisor Node

In this tutorial, you will learn how to enable the Ros2Supervisor node which enhances the interface by creating additional services and topics to interact with the simulation. You can, for example, record animations or spawn Webots nodes directly from the ROS 2 interface while the simulation is running. These instructions list in details the current implemented features and how to use them.

In this tutorial, you learned how to enable the Ros2Supervisor and how to extend the interface with the Webots simulation. The node creates multiple services and topics to interact with and modify the simulation.

               Setting up a Reset Handler

In this tutorial, you will learn how to implement a reset handler in a robot simulation using Webots. The Webots reset button reverts the world to the initial state and restarts controllers. It is convenient as it quickly resets the simulation, but in the context of ROS 2, robot controllers are not started again making the simulation stop. The reset handler allows you to restart specific nodes or perform additional actions when the reset button in Webots is pressed. This can be useful for scenarios where you need to reset the state of your simulation or restart specific components without completely restarting the complete ROS system.

In this tutorial, you learned how to implement a reset handler in a robot simulation using Webots. The reset handler allows you to restart specific nodes or perform additional actions when the reset button in Webots is pressed. You explored different approaches based on the complexity of your simulation and the requirements of your nodes.

                Setting up a robot simulation (Gazebo)

First of all you should install ROS 2 and Gazebo. You have two options:

Install from deb packages. To check which versions are available from deb packages please check this table.
Compile from sources:
ROS 2 install instructions
Gazebo install instructions

In this demo you are going to simulate a simple diff drive robot in Gazebo. You are going to use one of the worlds defined in the Gazebo examples called visualize_lidar.sdf.

In this tutorial, you launched a robot simulation with Gazebo, launched bridges with actuators and sensors, visualized data from a sensor, and moved a diff drive robot.

              Setting up security

The sros2 package provides the tools and instructions to use ROS 2 on top of DDS-Security. The security features have been tested across platforms (Linux, macOS, and Windows) as well as across different languages (C++ and Python). The SROS2 has been designed to work with any secure middleware, although not all middleware is open source and support varies depending on the ROS distribution in use. Please reach out to the ROS 2 Security Working Group if you encounter any support issues.


         Understanding the security keystore

The sros2 package can be used to create keys, certificates and policies necessary to enable ROS 2 security. However, the security configuration is extrememly flexible. A basic understanding of the ROS 2 Security Keystore will allow integration with an existing PKI (Public Key Infrastructure) and managment of sensitive key materials consistent with organizational policies.

Secure processes (typically ROS nodes) run within a security enclave. In the simplest case, all the processes can be consolidated into the same enclave, and all processes will then use the same security policy. However, to apply different policies to different processes, the processes can use different security enclaves when starting. For more details about security enclaves, see the design document. The security enclave is specifed by using the ROS argument --enclave when running a node. 

            Ensuring security across machines

The previous tutorials have used two ROS nodes on the same machine sending all network communications over the localhost interface. Let’s extend that scenario to involve multiple machines, since the benefits of authentication and encryption then become more obvious.
     
Suppose that the machine with the keystore created in the previous demo has a hostname Alice, and that we want to also use another machine with hostname Bob for our multi-machine talker/listener demo. We need to move some keys from Alice to Bob to allow SROS 2 to authenticate and encrypt the transmissions.

               Examining network traffic

ROS 2 communications security is all about protecting communications between nodes. Prior tutorials enabled security, but how can you really tell if traffic is being encrypted? In this tutorial we’ll take a look at capturing live network traffic to show the difference between encrypted and unencrypted traffic.

The destination address is 239.255.0.1, which is a multicast IP address; ROS 2 uses multicast traffic for discovery by default.
UDP 7400 is the destination port, as per the DDS-RTPS specification.
The packet contains the “RTPS” tag, also as defined to the DDS-RTPS specification.

                     Setting access controls

Permissions are quite flexible and can be used to control many behaviors within the ROS graph.

For this tutorial, we demonstrate a policy which only allows publishing messages on the default chatter topic. This would prevent, for instance, remapping the topic when launching the listener or using the same security enclaves for another purpose.

In order to enforce this policy, we need to update the permissions.xml file and re-sign it before launching the node. This can be done by modifying the permissions file by hand, or by using XML templates.

                      Deployment Guidelines

Typical deployment scenarios often involve shipping containerized applications, or packages, into remote systems. Special attention should be payed when deploying security enabled applications, requiring users to reason about the sensitivity of packaged files.

Complying with the DDS Security standard, the sros2 package provides a collection of utilities for managing security under ROS 2 environments in a highly modular and flexible fashion.

Basic core guidelines on how to organize the different certificates, keys and directories remains a critical factor to avoid compromising the security of the system. This includes protection-awareness and criteria for selecting the minimum set of necessary files to be deployed upon remote production systems for minimizing security exposure.

A docker installation with the compose plugin. Please refer to the installation steps detailed in Docker installation and Compose Plugin.
(Recommended) A basic understanding on ROS 2 Security design.
(Recommended) Previous security tutorials completion. In particular:

Setting up security
Understanding the security keystore
Setting access controls

keystore-creator: That, similarly to previous tutorials, it internally initializes a new keystore tree directory. This will create enclaves/ public/ and private/, which are explained in more detail in ROS 2 Security enclaves. The keystore directory is configured to be a shared volume across containers.
listener and talker: Act as the remote device actors in this tutorial. Required Security environment variables are sourced as well as the necessary keystore files from the shared volume.
