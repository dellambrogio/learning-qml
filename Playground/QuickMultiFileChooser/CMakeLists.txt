# =============================================================================
#   Copyright (c) 2016 Nextcode
#   Nextcode, Zurich. All rights reserved.
#
#   Authors: Michele Dell'Ambrogio (m@nextcode.ch)
# =============================================================================

cmake_minimum_required(VERSION 2.8.11)

project(QuickMultiFileChooser)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Quick Core Widgets)

file(GLOB HEADERS 
	*.h
)

file(GLOB SOURCES 
	*.cpp
)

file(GLOB QML
	*.qml
)

qt5_add_resources(RESOURCES qml.qrc)

add_executable(${PROJECT_NAME}
	${HEADERS} 
	${SOURCES} 
	${QML} 
	${RESOURCES}
)

qt5_use_modules(${PROJECT_NAME} Quick Core Widgets)
