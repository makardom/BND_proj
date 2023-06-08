//
// Created by maksi on 08.06.2023.
//

#ifndef BND_PROJ_LIBRARYDATA_HPP
#define BND_PROJ_LIBRARYDATA_HPP

#include "dto/BND.h"
#include "serializer/ISerializer.hpp"

class ISerializer;

class LibraryData{
public:
    ISerializer &serializer;
    BND bnd;
    bool isInit = false;
public:
    explicit LibraryData(ISerializer &serializer) : serializer(serializer) {}

    LibraryData(LibraryData &libraryData) = delete; // can't copy serializer and info about library data

    LibraryData(LibraryData &&libraryData) noexcept = default;
    LibraryData &operator =(const LibraryData &libraryData) = delete; // can't copy serializer and info about library data

    void open(const std::string& filename);

    void close();
};
#endif //BND_PROJ_LIBRARYDATA_HPP
