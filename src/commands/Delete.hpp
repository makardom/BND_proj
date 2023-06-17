//
// Created by maksi on 12.06.2023.
//

#ifndef BND_DELETE_HPP
#define BND_DELETE_HPP
#include "BaseCommand.h"
#include "LibraryData.hpp"
/**
 * @file Delete.hpp
 * @brief Содержит объявление класса Delete
 */

/**
 * @class Delete
 * @brief Удаляет все данные из библиотечного набора данных
 * @details Наследуется от класса BaseCommand и реализует методы checkAndAssemble(), run() и help().
 */
class Delete : public BaseCommand {
private:
    LibraryData &libraryData;/**< Ссылка на данные библиотеки */

    /**
    * @brief Проверяет количество аргументов парсера
    * @param parser Объект, содержащий аргументы парсера
    * @return Пустая строка в случае успеха, сообщение об ошибке в случае неудачи
    */
    static std::string checkAmount(const Parser &parser);
    static constexpr char TOO_MANY_ARGS[] = "Too many arguments (see INIT --help).";/**< Сообщение об ошибке для слишком большого количества аргументов */

public:

    /**
    * @brief Конструктор объекта Delete
    * @param libraryData Ссылка на данные библиотеки
    */
    explicit Delete(LibraryData &libraryData);

    /**
    * @brief Получить строку запроса для этой команды
    * @return Строка запроса для этой команды
    */
    static std::string getQuery();

    /**
    * Метод проверяет аргументы из объекта парсера и собирает их в соответствующие команде переменные
    * @param parser объект парсера, содержащий массивы полученных аргументов
    * @return сообщение об ошибке (при ошибке)
    */
    std::string checkAndAssemble(Parser &parser) final;

    /**
     * Метод запускает соответствующую команде функцию библиотечных данных
     * @return Код ошибки или void в зависимости от команды
     */
    std::string run() final;

    /**
     * Выводит в сохраненный поток вывода информацию о команде
     * @return Сохраненный поток вывода
     */
    std::string help() override;

    /**
    * @brief Получить строку описания этой команды
    * @return Строка описания этой команды
    */
    static std::string description();
};
#endif //BND_DELETE_HPP
