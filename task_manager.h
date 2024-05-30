// task_manager.h
// Author: Gergana Karabelyova

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task.h"
#include "logger.h"
#include <vector>
#include <algorithm>
#include <iostream>

class TaskManager {
    public:
        TaskManager(const std::string& logFileName) : logger(logFileName) {}

        void addTask(const Task& task){
            tasks.push_back(task);
            logger.log(INFO, "Added task: " + task.getTitle());
            std::cout<<"\n Task \"" << task.getTitle() << "\" added!\n";
        }

        void viewTasks() const{
            logger.log(INFO, "Viewed tasks");
            for(const auto& task : tasks){
                std::cout << "Title: " << task.getTitle() << "\nDescription: " << task.getDescription()
                    << "\nDue Date: " << task.getDueDate() << "\nCompleted: " << (task.isCompleted() ? "Yes" : "No") << "\n\n";
            }
        }

        void removeTask(const std::string& title){
            auto it = std::remove_if(  tasks.begin(), tasks.end(), [&title](const Task& task) { return task.getTitle() == title; }  );

            if(it !=tasks.end()){
                tasks.erase(it, tasks.end());
                logger.log(INFO, "Removed task: " + title);
                std::cout<<"\n Task \"" << title << "\" removed!\n";
            }
            else {
                logger.log(ERROR, "Task not found: " + title);
                std::cout<<"\n Task \"" << title << "\" NOT found!\n";
            }
        }

        void completeTask(const std::string& title){
            auto it = std::remove_if(  tasks.begin(), tasks.end(), [&title](const Task& task) { return task.getTitle() == title; }  );
            
            if (it != tasks.end()) {
                it->complete();
                logger.log(INFO, "Completed task: " + title);
                std::cout<<"\n Task \"" << title << "\" completed!\n";
            } 
            else {
                logger.log(ERROR, "Task not found: " + title);
                std::cout<<"\n Task \"" << title << "\" NOT found!\n";
              }
            }

        void exiting(){
            logger.log(INFO, "Exiting.........................................");
        }

    private:
        std::vector<Task> tasks;
        Logger logger;
};

#endif TASK_MANAGER_H