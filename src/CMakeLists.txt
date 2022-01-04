cmake_minimum_required(VERSION 3.8)

set(This FunctionLib)
project(${This})

set(Sources
    function.cpp
)

add_library(${This} STATIC ${Sources})