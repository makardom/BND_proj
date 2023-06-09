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
public:
    explicit Init(LibraryData &libraryData);
    static std::string getQuery();

    std::string checkAndAssemble(Parser &parser) final;
    std::string run() final;

    std::string processQuery(Parser &parser) final;
    std::string help() override;

    static std::string description();
};
#endif //BND_INIT_H
