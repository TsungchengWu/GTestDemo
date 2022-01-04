cmake_minimum_required(VERSION 3.8)

set(This ExampleTest)
project(${This} CXX)

include_directories("../src")

set(Sources 
    Test.cpp
)

add_executable(${This}  ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    FunctionLib
)

add_test(
    NAME ${This}
    COMMAND ${This}
)
