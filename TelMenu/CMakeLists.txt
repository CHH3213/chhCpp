cmake_minimum_required(VERSION 3.22)
project(TelMenu)

set(CMAKE_CXX_STANDARD 14)

add_executable(TelMenu main.cpp showMenu.cpp showMenu.h addPerson.cpp addPerson.h Person.h Addressbooks.h showPerson.cpp showPerson.h
        deletePerson.h deletePerson.cpp isExist.cpp modifyPerson.h findPerson.h clearPerson.h)
