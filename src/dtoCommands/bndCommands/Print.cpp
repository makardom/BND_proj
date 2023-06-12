//
// Created by maksi on 09.06.2023.
//
#include "Print.hpp"
#include "../catalogCommands/Print.hpp"
namespace BNDNS {
    Print::Print(BND &bnd) : BNDCommand(bnd) {}

    void Print::execute() {
        cout << "LB" << bnd.getCatOffset() << bnd.getCatamount() << " ";
        for (int i = 0; i < bnd.getCatOffset(); i++)
            cout << *(bnd.getDataArea() + i);
//        bnd.getCatalog().print();
        CatalogNS::Print catalogPrint(bnd.getCatalog());
        catalogPrint.execute();
        cout << endl;
    }

    Print::~Print() = default;
}