//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CatalogUnitPRINT_HPP
#define BND_CatalogUnitPRINT_HPP
#include "BNDCommand.hpp"
namespace BNDNS {
    class Print : BNDCommand {
    public:
        explicit Print(BND &bnd);

        void execute() override;

        ~Print() override;
    };
}
#endif //BND_CatalogUnitPRINT_HPP
