//
// Created by maksi on 09.06.2023.
//
#include "CatalogCommand.hpp"
namespace CatalogNS {
    CatalogCommand::CatalogCommand(Catalog &catalog) : catalog(catalog) {}

    CatalogCommand::~CatalogCommand() = default;
}