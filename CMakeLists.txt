# note: following this post for setting up CMake
# https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html

cmake_minimum_required (VERSION 2.8)

project(PA9)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall -std=c++17")

# make an automatic library
add_library(pa_library ${PROJECT_NAME}.cpp ${PROJECT_NAME}.h LinkedList.cpp LinkedList.h)

# create unit test executable
add_subdirectory(test)

# create main executable
add_executable(run${PROJECT_NAME} Main.cpp ${PROJECT_NAME}.cpp LinkedList.cpp)

