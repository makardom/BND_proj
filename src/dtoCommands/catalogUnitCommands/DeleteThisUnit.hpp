//
// Created by maksi on 09.06.2023.
//

#ifndef BND_DELETETHISUNIT_HPP
#define BND_DELETETHISUNIT_HPP
#include "CatalogUnitCommand.hpp"
namespace CatalogUnitNS {
    class DeleteThisUnit{
    public:
        CatalogUnit *catalogUnit;
        explicit DeleteThisUnit(CatalogUnit *catalogUnit): catalogUnit(catalogUnit) {}

        void execute() const{
            char * name = new char[10]{'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
            catalogUnit->setName(name);
            catalogUnit->setOffset(0);
            catalogUnit->setLength(0);
        }

        ~DeleteThisUnit() = default;
    };

#endif //BND_DELETETHISUNIT_HPP
}