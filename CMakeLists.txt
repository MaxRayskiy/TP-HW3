cmake_minimum_required(VERSION 2.6)

project(TP-HW3)
include(gtest.cmake)

add_definitions(-Wall -std=gnu++0x -D HOME)


add_executable(executeTests test.cpp)

target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)


# GTest needs threading support
find_package (Threads)
target_link_libraries(gtest ${CMAKE_THREAD_LIBS_INIT})