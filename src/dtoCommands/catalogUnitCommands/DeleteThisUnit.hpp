//
// Created by maksi on 09.06.2023.
//

#ifndef BND_DELETETHISUNIT_HPP
#define BND_DELETETHISUNIT_HPP
#include "CatalogUnitCommand.hpp"
namespace CatalogUnitNS {
    class DeleteThisUnit : CatalogUnitCommand {
    public:
        explicit DeleteThisUnit(CatalogUnit &catalogUnit): CatalogUnitCommand(catalogUnit) {}

        void execute() override{
            catalogUnit.setName(new char[10]{'\0'});
            catalogUnit.setOffset(0);
            catalogUnit.setLength(0);
        }

        ~DeleteThisUnit() override = default;
    };

#endif //BND_DELETETHISUNIT_HPP
}