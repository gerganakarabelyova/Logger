// task.h
// Author: Gergana Karabelyova

#include <string>

#ifndef TASK_H
#define TASK_H

class Task{
    public:
        Task(const std::string& title, const std::string& description, const std::string& dueDate)
            : title(title), description(description), dueDate(dueDate), completed(false){}
        
        std::string getTitle() const {
            return title;
        }

        std::string getDescription() const {
            return description;
        }

        std::string getDueDate() const {
            return dueDate;
        }

        bool isCompleted() const { 
            return completed; 
        }

        void complete() {
            completed = true; 
        } 

    private:
        std::string title;
        std::string description;
        std::string dueDate;
        bool completed;
};

#endif