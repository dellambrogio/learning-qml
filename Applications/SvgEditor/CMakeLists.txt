
cmake_minimum_required(VERSION 2.8.11)

project(SvgEditor)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets Quick Core QuickControls2)

file(GLOB SOURCES
	*.hpp
	*.cpp
	*.qml
	*.qrc
	*.conf
	*.js
	*.png
)

qt5_add_resources(RESOURCES qml.qrc)

add_executable(${PROJECT_NAME}
	${SOURCES} 
	${RESOURCES}
)

target_link_libraries(${PROJECT_NAME}
	ReversiController
	Qt5::Core
	Qt5::Widgets
	Qt5::Quick
	Qt5::QuickControls2
)
