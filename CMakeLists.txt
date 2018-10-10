cmake_minimum_required(VERSION 3.1)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Core REQUIRED HINTS ~/Qt/5.11.0/gcc_64)
find_package(Qt5Sql REQUIRED HINTS ~/Qt/5.11.0/gcc_64)

include_directories(src)

add_subdirectory(src)
