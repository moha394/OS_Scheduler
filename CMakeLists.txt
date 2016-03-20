cmake_minimum_required(VERSION 3.3)
project(OS_Scheduler)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Process.h Scheduler.h sjf.cpp)
add_executable(OS_Project ${SOURCE_FILES})