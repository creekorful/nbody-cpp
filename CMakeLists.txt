cmake_minimum_required(VERSION 3.9)
project(nbody_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)

find_package(SFML REQUIRED COMPONENTS graphics window system)

include_directories(${SFML_INCLUDE_DIR})

add_executable(nbody_cpp Source/main.cpp Source/constant.h Source/Application.cpp Source/Application.h Source/Body.cpp Source/Body.h Source/Vector.cpp Source/Vector.h Source/System.cpp Source/System.h Source/BodiesLoader.cpp Source/BodiesLoader.h)

target_link_libraries(nbody_cpp ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})