# =============================================================================
#   Copyright (c) 2016 Nextcode
#   Nextcode, Zurich. All rights reserved.
#
#   Authors: Michele Dell'Ambrogio (m@nextcode.ch)
# =============================================================================

cmake_minimum_required(VERSION 2.8.11)

project(QWidgetMultiFileChooser)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Core Widgets)

file(GLOB HEADERS 
	*.h
)

file(GLOB SOURCES 
	*.cpp
)

file(GLOB GUI_UI 
	*.ui
)

qt5_wrap_ui(GUI_UI_H ${GUI_UI})

qt5_add_resources(RESOURCES qdarkstyle/style.qrc)

add_executable(${PROJECT_NAME} WIN32
	${HEADERS}
	${SOURCES}
	${RESOURCES}
	${GUI_UI_H}
)

qt5_use_modules(${PROJECT_NAME} Core Widgets)
