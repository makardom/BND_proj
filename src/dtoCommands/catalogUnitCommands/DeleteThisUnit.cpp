//
// Created by maksi on 09.06.2023.
//
#include "DeleteThisUnit.hpp"
DeleteThisUnit::DeleteThisUnit(CatalogUnit &catalogUnit) : CatalogUnitCommand(catalogUnit){}
void DeleteThisUnit::execute() {
    catalogUnit.setName(new char[10]{'\0'});
    catalogUnit.setOffset(0);
    catalogUnit.setLength(0);
}

DeleteThisUnit::~DeleteThisUnit()= default;