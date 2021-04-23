cmake_minimum_required(VERSION 3.19)
project(MyTest)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(MyTest main.cpp)
target_link_libraries(MyTest gtest gtest_main)