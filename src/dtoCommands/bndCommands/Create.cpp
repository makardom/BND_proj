//
// Created by maksi on 09.06.2023.
//
#include "Create.hpp"
namespace BNDNS {
    Create::Create(BND &bnd, unsigned short amount, unsigned short offset) : BNDCommand(bnd), catAmount(amount),
                                                                             catOffset(offset) {}

    void Create::execute() {
        bnd.setCatamount(catAmount);
        bnd.setCatOffset(catOffset);
        bnd.setDataArea(new int[catOffset]{0});
    }

    Create::~Create() = default;
}