//
// Created by maksi on 09.06.2023.
//

#ifndef BND_MAKENEWMASSIVE_HPP
#define BND_MAKENEWMASSIVE_HPP
#include "CatalogCommand.hpp"
namespace CatalogNS {
    class MakeNewMassive : CatalogCommand {
    public:
        explicit MakeNewMassive(Catalog &catalog);

        void execute() override;

        ~MakeNewMassive() override;
    };
}
#endif //BND_MAKENEWMASSIVE_HPP
