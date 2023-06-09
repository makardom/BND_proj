//
// Created by maksi on 09.06.2023.
//

#ifndef BND_BNDMETHODS_HPP
#define BND_BNDMETHODS_HPP

#include "dto/BND.h"
namespace BNDNS {
    class BNDCommand {
    public:
        virtual void execute() = 0;

        BND *bnd;

        explicit BNDCommand(BND *bnd);

        virtual ~BNDCommand();
    };
}
#endif //BND_BNDMETHODS_HPP
