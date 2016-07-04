
cmake_minimum_required(VERSION 3.0)

project(ReversiController)

find_package(Eigen3 REQUIRED)
find_package(Qt5 COMPONENTS Core)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

file(GLOB HEADERS 
	include/${PROJECT_NAME}/*.hpp
	src/*.hpp
)

file(GLOB SOURCES 
	src/*.cpp
)

add_library(${PROJECT_NAME} STATIC
	${HEADERS}
	${SOURCES}
)

target_link_libraries(${PROJECT_NAME}
	Reversi
	Qt5::Core
)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
	PUBLIC ${EIGEN3_INCLUDE_DIR}
)
