cmake_minimum_required(VERSION 3.22)
project(Speech_Project_STL)

set(CMAKE_CXX_STANDARD 14)

add_executable(Speech_Project_STL main.cpp src/speechManager.cpp include/speechManager.h src/Speaker.cpp include/Speaker.h)
