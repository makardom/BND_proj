//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGPRINT_HPP
#define BND_CATALOGPRINT_HPP
#include "CatalogCommand.hpp"
namespace CatalogNS {
    class Print : CatalogCommand {
    public:
        explicit Print(Catalog &catalog);

        void execute() override;

        ~Print() override;
    };
}
#endif //BND_CATALOGPRINT_HPP
