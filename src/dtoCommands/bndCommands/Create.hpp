//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CREATE_HPP
#define BND_CREATE_HPP
#include "BNDCommand.hpp"
namespace BNDNS {
    class Create : BNDCommand {
    private:
        unsigned short catAmount;
        unsigned short catOffset;
    public:
        Create(BND *bnd, unsigned short amount, unsigned short offset);

        void execute() override;

        ~Create() override;
    };
}
#endif //BND_CREATE_HPP