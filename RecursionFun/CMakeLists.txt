cmake_minimum_required(VERSION 3.0.0)
project(RecursionFun VERSION 0.1.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall")
include(CTest)
enable_testing()

add_executable(RecursionFun main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
