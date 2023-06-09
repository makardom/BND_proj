//
// Created by maksi on 09.06.2023.
//

#ifndef BND_INIT_H
#define BND_INIT_H
#include "BaseCommand.h"
#include "LibraryData.hpp"

class Init : public BaseCommand {
private:
    LibraryData &libraryData;
    uint16_t catAmount = 0;
    uint16_t catOffset = 0;
    static std::string checkAmount(const Parser &parser);
    std::string setCatalogAmount(const keyArgs_t &keys);
    std::string setCatalogOffset(const keyArgs_t &keys);
    static constexpr char NOT_ENOUGH_ARGS[] = "Not enough arguments (see INIT --help).";
    static constexpr char TOO_MANY_ARGS[] = "Too many arguments (see INIT --help).";
    static constexpr char CATALOGAMOUNT_CANT_CONVERT[] = "Catalog Amount has incorrect format.";
    static constexpr char CATALOGAMOUNT_RESTRICTED[] = "Catalog amount must be in range [1, 65535].";
    static constexpr char NO_CATALOGAMOUNT_VALUE[] = "Catalog amount can’t be empty.";
    static constexpr char CATALOGOFFSET_CANT_CONVERT[] = "Catalog offset has incorrect format.";
    static constexpr char CATALOGOFFSET_RESTRICTED[] = "Catalog offset must be in range [1, 65535].";
    static constexpr char NO_CATALOGOFFSET_VALUE[] = "Catalog offset can’t be empty.";

public:
    explicit Init(LibraryData &libraryData);
    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;

    std::string help() override;

    static std::string description();
};
#endif //BND_INIT_H
