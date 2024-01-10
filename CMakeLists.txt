cmake_minimum_required(VERSION 3.5)

project(Howdy)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set(CMAKE_CXX_STANDARD 14)
# set (DCMAKE_BUILD_TYPE "Debug")
set(sources "${PROJECT_SOURCE_DIR}/src")

include_directories("${PROJECT_SOURCE_DIR}/include")
file (GLOB source_files "${sources}/*.cpp")

add_executable(Howdy ${source_files})

# Must add include directories after the executable
# target_include_directories(Howdy PRIVATE "${PROJECT_SOURCE_DIR}/include")