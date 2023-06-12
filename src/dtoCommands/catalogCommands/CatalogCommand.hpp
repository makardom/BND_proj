//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGCOMMAND_HPP
#define BND_CATALOGCOMMAND_HPP

#include "dto/Catalog.h"
namespace CatalogNS {
    class CatalogCommand {
    public:
        Catalog &catalog;

        explicit CatalogCommand(Catalog &catalog);

        virtual void execute() = 0;

        virtual ~CatalogCommand();
    };
}
#endif //BND_CATALOGCOMMAND_HPP
