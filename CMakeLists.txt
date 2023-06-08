cmake_minimum_required(VERSION 3.25)
project(BND_proj)

set(CMAKE_CXX_STANDARD 23)
include_directories(src)
add_subdirectory(lib)
add_executable(BND_proj dto/Catalog.h dto/CatalogUnit.h dto/BND.h src/main.cpp src/serializer/ISerializer.hpp src/serializer/BinSerializer.hpp src/serializer/BinSerializer.cpp src/exceptions/FileNotFoundException.hpp src/exceptions/IOException.hpp src/exceptions/FileCannotCreate.hpp src/exceptions/FileWriteException.hpp src/exceptions/CatalogSpaceFull.hpp src/exceptions/CatalogSpaceUnspecified.hpp src/exceptions/CatalogNameTooLong.hpp src/exceptions/BNDCannotAddDataInDataArea.hpp src/exceptions/BNDImpossibleToReorganize.hpp)
