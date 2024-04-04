/*
* Video #75: Optional Data
*
* In the example below, we show the difference between using std::optional and
* std::variant when attempting to get more information from the return value of
* a function.
*
* Video #75: std::optional
* Video #76: std::variant
*/

#include <fstream>
#include <iostream>
#include <optional>
#include <variant>

// Create an enum class to support the std::variant return type
enum class ErrorType{
  None = 0,
  FileNotFound = 1,
  PermissionError = 2
};

std::ostream& operator<<(std::ostream& stream, const ErrorType& error) {
  stream << static_cast<std::underlying_type<ErrorType>::type>(error);
  return stream;
}

// Use std::variant as the return type.
std::variant<std::string, ErrorType> read_file_as_string_2(const std::string& filepath) {
  std::ifstream stream(filepath);
  if (stream) {
    // TODO: Read file contents into 'result' string
    std::string result;

    stream.close();
    return result;
  }
  else {
    return ErrorType::FileNotFound;
  }
}

// Use std::optional as the return type.
std::optional<std::string> read_file_as_string(const std::string& filepath) {
  std::ifstream stream(filepath);
  if (stream) {
    // TODO: Read file contents into 'result' string
    std::string result;

    stream.close();
    return result;
  }

  // Returning {} is similar to returning None in python (I think?)
  return {};
}

int main() {
  std::string valid_file = "../data/data.txt";
  std::string invalid_file = "../data/data1.txt";

  // 1. Try to read the file and store the result as a std::optional
  std::cout << "Attempting to read valid file path." << std::endl;
  std::optional<std::string> data = read_file_as_string(valid_file);
  // Can also do if (data) instead of if (data.has_value())
  if (data.has_value()) {
    // Do domething with the data
    std::cout << "Data read successfully!" << std::endl;
  }
  else {
    std::cout << "File could not be read." << std::endl; 
  }

  // 2. Try to read the file and store the the result using std::variant
  std::cout << "\nAttempting to read invalid file path." << std::endl;
  std::variant<std::string, ErrorType> result = 
    read_file_as_string_2(invalid_file);
  if (std::get_if<std::string>(&result)) {
    // Do domething with the data
    std::cout << "Data read successfully!" << std::endl;
  }
  else {
    ErrorType* error = std::get_if<ErrorType>(&result);
    // TODO: How to print enum value (not int)??
    std::cout << "File could not be read: " << *error << std::endl;
  }
}