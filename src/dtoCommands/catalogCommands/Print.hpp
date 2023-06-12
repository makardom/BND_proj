//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGPRINT_HPP
#define BND_CATALOGPRINT_HPP

#include "dto/Catalog.h"

namespace CatalogNS {
    class Print {
    private:
        Catalog &catalog;
    public:
        explicit Print(Catalog &catalog);

        std::string execute();

        ~Print();
    };
}
#endif //BND_CATALOGPRINT_HPP
