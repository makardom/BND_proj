//
// Created by maksi on 08.06.2023.
//
/**
 * @file BNDCommandFactory.h
 * @brief Определение класса шаблона BNDCommandFactory
 */
#ifndef MONITOR_MYCOMMANDFACTORY_HPP
#define MONITOR_MYCOMMANDFACTORY_HPP

#include "CommandFactory.hpp"
#include "LibraryData.hpp"

/**
* @class BNDCommandFactory
* @tparam CommandClasses Тип создаваемых команд
* @brief Фабричный класс, создающий команды типа CommandClasses с использованием библиотеки данных.
*/
template<typename CommandClasses>
class BNDCommandFactory : public CommandFactory<CommandClasses> {
private:
    LibraryData &libraryData;///< Ссылка на объект LibraryData

public:

    /**
    * @brief Конструктор класса BNDCommandFactory
    * @param libraryData Ссылка на объект LibraryData, который будет использоваться при создании команд
    */
    explicit BNDCommandFactory(LibraryData &libraryData) : CommandFactory<CommandClasses>(), libraryData(libraryData){}

    /**
    * @brief Создает объект команды
    * @param commandString Строка, представляющая тип создаваемой команды.
    * @return Общий указатель на объект BaseCommand
    * @note Переопределено из CommandFactory
    */
    std::shared_ptr<BaseCommand> getCommand(const std::string &commandString) override {
        return CommandFactory<CommandClasses>::construct(commandString, libraryData);
    }
};


#endif //MONITOR_MYCOMMANDFACTORY_HPP