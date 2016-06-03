cmake_minimum_required(VERSION 2.8.11)

project(Othello)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Quick Core)

file(GLOB SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/*.qml
	${CMAKE_CURRENT_SOURCE_DIR}/*.qrc
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
