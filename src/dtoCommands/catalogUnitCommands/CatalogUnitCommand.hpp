//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGUNITCOMMAND_HPP
#define BND_CATALOGUNITCOMMAND_HPP

#include "dto/CatalogUnit.h"
namespace CatalogUnitNS {
    class CatalogUnitCommand {
    public:
        CatalogUnit catalogUnit;

        explicit CatalogUnitCommand(CatalogUnit &catalogUnit): catalogUnit(catalogUnit) {}

        virtual void execute() = 0;

        virtual ~CatalogUnitCommand() = default;
    };
}
#endif //BND_CATALOGUNITCOMMAND_HPP
