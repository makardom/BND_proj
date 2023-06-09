//
// Created by maksi on 09.06.2023.
//

#ifndef BND_PRINT_HPP
#define BND_PRINT_HPP
#include "CatalogUnitCommand.hpp"
class Print: CatalogUnitCommand{
public:
    explicit Print(CatalogUnit &catalogUnit);
    void execute() override;
    ~Print() override;
};
#endif //BND_PRINT_HPP
