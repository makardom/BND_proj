//
// Created by maksi on 09.06.2023.
//
#include "MakeNewMassive.hpp"
namespace CatalogNS {
    MakeNewMassive::MakeNewMassive(Catalog &catalog) : CatalogCommand(catalog) {}

    void MakeNewMassive::execute() {
        if (catalog.getSize() == 0) {
            catalog.getRecords().clear();
        } else {
            int i = 0;
            for (const auto &record: catalog.getRecords()) {
                if (record.getNameSize() == 0) {
                    break;
                }
                i++;
            }
            catalog.getRecords().erase(catalog.getRecords().cbegin() + i);
        }
        copy(catalog.getRecords().begin(), catalog.getRecords().end(), catalog.getRecords().begin());
    }


    MakeNewMassive::~MakeNewMassive() = default;
}