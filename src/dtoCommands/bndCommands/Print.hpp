//
// Created by maksi on 09.06.2023.
//

#ifndef BND_PRINT_HPP
#define BND_PRINT_HPP
#include "BNDCommand.hpp"
namespace BNDNS {
    class Print : BNDCommand {
    public:
        explicit Print(BND &bnd);

        void execute() override;

        ~Print() override;
    };
}
#endif //BND_PRINT_HPP
