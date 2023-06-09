//
// Created by maksi on 09.06.2023.
//

#ifndef BND_DELETETHISUNIT_HPP
#define BND_DELETETHISUNIT_HPP
#include "CatalogUnitCommand.hpp"
class DeleteThisUnit: CatalogUnitCommand{
public:
    explicit DeleteThisUnit(CatalogUnit &catalogUnit);
    void execute() override;
    ~DeleteThisUnit() override;
};
#endif //BND_DELETETHISUNIT_HPP
