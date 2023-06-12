//
// Created by maksi on 12.06.2023.
//
#include "SearchRecordByName.hpp"
namespace CatalogNS{
    SearchRecordByName::SearchRecordByName(Catalog &catalog, const char *name): catalog(catalog), name(name) {}

    CatalogUnit *SearchRecordByName::execute() {
        for (int i = 0; i < catalog.getSize(); i++) {
            if (strcmp(catalog.getRecords()[static_cast<unsigned long long int>(i)].getName(), name) == 0) {
                return &catalog.getRecords()[static_cast<unsigned long long int>(i)];
            }
        }
        return nullptr;
    }
}