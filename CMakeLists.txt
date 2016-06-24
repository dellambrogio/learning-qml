cmake_minimum_required(VERSION 3.2)

project(LearningQML)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/CMake/Modules/)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/bin")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/lib")

# std c++11
set(CMAKE_CXX_STANDARD 11)

#add_subdirectory(Playground)
add_subdirectory(Libraries)
add_subdirectory(Applications)
add_subdirectory(Tests)
