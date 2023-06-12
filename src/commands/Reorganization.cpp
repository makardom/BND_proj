//
// Created by maksi on 12.06.2023.
//
#include "Reorganization.hpp"
#include <sstream>
#include "../dtoCommands/bndCommands/Print.hpp"
#include "UtilsFunctions.hpp"

Reorganization::Reorganization(LibraryData &libraryData) : libraryData(libraryData) {}

std::string Reorganization::checkAndAssemble(Parser &parser) {
    std::string errorMessage;
    if(errorMessage = checkAmount(parser); !errorMessage.empty()) return errorMessage;
    return errorMessage;
}
std::string Reorganization::checkAmount(const Parser &parser) {
    if(!parser.getKeyArgs().empty()){
        return TOO_MANY_ARGS;
    }
    if(!parser.getPosArgs().empty()){
        return TOO_MANY_ARGS;
    }

    return "";
}

std::string Reorganization::run() {
    string str;
    if(!libraryData.isInit){
        return str = "Library data is not initialized!";
    }
    try{
        unsigned int offsets[libraryData.bnd.getCatalog().getSize()];
        unsigned int lengths = 0;
        auto *records = new CatalogUnit[libraryData.bnd.getCatamount()];
        for (int i=0; i<libraryData.bnd.getCatalog().getSize(); i++){
            offsets[i] = libraryData.bnd.getCatalog().getRecords()[i].getOffset();
            lengths += libraryData.bnd.getCatalog().getRecords()[i].getLength();
        }
        if(lengths == libraryData.bnd.getCatOffset())
            throw BNDImpossibleToReorganize();
        for(int i = 0; i < libraryData.bnd.getCatOffset() - lengths; i++) //обходим столько раз, сколько свободных ячеек в DataArea
        {
            int nol = 0;
            while(*(libraryData.bnd.getDataArea()+nol)!=0){
                nol++;
            }
            while (nol<=libraryData.bnd.getCatOffset()-2){
                if(*(libraryData.bnd.getDataArea()+nol+1)==1)
                {
                    int sec = UtilsFunctions::checkSection(libraryData.bnd,nol+1, offsets);
                    if(sec!=-1) {
                        libraryData.bnd.getCatalog().getRecords()[sec].setOffset(nol);
                        offsets[UtilsFunctions::checkPosition(offsets, libraryData.bnd.getCatalog().getSize(), nol + 1)] = nol;
                    }
                }
                nol++;
                UtilsFunctions::switchData(libraryData.bnd, nol-1, nol);
            }
        }
        str = "Data has been reorganized successfully";
    }catch (IOException &e){
        str = e.what();
    }
    return str;
}
std::string Reorganization::getQuery(){
    return "reorganize";
}
std::string Reorganization::help() {
    return "usage: reorganize";
}

std::string Reorganization::description() {
    return "Reorganize data area";
}