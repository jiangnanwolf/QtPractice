cmake_minimum_required(VERSION 3.15)

project(MyTextFinder)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(MyTextFinder main.cpp window.cpp)

target_link_libraries(MyTextFinder Qt6::Widgets)