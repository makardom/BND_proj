//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGDecSize_HPP
#define BND_CATALOGDecSize_HPP
#include "CatalogCommand.hpp"
namespace CatalogNS {
class DecSize: CatalogCommand{
public:
    explicit DecSize(Catalog &catalog);
    void execute() override;
    ~DecSize() override;
};
}
#endif //BND_CATALOGDecSize_HPP
