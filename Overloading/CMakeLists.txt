cmake_minimum_required(VERSION 3.27)
project(Overloading)

set(CMAKE_CXX_STANDARD 17)

add_executable(Overloading main.cpp
        cmake-build-debug/Complex.cpp
        cmake-build-debug/Complex.h)
