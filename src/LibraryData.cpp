//
// Created by maksi on 09.06.2023.
//
#include "LibraryData.hpp"
#include "exceptions/FileNotFoundException.hpp"
#include "exceptions/LibraryDataNotInitializedException.hpp"
#include "exceptions/InvalidFileFormatException.hpp"
#include "exceptions/LibraryDataCorruptedException.hpp"
#include "exceptions/UnexpectedEndOfFileException.hpp"

void LibraryData::open(const std::string& filename){
    try {
        serializer.open(filename);
    } catch (FileNotFoundException &e){
        throw LibraryDataNotInitializedException();
    }
    try {
        serializer.load(bnd);
    } catch (UnexpectedEndOfFileException &e) {
        throw LibraryDataCorruptedException();
    } catch (InvalidFileFormatException &e) {
        throw LibraryDataCorruptedException();
    }

    isInit = true;
}
void LibraryData::close(){
    serializer.close();
}
