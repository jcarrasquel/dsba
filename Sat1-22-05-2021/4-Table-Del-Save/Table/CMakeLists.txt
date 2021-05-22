cmake_minimum_required(VERSION 3.5)

project(Table LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        delegate.cpp
        delegate.h
        secondwindow.cpp
        secondwindow.h
        secondwindow.ui
        student.h
        detailwindow.h
        detailwindow.cpp
        detailwindow.ui
        addwindow.h
        addwindow.cpp
        addwindow.ui
        globalvariables.h
        globalvariables.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Table
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Table SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Table
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Table PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
