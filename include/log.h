#pragma once

// Old-style "header-guide"
// #ifndef _LOG_H
// #define _LOG_H

#include <iostream>

void log(const char*);

class Logger 
{
  public:
    // TODO: Convert this to an ENUM eventually
    // const int log_level_error = 0;
    // const int log_level_warning = 1;
    // const int log_level_info = 2;

    enum LogLevel
    {
      ERROR = 0,
      WARNING = 1,
      INFO = 2
    };

    // Define a constructor
    Logger() {std::cout << "Created default Logger." << std::endl;};
    Logger(LogLevel log_level) : log_level_{log_level}
      {
        std::cout << "Created Logger with Log Level: " << log_level_ 
          << std::endl;
      };

    // Define a destructor
    ~Logger() {
      std::cout << "Destroyed Logger with Log Level: " << log_level_ 
        << std::endl;
    }

    void set_level(LogLevel log_level);

    // Using const char* in place of strings for now.
    void error(const char* message);
    void warn(const char* message);
    void info(const char* message);

  private:
    // static methods (and also variables?) cannot access non-static variables
    // static LogLevel log_level_{log_level_info};
    LogLevel log_level_{ERROR};
};

// #endif