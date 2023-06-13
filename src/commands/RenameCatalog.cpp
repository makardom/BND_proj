//
// Created by maksi on 12.06.2023.
//
#include "RenameCatalog.hpp"
#include "UtilsFunctions.hpp"
#include "CommonFunctions.h"
#include "dtoCommands/catalogCommands/AddRecord.hpp"
#include "dtoCommands/catalogUnitCommands/Print.hpp"
#include "dtoCommands/catalogCommands/SearchRecordByName.hpp"
#include "exceptions/BNDIsEmpty.hpp"
#include "exceptions/CatalogNotFound.hpp"
#include <limits>

RenameCatalog::RenameCatalog(LibraryData &libraryData) : libraryData(libraryData) {}

std::string RenameCatalog::checkAndAssemble(Parser &parser) {
    std::string errorMessage;

    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;

    if(errorMessage = setOldName(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;
    if(errorMessage = setNewName(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;

    return errorMessage;
}
std::string RenameCatalog::checkAmount(const Parser &parser) {
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
std::string RenameCatalog::setOldName(const keyArgs_t &keys) {
    string str;
    if (auto it = keys.find("oldName"); it != keys.end() || ((it = keys.find("o")) != keys.end())) {
        str = it->second;
    }
    else {
        return NO_NAME_VALUE;
    }
    if (!MonCom::isASCII(oldname)) {
        return NAME_INCORRECT;
    }
    if (oldname.size() > 10) {
        return NAME_TOO_LONG;
    }
    oldname = str;

    return "";
}
std::string RenameCatalog::setNewName(const keyArgs_t &keys) {
    string str;
    if (auto it = keys.find("newName"); it != keys.end() || ((it = keys.find("n")) != keys.end())) {
        str = it->second;
    }
    else {
        return NO_NAME_VALUE;
    }
    if (!MonCom::isASCII(newname)) {
        return NAME_INCORRECT;
    }
    if (newname.size() > 10) {
        return NAME_TOO_LONG;
    }
    newname = str;

    return "";
}
std::string RenameCatalog::run() {
    std::string str;
    if(!libraryData.isInit){
        return str = "Library data is not initialized!";
    }
    try {
        if (libraryData.bnd.getCatalog().getSize() == 0)
            throw BNDIsEmpty();
        if (newname.length()>10){
            throw CatalogNameTooLong();
        }
        if (oldname.length()>10){
            throw CatalogNameTooLong();
        }
        char *oldname1 = new char[oldname.length()];
        for(int i=0; i<oldname.length(); i++){
            *(oldname1+i) = oldname[i];
            *(oldname1+i+1) = '\0';
        }
        char *newname1 = new char[newname.length()];
        for(int i=0; i<newname.length(); i++){
            *(newname1+i) = newname[i];
            *(newname1+i+1) = '\0';
        }
        if (CatalogNS::SearchRecordByName(libraryData.bnd.getCatalog(), oldname1).execute()== nullptr)
            throw CatalogNotFound();
        CatalogNS::SearchRecordByName(libraryData.bnd.getCatalog(), oldname1).execute()->setName(newname1);
        str = "Catalog name was changed successfully";
    } catch (IOException &e){
        str = str + e.what();
    }
    return str;
}
std::string RenameCatalog::getQuery(){
    return "rename";
}
std::string RenameCatalog::help() {
    return "usage: rename -o <oldName> -n <newName>";
}

std::string RenameCatalog::description() {
    return "Rename catalog with oldName to newName";
}
