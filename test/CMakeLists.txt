cmake_minimum_required(VERSION 3.8)

set(This ExampleTest)
set(ResultXmlDir xmls)
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

# add_test(
#     NAME ${This}
#     COMMAND ${This}
# )
include(GoogleTest)
gtest_discover_tests(${This} 
                    XML_OUTPUT_DIR ${ResultXmlDir})
