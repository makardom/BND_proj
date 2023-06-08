//
// Created by maksi on 08.06.2023.
//

#ifndef MONITOR_MYCOMMANDFACTORY_HPP
#define MONITOR_MYCOMMANDFACTORY_HPP

#include "CommandFactory.hpp"
#include "LibraryData.hpp"

template<typename CommandClasses>
class BNDCommandFactory : public CommandFactory<CommandClasses> {
private:
    LibraryData &libraryData;

public:
    explicit BNDCommandFactory(LibraryData &libraryData) : CommandFactory<CommandClasses>(), libraryData(libraryData){}

    std::shared_ptr<BaseCommand> getCommand(const std::string &commandString) override {
        return CommandFactory<CommandClasses>::construct(commandString, &libraryData);
    }
};


#endif //MONITOR_MYCOMMANDFACTORY_HPP