//
// Created by maksi on 09.06.2023.
//
#include "Print.hpp"
#include "../catalogUnitCommands/Print.hpp"
namespace CatalogNS {
    Print::Print(Catalog &catalog) : CatalogCommand(catalog) {}

    void Print::execute() {
        for (int i = 0; i < catalog.getSize(); i++) {
            CatalogUnitNS::Print catalogUnitPrint(catalog.getRecords().operator[](static_cast<unsigned long long int>(i)));
            catalogUnitPrint.execute();
        }
    }

    Print::~Print() = default;
}