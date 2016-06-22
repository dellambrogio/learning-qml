
cmake_minimum_required(VERSION 3.2)

project(OthelloGameTests)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

file(GLOB HEADERS 
	*.hpp
)

file(GLOB SOURCES 
	*.cpp
)

add_executable(${PROJECT_NAME}
	${HEADERS}
	${SOURCES}
)

target_link_libraries(${PROJECT_NAME}
	OthelloGame
	${GTEST_BOTH_LIBRARIES}
	${CMAKE_THREAD_LIBS_INIT}
)

target_include_directories(${PROJECT_NAME}
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
	PRIVATE ${GTEST_BOTH_LIBRARIES}
)

add_test(AllTestsIn${PROJECT_NAME} ${PROJECT_NAME})
