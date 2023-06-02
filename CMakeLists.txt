cmake_minimum_required(VERSION 3.25)
project(BND_proj)

set(CMAKE_CXX_STANDARD 23)

add_executable(BND_proj Catalog.h CatalogUnit.h BND.h main.cpp)
