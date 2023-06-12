//
// Created by maksi on 12.06.2023.
//
#include "Add.hpp"
#include "UtilsFunctions.hpp"
#include "CommonFunctions.h"
#include "dtoCommands/catalogCommands/AddRecord.hpp"
#include "dtoCommands/catalogUnitCommands/Print.hpp"
#include <limits>

Add::Add(LibraryData &libraryData) : libraryData(libraryData) {}

std::string Add::checkAndAssemble(Parser &parser) {
    std::string errorMessage;

    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;

    if(errorMessage = setLength(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;
    if(errorMessage = setName(parser.getKeyArgs()); !errorMessage.empty()) return errorMessage;

    return errorMessage;
}
std::string Add::checkAmount(const Parser &parser) {
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
std::string Add::setLength(const keyArgs_t &keys) {
    if(auto it = keys.find("length"); it != keys.end() || ((it = keys.find("l")) != keys.end())) {
        // convert to int
        int intLength = 0;
        if(UtilsFunctions::convertToNumber(it->second, intLength)) return LENGTH_CANT_CONVERT;

        // check restrictions
        if (intLength < 1 || std::numeric_limits<unsigned short>::max() < intLength) {
            return LENGTH_RESTRICTED;
        }

        length = static_cast<uint16_t>(intLength);
    } else {
        return NO_LENGTH_VALUE;
    }

    return "";
}
std::string Add::setName(const keyArgs_t &keys) {
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
std::string Add::run() {
    std::string str;
    if(!libraryData.isInit){
        return str = "Library data is not initialized!";
    }
    try {
        if (libraryData.bnd.getCatalog().getSize() == libraryData.bnd.getCatamount()) {
            throw CatalogSpaceFull();
        }
        if (libraryData.bnd.getDataArea() == nullptr) {
            throw CatalogSpaceUnspecified();
        }
        if (name.length() > 10) {
            throw CatalogNameTooLong();
        }
        char *charname = new char[name.length() + 1];
        for (int i = 0; i < name.length(); i++) {
            *(charname + i) = name[i];
            *(charname + i + 1) = '\0';
        }
        int num = UtilsFunctions::findSpace(libraryData.bnd, length);
        if (num == -1) {
            throw BNDCannotAddDataInDataArea();
        } else {
            for (int i = num; i < num + length; i++) {
                *(libraryData.bnd.getDataArea() + i) = BLOCK;
            }
            CatalogUnit newCatU(charname, num, length);
            CatalogNS::AddRecord(libraryData.bnd.getCatalog(), newCatU).execute();
        }
        str = "Catalog was added successfully";
    } catch (IOException &e){
        str = str + e.what();
    }
    return str;
}
std::string Add::getQuery(){
    return "add";
}
std::string Add::help() {
    return "usage: add -n <name> -l <length>";
}

std::string Add::description() {
    return "add catalog of length";
}
