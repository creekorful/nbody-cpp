cmake_minimum_required(VERSION 3.9)
project(nbody_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(nbody_cpp Source/main.cpp Source/constant.h Source/Application.cpp Source/Application.h Source/Body.cpp Source/Body.h Source/Vector.cpp Source/Vector.h)