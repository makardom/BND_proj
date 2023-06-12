//
// Created by maksi on 13.06.2023.
//
#include "Save.hpp"
#include "CommonFunctions.h"
#include "UtilsFunctions.hpp"

Save::Save(LibraryData &libraryData) : libraryData(libraryData) {}

std::string Save::checkAndAssemble(Parser &parser) {
    std::string errorMessage;

    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;

    return errorMessage;
}
std::string Save::checkAmount(const Parser &parser) {

    if(!parser.getKeyArgs().empty()){
        return TOO_MANY_ARGS;
    }

    if(!parser.getPosArgs().empty()){
        return TOO_MANY_ARGS;
    }

    return "";
}
std::string Save::run() {
    std::string str;
    if(!libraryData.isInit){
        return str = "Library data is not initialized!";
    }
    try {
        UtilsFunctions::deleteFile("BND.bin");
        libraryData.serializer.create("BND.bin");
        libraryData.serializer.save(libraryData.bnd);
        libraryData.serializer.close();
        str = "Library data was saved successfully";
    } catch (IOException &e){
        str = str + e.what();
    }
    return str;
}
std::string Save::getQuery(){
    return "save";
}
std::string Save::help() {
    return "usage: save";
}

std::string Save::description() {
    return "Save from file";
}
