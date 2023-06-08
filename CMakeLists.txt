cmake_minimum_required(VERSION 3.25)
project(BND)

set(CMAKE_CXX_STANDARD 23)
include_directories(src)

add_subdirectory(lib)
add_subdirectory(src)