//
// Created by maksi on 09.06.2023.
//
#include "DecSize.hpp"
namespace CatalogNS {
    DecSize::DecSize(Catalog &catalog) : CatalogCommand(catalog) {}

    void DecSize::execute() {
        catalog.setSize(catalog.getSize() + 1);
    }

    DecSize::~DecSize() = default;
}