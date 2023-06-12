//
// Created by maksi on 09.06.2023.
//
#include "../catalogCommands/Print.hpp"
#include "Print.hpp"
namespace BNDNS {
    Print::Print(BND &bnd) : bnd(bnd) {}

    std::string Print::execute() {
        std::string str ="LB" + to_string(bnd.getCatOffset()) + to_string(bnd.getCatamount()) + " ";
        for (int i = 0; i < bnd.getCatOffset(); i++) {
            string strchar = to_string(*(bnd.getDataArea() + i));
            str += strchar;
        }
        str += " ";
        str += CatalogNS::Print(bnd.getCatalog()).execute();
        return str;
    }

    Print::~Print() = default;
}