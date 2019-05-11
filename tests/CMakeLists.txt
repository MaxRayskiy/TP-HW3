project(tests)

add_executable(runTests tests.cpp)
include_directories(lib/gtest-1.8.1/include lib/gtest-1.8.1)
add_subdirectory(lib/gtest-1.8.1)

target_link_libraries(runTests gtest gtest_main)

enable_testing()