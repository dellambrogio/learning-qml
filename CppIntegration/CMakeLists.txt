cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME CppIntegration)

project(${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Quick Core)

file(GLOB SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.h
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.qml
	${CMAKE_CURRENT_SOURCE_DIR}/*.qrc
)

qt5_add_resources(RESOURCES qml.qrc)

add_executable(${PROJECT_NAME} ${SOURCES} ${RESOURCES})

qt5_use_modules(${PROJECT_NAME} Quick Core)
