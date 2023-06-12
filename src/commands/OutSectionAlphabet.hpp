//
// Created by maksi on 12.06.2023.
//

#ifndef BND_OUTSECTIONALPHABET_HPP
#define BND_OUTSECTIONALPHABET_HPP
#include "BaseCommand.h"
#include "LibraryData.hpp"
class OutSectionAlphabet : public BaseCommand {
private:
    LibraryData &libraryData;
    static std::string checkAmount(const Parser &parser);
    static constexpr char TOO_MANY_ARGS[] = "Too many arguments (see INIT --help).";

public:
    explicit OutSectionAlphabet(LibraryData &libraryData);
    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;

    std::string help() override;

    static std::string description();
};
#endif //BND_OUTSECTIONALPHABET_HPP
