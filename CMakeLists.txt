cmake_minimum_required(VERSION 3.16)

project("MiniCAD")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "D:/coding/QT/5.12.4/msvc2017_64")

set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets OpenGL)
find_package(OpenGL REQUIRED)

add_subdirectory("src-cpp")
add_subdirectory(src-cpp/core)
add_subdirectory(src-cpp/entity)