//
// Created by maksi on 13.06.2023.
//
#include "Load.hpp"
#include "CommonFunctions.h"
#include "serializer/BinSerializer.hpp"

Load::Load(LibraryData &libraryData) : libraryData(libraryData) {}

std::string Load::checkAndAssemble(Parser &parser) {
    std::string errorMessage;

    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;

    return errorMessage;
}
std::string Load::checkAmount(const Parser &parser) {

    if(!parser.getKeyArgs().empty()){
        return TOO_MANY_ARGS;
    }

    if(!parser.getPosArgs().empty()){
        return TOO_MANY_ARGS;
    }

    return "";
}
std::string Load::run() {
    std::string str;
    if(libraryData.isInit){
        return str = "Library data has been already initialized! Delete first!";
    }
    try {
        libraryData.serializer.open("BND.bin");
        libraryData.serializer.load(libraryData.bnd);
        libraryData.serializer.close();
        libraryData.isInit = true;
        str = "Library data was loaded successfully";
    } catch (IOException &e){
        str = str + e.what();
    }
    return str;
}
std::string Load::getQuery(){
    return "load";
}
std::string Load::help() {
    return "usage: load";
}

std::string Load::description() {
    return "Init from file";
}
