//
// Created by maksi on 09.06.2023.
//
#include "Init.h"
Init::Init(LibraryData &libraryData) : libraryData(libraryData) {}

std::string Init::checkAndAssemble(Parser &parser) {
    std::string errorMessage;

    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;

    if(errorMessage = setBlocks(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;
    if(errorMessage = setSegments(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;

    return errorMessage;
}
