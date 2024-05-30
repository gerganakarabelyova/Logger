##Project Description: 

#Task Manager with Logging

##Author: Gergana Karabelyova

##Overview
This project is a simple command-line task manager application implemented in C++. It allows users to create, view, complete, and remove tasks. Additionally, the application logs various actions such as adding, completing, viewing, and removing tasks to a log file for tracking and debugging purposes. The logger provides insights into the program's operations and helps maintain a record of user interactions.

##Files:
•	logger.h
•	logger.cpp – main file
•	task.h
•	task_manager.h

##Features
1.	Add Task: Users can add a new task by providing a title, description, and due date. The task is then stored in a list.
2.	View Tasks: Users can view all tasks along with their details, including completion status. This action is logged.
3.	Complete Task: Users can mark a task as completed by specifying the task title. The task's completion status is updated and the action is logged.
4.	Remove Task: Users can remove a task by specifying the task title. The task is removed from the list, and the action is logged.
5.	Logging: All actions are logged to a file (task_manager.log). The log includes timestamps and log levels (INFO, WARNING, etc.) to help track and debug the application.

##Components
1.	Logger (logger.h):
•	Logs messages to a file with different log levels (DEBUG, INFO, WARNING, ERROR).
•	Records timestamps for each log entry.
2.	Task (task.h):
•	Represents a task with a title, description, due date, and completion status.
•	Provides methods to get task details and mark a task as complete.
3.	Task Manager (task_manager.h):
•	Manages a list of tasks.
•	Provides methods to add, view, complete, and remove tasks.
•	Logs each action using the Logger class.
4.	Main Program (logger.cpp):
•	Provides a command-line interface for interacting with the task manager.
•	Allows users to choose actions from a menu and perform operations on tasks.

##How to Use
1.	Compile the Program:
g++ -o task_manager logger.cpp -I. -std=c++11 
2.	Run the Program:
./task_manager 
3.	Interact with the Program:
•	Follow the on-screen menu to add, view, complete, or remove tasks, or exit.
•	Check the log file (task_manager.log) to see recorded actions and debug if necessary.

##Example Usage
1.	Add a Task:
•	Enter task title, description, and due date when prompted.
•	The task will be added to the list and logged.
2.	View Tasks:
•	View a list of all tasks with their details and completion status.
•	This action will be logged.
3.	Complete a Task:
•	Enter the title of the task to mark it as complete.
•	The task's status will be updated and the action will be logged.
4.	Remove a Task:
•	Enter the title of the task to remove it from the list.
•	The task will be removed and the action will be logged.
5.	Exit:
•	Choose to exit the program from the menu.


