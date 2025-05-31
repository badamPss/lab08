#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "formatter_ex.h"

std::string get_current_time() {
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void log_message(std::ostream& stream, const std::string& level, const std::string& message) {
    stream << "[" << get_current_time() << "] [" << level << "] " << message << std::endl;
}

int main()
{
    const char* log_path = std::getenv("LOG_PATH");
    std::ofstream log_file;
    
    if (log_path) {
        log_file.open(log_path);
        if (log_file.is_open()) {
            log_message(log_file, "INFO", "Application started");
            log_message(log_file, "INFO", "Configuration loaded successfully");
        }
    }
    
    log_message(std::cout, "INFO", "Application started");
    log_message(std::cout, "INFO", "Configuration loaded successfully");
    
    try {
        formatter(std::cout, "hello, world!");
        if (log_file.is_open()) {
            log_message(log_file, "INFO", "Message formatted and displayed successfully");
        }
        log_message(std::cout, "INFO", "Message formatted and displayed successfully");
    } catch (const std::exception& e) {
        if (log_file.is_open()) {
            log_message(log_file, "ERROR", std::string("Error occurred: ") + e.what());
        }
        log_message(std::cout, "ERROR", std::string("Error occurred: ") + e.what());
        return 1;
    }
    
    if (log_file.is_open()) {
        log_message(log_file, "INFO", "Application finished successfully");
        log_file.close();
    }
    log_message(std::cout, "INFO", "Application finished successfully");
    
    return 0;
}
