cmake_minimum_required(VERSION 3.22)
project(hello_world)

set(CMAKE_CXX_STANDARD 14)

add_executable(hello_world main.cpp)

add_executable(hello_world2 demo.cpp)

add_executable(hello_world3 demo2.cpp)