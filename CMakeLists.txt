cmake_minimum_required(VERSION 3.9)
project(nbody_cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)

find_package(SFML REQUIRED COMPONENTS graphics window system)

include_directories(${SFML_INCLUDE_DIR})


add_subdirectory(Source/Majoris)

add_executable(nbody_cpp Source/main.cpp Source/Application/Utils/constant.h
        Source/Application/Body/Body.cpp Source/Application/Body/Body.h
        Source/Application/Utils/Vector.cpp Source/Application/Utils/Vector.h
        Source/Application/System.cpp Source/Application/System.h
        Source/Application/Body/BodiesLoader.cpp Source/Application/Body/BodiesLoader.h
        Source/Application/Application.cpp Source/Application/Application.h
        Source/Application/States/MainMenuState.cpp Source/Application/States/MainMenuState.h
        Source/Application/States/SimulationState.cpp Source/Application/States/SimulationState.h
        Source/Application/GameObjects/BodyGameObject.cpp Source/Application/GameObjects/BodyGameObject.h
        Source/Application/States/EditorState.cpp Source/Application/States/EditorState.h
        Source/Application/States/LoadSystemState.cpp Source/Application/States/LoadSystemState.h)

target_link_libraries(nbody_cpp ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} Majoris)