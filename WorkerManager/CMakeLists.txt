cmake_minimum_required(VERSION 3.22)
project(WorkerManager)

set(CMAKE_CXX_STANDARD 14)

add_executable(WorkerManager main.cpp workerManager.cpp workerManager.h worker.h employee.cpp employee.h manager.cpp manager.h boss.cpp boss.h)
