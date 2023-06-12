//
// Created by maksi on 08.06.2023.
//

#ifndef BND_PROJ_BNDCOMMANDS_HPP
#define BND_PROJ_BNDCOMMANDS_HPP
#include "Init.h"
#include "Print.h"
#include "Add.hpp"
#include "Reorganization.hpp"
#include "BNDCommandFactory.hpp"
#include "Delete.hpp"
#include "RenameCatalog.hpp"
#include "OutSectionAlphabet.hpp"
#include "OutFreeSpace.hpp"
#include "DeleteSection.hpp"

typedef std::tuple<
    Init,
    Print,
    Add,
    Reorganization,
    Delete,
    RenameCatalog,
    OutSectionAlphabet,
    OutFreeSpace,
    DeleteSection
> BNDCommandsTuple;

typedef BNDCommandFactory<BNDCommandsTuple> BNDCommands;
#endif //BND_PROJ_BNDCOMMANDS_HPP
