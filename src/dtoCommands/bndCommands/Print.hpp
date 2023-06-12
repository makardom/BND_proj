//
// Created by maksi on 09.06.2023.
//

#ifndef BND_PRINT_HPP
#define BND_PRINT_HPP

#include "dto/BND.h"

namespace BNDNS {
    class Print {
    private:
        BND &bnd;
    public:
        explicit Print(BND &bnd);

        std::string execute();

        ~Print();
    };
}
#endif //BND_PRINT_HPP
