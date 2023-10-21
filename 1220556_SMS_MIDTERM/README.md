Name: Elyor           Student ID: 12204556         SMS Midterm assignment
                              
                              Dynamic Fleet Management with ROS2 (Python)
                      Project Overview
In this assignment, I worked on implementing a dynamic fleet management system using ROS2 (Robot Operating System 2) in Python. The goal of the project was to efficiently allocate and route vehicles in a smart mobility service. I built both the Action Server and Action Client components and created a professional Command Line Interface (CLI) for interaction.

                       Table of Contents

Project Overview
Objectives
Task Description
Task 1: Defined ROS2 Action
Task 2: Implemented the Action Server
Task 3: Developed the Action Client CLI
Task 4: Crafted a Professional CLI
Task 5: Tested with Scenarios
Task 6: Documented the Project
Strategy
                      Objectives

My main objectives for this assignment were as follows:
To gain practical experience in developing ROS2 applications with Python.
To create a functional ROS2 project.
To learn how to use GitHub for version control.
To practice proper documentation and reporting.

                    Task Explanations
                    
                Task 1: Defined ROS2 Action
In this step, I created a ROS2 Action file named fleet_management.action. This file defined the Action Goal, Result, and Feedback messages. The Action Goal included an integer field for the fleet size, the Action Result consisted of an array of strings representing vehicle routes, and the Action Feedback contained a float indicating the completion percentage.

                Task 2: Implemented the Action Server
For this task, I developed a Python script named fleet_management_server_cli.py that served as the Action Server. This server was responsible for receiving fleet size requests, executing fleet management logic (e.g., allocation and routing), and returning the calculated routes as the Action Result. I ensured to include proper error handling and logging for a robust implementation.
 
              Task 3: Developed the Action Client CLI
In this step, I created a Python script known as fleet_management_client_cli.py, which functioned as the Action Client. This client empowered users to request fleet management tasks by specifying the desired fleet size. It sent the request to the server, received the routes in response, and presented them to the user.

             Task 4: Crafted a Professional CLI
Here, I designed a user-friendly Command Line Interface (CLI) using the click library. The CLI provided an option for users to allocate and route vehicles by specifying the fleet size. Internally, it called the Action Client CLI to execute the task seamlessly.

             Task 5: Tested with Scenarios
I created two distinct scenarios, each with real-world data, to rigorously test the application. For each scenario, I provided the following details:

                Summary               
In this project, I implemented a dynamic fleet management system using ROS2 and Python. The project's goal was to efficiently allocate and route vehicles in a smart mobility service. I developed the Action Server and Action Client components and created a user-friendly Command Line Interface (CLI). The project included defining ROS2 Actions, building the server and client, and thorough documentation. The use of Git for version control and proper documentation ensured a functional and well-documented ROS2 project.       
