//
// Created by maksi on 04.06.2023.
//
#include "BinSerializer.hpp"
#include "../exceptions/FileNotFoundException.hpp"
#include "../exceptions/FileCannotCreate.hpp"

void BinSerializer::open(const std::string &filename) {
    file.open(filename);

    if (!file.is_open()) {
        throw FileNotFoundException();
    }
}

void BinSerializer::close() {
    file.close();
}


bool BinSerializer::is_open() {
    return file.is_open();
}

void BinSerializer::create(const std::string &filename) {
    file.open(filename, std::ios::in | std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        throw FileCannotCreate();
    }
}