#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<sstream>

enum LogLevel{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger{
    public:
    // CONSTRUCTOR
    // The constructor opens a log file in append mode
        Logger(const std::string& fileName) :logFile(fileName, std::ios::app){
            if(!logFile.is_open()){
                std::cerr << "Failed to open log file: " << fileName << std::endl;
            }
        }

    // DESTRUCTOR
    // The destructor ensures the log file is closed when the logger object is destroyed
        ~Logger(){
            if(logFile.is_open()){
                logFile.close();
            }
        }

    // The log method writes a log message with a specified log level (debug, info, warning, error) and the current timestamp (from the getCurrentTime method) to the log file
        void log(LogLevel level, const std::string& message) const{
            if(logFile.is_open()){ // if the log file is opened successfully
                logFile << "[" << getCurrentTime() << "] [" << logLevelToString(level) << "] " << message << std::endl;
            }
        }

    private:
        mutable std::ofstream logFile;

        // This method generates a string representing the current time
        std::string getCurrentTime() const{
            std::time_t now = std::time(nullptr);
            std::tm* nowTm = std::localtime(&now);
            std::ostringstream oss;
            oss << (nowTm->tm_year + 1900) << "-"
            << (nowTm->tm_mon + 1) << "-"
            << nowTm->tm_mday << " "
            << nowTm->tm_hour << ":"
            << nowTm->tm_min << ":"
            << nowTm->tm_sec;
            return oss.str();
        }

        // This method takes the log level labels (from the enum) and converts them to strings
        std::string logLevelToString(LogLevel level) const {
            switch(level){
                case DEBUG: return "DEBUG";
                case INFO: return "INFO";
                case WARNING: return "WARNING";
                case ERROR: return "ERROR";
                default: return "UNKNOWN";
            }
        }
};