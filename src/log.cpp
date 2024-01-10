// C++ standard library header files have no .h file extension (C header files do)
#include <iostream>

#include "log.h"

void log(const char* message)
{
  std::cout << message << std::endl;
}

void Logger::set_level(LogLevel log_level) { log_level_ = log_level; }

void Logger::error(const char* message)
{
  if (this->log_level_ >= this->ERROR)
  {
    std::cout << "[ERROR]: " << message << std::endl; 
  }
}

void Logger::warn(const char* message)
{
  if (this->log_level_ >= this->WARNING)
  {
    std::cout << "[WARNING]: " << message << std::endl; 
  }
}

void Logger::info(const char* message)
{
  if (this->log_level_ >= this->INFO)
  {
    std::cout << "[INFO]: " << message << std::endl; 
  }
}