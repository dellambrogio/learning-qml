#=============================================================================
#  Copyright (c) 2016 Disney Enterprises, Inc.
#  Disney Research, Zurich. All rights reserved.
#
#  Authors: Michele Dell'Ambrogio (mda@disneyresearch.com)
#=============================================================================

cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME MoviePlayer)

project(${PROJECT_NAME})

set(CMAKE_AUTOMOC ON)
find_package(Qt5 REQUIRED COMPONENTS Core Quick)

file(GLOB SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.qml
	${CMAKE_CURRENT_SOURCE_DIR}/*.js
	${CMAKE_CURRENT_SOURCE_DIR}/*.qrc
	${CMAKE_CURRENT_SOURCE_DIR}/*.mp4
)

qt5_add_resources(RESOURCES qml.qrc)

add_executable(${PROJECT_NAME}
	${SOURCES}
	${RESOURCES}
)

target_link_libraries(${PROJECT_NAME}
	Qt5::Core
	Qt5::Quick
)
