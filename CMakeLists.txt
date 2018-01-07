cmake_minimum_required(VERSION 3.9)
project(hello_socket)

set(CMAKE_CXX_STANDARD 11)

add_executable(hello_socket main.cpp Sample/Sample.cpp Sample/Sample.h)
