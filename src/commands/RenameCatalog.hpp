//
// Created by maksi on 12.06.2023.
//

#ifndef BND_RENAMECATALOG_HPP
#define BND_RENAMECATALOG_HPP
#include "BaseCommand.h"
#include "LibraryData.hpp"

class RenameCatalog : public BaseCommand {
private:
    LibraryData &libraryData;
    string oldname;
    string newname;
    static std::string checkAmount(const Parser &parser);
    std::string setOldName(const keyArgs_t &keys);
    std::string setNewName(const keyArgs_t &keys);
    static constexpr char NOT_ENOUGH_ARGS[] = "Not enough arguments (see INIT --help).";
    static constexpr char TOO_MANY_ARGS[] = "Too many arguments (see INIT --help).";
    static constexpr char LENGTH_CANT_CONVERT[] = "Length has incorrect format.";
    static constexpr char LENGTH_RESTRICTED[] = "Length must be in range [1, 65535].";
    static constexpr char NO_LENGTH_VALUE[] = "length can’t be empty.";
    static constexpr char NO_NAME_VALUE[] = "name can’t be empty.";
    static constexpr char NAME_TOO_LONG[] = "The name is too long (maximum 10 chars).";
    static constexpr char NAME_INCORRECT[] = "Name has incorrect format.";

public:
    explicit RenameCatalog(LibraryData &libraryData);
    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;

    std::string help() override;

    static std::string description();
};
#endif //BND_RENAMECATALOG_HPP
