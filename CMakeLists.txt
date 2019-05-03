cmake_minimum_required(VERSION 2.6)

project(TP-HW3)
#include(gtest.cmake)
set(CMAKE_CXX_STANDARD 11)

add_executable(executeTests test.cpp)

target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)


# GTest needs threading support
#find_package (Threads)
#target_link_libraries(gtest ${CMAKE_THREAD_LIBS_INIT})

add_subdirectory(ext/gtest-1.8.0)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})