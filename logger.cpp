// logger.cpp
// Author: Gergana Karabelyova

#include "task_manager.h"
#include <iostream>

void showMenu(){
    std::cout << "-------------------\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Complete Task\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "-------------------\n";
}

int main(){
    TaskManager taskManager("task_manager.log");
    int choice;
    std::string title, description, dueDate;

    do{
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // This method clear the newline character from the input buffer

        switch(choice){
            case 1:
                std::cout << "Enter task title: ";
                std::getline(std::cin, title);
                std::cout << "Enter task description: ";
                std::getline(std::cin, description);
                std::cout << "Enter task due date: ";
                std::getline(std::cin, dueDate);
                taskManager.addTask(Task(title, description, dueDate));
                break;
            case 2:
                taskManager.viewTasks();
                break;
            case 3:
                std::cout << "Enter task title to complete: ";
                std::getline(std::cin, title);
                taskManager.completeTask(title);
                break;
            case 4:
                std::cout << "Enter task title to remove: ";
                std::getline(std::cin, title);
                taskManager.removeTask(title);
                break;
            case 5:
                std::cout << "Exiting ... \n";
                taskManager.exiting();
                break;
            default:
                std::cout << "Invalid choice. Please try again. \n";
        }
    } while (choice != 5);

    return 0;
}