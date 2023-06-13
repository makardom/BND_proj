//
// Created by maksi on 12.06.2023.
//
#include "OutSectionAlphabet.hpp"
#include "exceptions/CatalodMemoryIsNotAllocated.hpp"
#include "exceptions/CatalogRecordsAreEmpty.hpp"

OutSectionAlphabet::OutSectionAlphabet(LibraryData &libraryData) : libraryData(libraryData) {}

std::string OutSectionAlphabet::checkAndAssemble(Parser &parser) {
    std::string errorMessage;
    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;
    return errorMessage;
}
std::string OutSectionAlphabet::checkAmount(const Parser &parser) {
    if(!parser.getKeyArgs().empty()){
        return TOO_MANY_ARGS;
    }
    if(!parser.getPosArgs().empty()){
        return TOO_MANY_ARGS;
    }

    return "";
}

std::string OutSectionAlphabet::run() {
    string str;
    if(!libraryData.isInit){
        return str = "Library data is not initialized!";
    }
    if(libraryData.bnd.getCatamount() == 0){
        throw CatalogMemoryIsNotAllocated();
    }
    if(libraryData.bnd.getCatalog().getRecords().empty()){
        throw CatalogRecordsAreEmpty();
    }
    string names[libraryData.bnd.getCatalog().getSize()];
    for (int i=0; i<libraryData.bnd.getCatalog().getSize(); i++){
        names[i] = libraryData.bnd.getCatalog().getRecords()[i].getName();
    }
    vector<string> namevec;
    for(auto &i : names)
        namevec.push_back(i);
    sort(namevec.begin(), namevec.end());
    for(auto &i : namevec)
        str += i + " ";
    return str;
}
std::string OutSectionAlphabet::getQuery(){
    return "alphabet";
}
std::string OutSectionAlphabet::help() {
    return "usage: alphabet";
}

std::string OutSectionAlphabet::description() {
    return "Puts catalogs in alphabetic order";
}