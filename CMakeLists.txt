cmake_minimum_required(VERSION 3.0)
project(antibodies VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(model)

add_subdirectory(report)

add_executable(antibodies main.cpp)
target_link_libraries(antibodies PRIVATE model report)
