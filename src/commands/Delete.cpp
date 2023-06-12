//
// Created by maksi on 12.06.2023.
//
#include "Delete.hpp"
#include <sstream>
#include "../dtoCommands/bndCommands/Print.hpp"
#include "dtoCommands/catalogCommands/DecSize.hpp"

Delete::Delete(LibraryData &libraryData) : libraryData(libraryData) {}

std::string Delete::checkAndAssemble(Parser &parser) {
    std::string errorMessage;
    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;
    return errorMessage;
}
std::string Delete::checkAmount(const Parser &parser) {
    if(!parser.getKeyArgs().empty()){
        return TOO_MANY_ARGS;
    }
    if(!parser.getPosArgs().empty()){
        return TOO_MANY_ARGS;
    }

    return "";
}

std::string Delete::run() {
    string str;
    if(!libraryData.isInit){
        return str = "Library data is not initialized!";
    }
    try{
        libraryData.bnd.setCatamount(0);
        libraryData.bnd.setCatOffset(0);
        delete[] libraryData.bnd.getDataArea();
        libraryData.bnd.setDataArea(nullptr);
        int k = libraryData.bnd.getCatalog().getSize();
        for(int i=0; i<k; i++){
            CatalogNS::DecSize(libraryData.bnd.getCatalog()).execute();
        }
        libraryData.bnd.getCatalog().getRecords().clear();
        str = "Library data has been deleted successfully";
    }catch (IOException &e){
        str = e.what();
    }
    return str;
}
std::string Delete::getQuery(){
    return "delete";
}
std::string Delete::help() {
    return "usage: delete";
}

std::string Delete::description() {
    return "Delete library data";
}