//
// Created by maksi on 12.06.2023.
//

#ifndef BND_ADD_HPP
#define BND_ADD_HPP
#include "BaseCommand.h"
#include "LibraryData.hpp"

class Add : public BaseCommand {
private:
    LibraryData &libraryData;
    uint16_t length = 0;
    string name;
    static std::string checkAmount(const Parser &parser);
    std::string setLength(const keyArgs_t &keys);
    std::string setName(const keyArgs_t &keys);
    static constexpr char NOT_ENOUGH_ARGS[] = "Not enough arguments (see INIT --help).";
    static constexpr char TOO_MANY_ARGS[] = "Too many arguments (see INIT --help).";
    static constexpr char LENGTH_CANT_CONVERT[] = "Length has incorrect format.";
    static constexpr char LENGTH_RESTRICTED[] = "Length must be in range [1, 65535].";
    static constexpr char NO_LENGTH_VALUE[] = "length can’t be empty.";
    static constexpr char NO_NAME_VALUE[] = "name can’t be empty.";
    static constexpr char NAME_TOO_LONG[] = "The name is too long (maximum 10 chars).";
    static constexpr char NAME_INCORRECT[] = "Name has incorrect format.";

public:
    explicit Add(LibraryData &libraryData);
    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;

    std::string help() override;

    static std::string description();
};
#endif //BND_ADD_HPP
