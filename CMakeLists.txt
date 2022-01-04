cmake_minimum_required(VERSION 3.8)

set(This Example)
project(${This} CXX)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(test)
add_subdirectory(src)

