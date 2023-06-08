//
// Created by maksi on 08.06.2023.
//

#ifndef BND_PROJ_BNDCOMMANDS_HPP
#define BND_PROJ_BNDCOMMANDS_HPP
#include "Init.h"
#include "BNDCommandFactory.hpp"

typedef std::tuple<
    Init
> BNDCommandsTuple;

typedef BNDCommandFactory<BNDCommandsTuple> BNDCommands;
#endif //BND_PROJ_BNDCOMMANDS_HPP
