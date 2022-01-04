cmake_minimum_required(VERSION 3.8)

set(This Example)
project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(test)
add_subdirectory(src)

