//
// Created by maksi on 09.06.2023.
//
#include "AddRecord.hpp"
namespace CatalogNS {
    AddRecord::AddRecord(Catalog &catalog, CatalogUnit &catalogUnit) : CatalogCommand(catalog), record(catalogUnit) {}

    void AddRecord::execute() {
        catalog.getRecords().push_back(record);
        catalog.setSize(catalog.getSize() + 1);
    }

    AddRecord::~AddRecord() = default;
}