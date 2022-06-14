cmake_minimum_required(VERSION 3.22)
project(ComputerRoomOrder)

set(CMAKE_CXX_STANDARD 14)

add_executable(ComputerRoomOrder main.cpp include/Identity.h src/Student.cpp include/Student.h src/Teacher.cpp include/Teacher.h src/Manager.cpp include/Manager.h include/globalFile.h include/ComputerRoom.h src/OrderFile.cpp include/OrderFile.h)
