
cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED ${GTEST_ROOT})
	set(GTEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/gtest/build)
endif()

find_package(GTest QUIET)

if(${GTEST_FOUND})
	add_subdirectory(ReversiTests)
endif()
