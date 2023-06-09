//
// Created by maksi on 09.06.2023.
//
#include "Init.h"
#include "UtilsFunctions.hpp"
#include "limits"
Init::Init(LibraryData &libraryData) : libraryData(libraryData) {}

std::string Init::checkAndAssemble(Parser &parser) {
    std::string errorMessage;

    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;

    if(errorMessage = setCatalogAmount(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;
    if(errorMessage = setCatalogOffset(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;


    return errorMessage;
}
std::string Init::checkAmount(const Parser &parser) {
    if(parser.getKeyArgs().size() > 2){
        return TOO_MANY_ARGS;
    }

    if(parser.getKeyArgs().size() < 2){
        return NOT_ENOUGH_ARGS;
    }

    if(!parser.getPosArgs().empty()){
        return TOO_MANY_ARGS;
    }

    return "";
}
std::string Init::setCatalogAmount(const keyArgs_t &keys) {
    if(auto it = keys.find("catalogAmount"); it != keys.end() || ((it = keys.find("a")) != keys.end())) {
        // convert to int
        int intCatalogAmount = 0;
        if(UtilsFunctions::convertToNumber(it->second, intCatalogAmount)) return CATALOGAMOUNT_CANT_CONVERT;

        // check restrictions
        if (intCatalogAmount < 1 || std::numeric_limits<unsigned short>::max() < intCatalogAmount) {
            return CATALOGAMOUNT_RESTRICTED;
        }

        catAmount = static_cast<uint16_t>(intCatalogAmount);
    } else {
        return NO_CATALOGAMOUNT_VALUE;
    }

    return "";
}
std::string Init::setCatalogOffset(const keyArgs_t &keys) {
    if(auto it = keys.find("catalogOffset"); it != keys.end() || ((it = keys.find("o")) != keys.end())) {
        // convert to int
        int intCatalogOffset = 0;
        if(UtilsFunctions::convertToNumber(it->second, intCatalogOffset)) return CATALOGOFFSET_CANT_CONVERT;

        // check restrictions
        if (intCatalogOffset < 1 || std::numeric_limits<unsigned short>::max() < intCatalogOffset) {
            return CATALOGOFFSET_RESTRICTED;
        }

        catAmount = static_cast<uint16_t>(intCatalogOffset);
    } else {
        return NO_CATALOGOFFSET_VALUE;
    }

    return "";
}
std::string Init::run() {
    if (!libraryData.serializer.is_open()){
        libraryData.serializer.create("bnd.bin");
    }

    std::stringstream str;
    str << "Library data created successfully.";
    return str.str();
}
std::string Init::getQuery(){
    return "init";
}
std::string Init::help() {
    return "usage: init -a <catalogAmount> -o <catalogOffset>";
}

std::string Init::description() {
    return "initializes library data";
}