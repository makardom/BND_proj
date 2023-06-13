//
// Created by maksi on 12.06.2023.
//
#include "DeleteSection.hpp"
#include "CommonFunctions.h"
#include "dtoCommands/catalogCommands/SearchRecordByName.hpp"
#include "dtoCommands/catalogUnitCommands/DeleteThisUnit.hpp"
#include "dtoCommands/catalogCommands/DecSize.hpp"
#include "dtoCommands/catalogCommands/MakeNewMassive.hpp"
#include "exceptions/CatalodMemoryIsNotAllocated.hpp"
#include "exceptions/CatalogRecordsAreEmpty.hpp"
#include "exceptions/CatalogNotFound.hpp"

DeleteSection::DeleteSection(LibraryData &libraryData) : libraryData(libraryData) {}

std::string DeleteSection::checkAndAssemble(Parser &parser) {
    std::string errorMessage;

    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;

    if(errorMessage = setName(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;

    return errorMessage;
}
std::string DeleteSection::checkAmount(const Parser &parser) {
    if(parser.getKeyArgs().size() > 1){
        return TOO_MANY_ARGS;
    }

    if(parser.getKeyArgs().empty()){
        return NOT_ENOUGH_ARGS;
    }

    if(!parser.getPosArgs().empty()){
        return TOO_MANY_ARGS;
    }

    return "";
}
std::string DeleteSection::setName(const keyArgs_t &keys) {
    string str;
    if (auto it = keys.find("name"); it != keys.end() || ((it = keys.find("n")) != keys.end())) {
        str = it->second;
    }
    else {
        return NO_NAME_VALUE;
    }
    if (!MonCom::isASCII(name)) {
        return NAME_INCORRECT;
    }
    if (name.size() > 10) {
        return NAME_TOO_LONG;
    }
    name = str;

    return "";
}
std::string DeleteSection::run() {
    std::string str;
    if(!libraryData.isInit){
        return str = "Library data is not initialized!";
    }
    try {
        if (name.length()>10){
            throw CatalogNameTooLong();
        }
        if(libraryData.bnd.getCatamount() == 0){
            throw CatalogMemoryIsNotAllocated();
        }
        if(libraryData.bnd.getCatalog().getRecords().empty()){
            throw CatalogRecordsAreEmpty();
        }
        char *namesec = new char[name.length()];
        for(int i=0; i<name.length(); i++){
            *(namesec+i) = name[i];
            *(namesec+i+1) = '\0';
        }
        CatalogUnit *finded = CatalogNS::SearchRecordByName(libraryData.bnd.getCatalog(), namesec).execute();
        if(finded == nullptr)
            throw CatalogNotFound();
        unsigned int start =  finded->getOffset();
        unsigned int len =  finded->getLength();
        for(unsigned int i=start; i<start+len; i++){
            *(libraryData.bnd.getDataArea()+i) = 0;
        }
        CatalogUnitNS::DeleteThisUnit(finded).execute();
        CatalogNS::DecSize(libraryData.bnd.getCatalog()).execute();
        CatalogNS::MakeNewMassive(libraryData.bnd.getCatalog()).execute();

        str = "Catalog record was deleted successfully";
    } catch (IOException &e){
        str = str + e.what();
    }
    return str;
}
std::string DeleteSection::getQuery(){
    return "deletecatalog";
}
std::string DeleteSection::help() {
    return "usage: deletecatalog -n <name>";
}

std::string DeleteSection::description() {
    return "Delete catalog and it's data";
}
