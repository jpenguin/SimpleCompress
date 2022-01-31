cmake_minimum_required(VERSION 3.21)
project(SimpleCompress)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SimpleCompress
        Compress.cpp
        Compress.h
        main.cpp)
