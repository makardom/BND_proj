//
// Created by maksi on 12.06.2023.
//
#include <sstream>
#include "../dtoCommands/bndCommands/Print.hpp"
#include "Print.h"
Print::Print(LibraryData &libraryData) : libraryData(libraryData) {}

std::string Print::checkAndAssemble(Parser &parser) {
    std::string errorMessage;
    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;
    return errorMessage;
}
std::string Print::checkAmount(const Parser &parser) {
    if(!parser.getKeyArgs().empty()){
        return TOO_MANY_ARGS;
    }
    if(!parser.getPosArgs().empty()){
        return TOO_MANY_ARGS;
    }

    return "";
}

std::string Print::run() {
    return BNDNS::Print(libraryData.bnd).execute();
}
std::string Print::getQuery(){
    return "print";
}
std::string Print::help() {
    return "usage: print";
}

std::string Print::description() {
    return "print library data";
}