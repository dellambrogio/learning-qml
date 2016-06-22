
cmake_minimum_required(VERSION 3.2)

project(OthelloGame)

find_package(Eigen3 REQUIRED)

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

)

target_include_directories(${PROJECT_NAME}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
	PUBLIC ${EIGEN3_INCLUDE_DIR}
)
