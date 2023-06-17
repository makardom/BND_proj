//
// Created by maksi on 08.06.2023.
//
/**
 * @file BNDCommands.h
 *
 * @brief Содержит объявления типов BNDCommandsTuple и BNDCommands.
 */
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
#include "Load.hpp"
#include "Save.hpp"
/**
 * @typedef BNDCommandsTuple
 *
 * @brief Тип кортежа, содержащий все доступные команды.
 *
 * Кортеж состоит из следующих команд:
 * - Init
 * - Print
 * - Add
 * - Reorganization
 * - Delete
 * - RenameCatalog
 * - OutSectionAlphabet
 * - OutFreeSpace
 * - DeleteSection
 * - Load
 * - Save
 */
typedef std::tuple<
    Init,
    Print,
    Add,
    Reorganization,
    Delete,
    RenameCatalog,
    OutSectionAlphabet,
    OutFreeSpace,
    DeleteSection,
    Load,
    Save
> BNDCommandsTuple;
/**
 * @typedef BNDCommands
 *
 * @brief Фабричный класс для выполнения различных команд из кортежа
 */
typedef BNDCommandFactory<BNDCommandsTuple> BNDCommands;
#endif //BND_PROJ_BNDCOMMANDS_HPP
