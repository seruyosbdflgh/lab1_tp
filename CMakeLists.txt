cmake_minimum_required(VERSION 4.2.0)

project(lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCES
    main.cpp
    base.cpp
    fantast.cpp
    keeper.cpp
    poet.cpp
    romanist.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})