cmake_minimum_required(VERSION 3.25)
project(BND_proj)

set(CMAKE_CXX_STANDARD 23)

add_executable(BND_proj src/Catalog.h src/CatalogUnit.h src/BND.h src/main.cpp src/serializer/ISerializer.hpp src/serializer/BinSerializer.hpp src/serializer/BinSerializer.cpp src/exceptions/FileNotFoundException.hpp src/exceptions/IOException.hpp src/exceptions/FileCannotCreate.hpp)
