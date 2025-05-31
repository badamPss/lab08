#include <iostream>
#include <fstream>
#include <cstdlib>

#include "formatter_ex.h"

int main()
{
    const char* log_path = std::getenv("LOG_PATH");
    if (log_path) {
        std::ofstream log_file(log_path);
        if (log_file.is_open()) {
            formatter(log_file, "hello, world!");
            log_file.close();
        }
    }
    formatter(std::cout, "hello, world!");
}
