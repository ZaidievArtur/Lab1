cmake_minimum_required(VERSION 3.25)
project(Lab1Algor)

set(CMAKE_CXX_STANDARD 17)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

add_executable(Lab1Algor main.cpp Human.h Program.cpp Program.h LinkedList.h)
