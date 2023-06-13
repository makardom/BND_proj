//
// Created by maksi on 12.06.2023.
//
#include "OutFreeSpace.hpp"
#include "exceptions/DataAreaIsNotAllocated.hpp"

OutFreeSpace::OutFreeSpace(LibraryData &libraryData) : libraryData(libraryData) {}

std::string OutFreeSpace::checkAndAssemble(Parser &parser) {
    std::string errorMessage;
    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;
    return errorMessage;
}
std::string OutFreeSpace::checkAmount(const Parser &parser) {
    if(!parser.getKeyArgs().empty()){
        return TOO_MANY_ARGS;
    }
    if(!parser.getPosArgs().empty()){
        return TOO_MANY_ARGS;
    }

    return "";
}

std::string OutFreeSpace::run() {
    string str;
    if(!libraryData.isInit){
        return str = "Library data is not initialized!";
    }
    if (libraryData.bnd.getCatOffset() == 0){
        throw DataAreaIsNotAllocated();
    }
    if (libraryData.bnd.getDataArea() == nullptr){
        throw DataAreaIsNotAllocated();
    }
    int kol = 0;
        for(int i=0; i<libraryData.bnd.getCatOffset(); i++){
            if (*(libraryData.bnd.getDataArea()+i)==0)
                kol++;
        }
        str ="Amount free space: " + to_string(kol);
    return str;
}
std::string OutFreeSpace::getQuery(){
    return "freespace";
}
std::string OutFreeSpace::help() {
    return "usage: freespace";
}

std::string OutFreeSpace::description() {
    return "Print free space in data area";
}