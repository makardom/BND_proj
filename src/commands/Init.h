//
// Created by maksi on 09.06.2023.
//

#ifndef BND_INIT_H
#define BND_INIT_H
#include "BaseCommand.h"
#include "LibraryData.hpp"
/**
 * @file Init.hpp
 * @brief Содержит объявление класса Init
 */

/**
 * @class Init
 * @brief Инициализирует библиотечные данные
 * @details Наследуется от класса BaseCommand и реализует методы checkAndAssemble(), run() и help().
 */
class Init : public BaseCommand {
private:
    LibraryData &libraryData;/**< Ссылка на данные библиотеки */
    uint16_t catAmount = 0;/**< Максимальное количество записей в каталоге*/
    uint16_t catOffset = 0;/**< Количество блоков данных*/

    /**
    * @brief Проверяет количество аргументов парсера
    * @param parser Объект, содержащий аргументы парсера
    * @return Пустая строка в случае успеха, сообщение об ошибке в случае неудачи
    */
    static std::string checkAmount(const Parser &parser);

    /**
    * @brief С помощью ключей парсера устанавливает значение максимального количества записей в каталоге
    * @param keys Объект, содержащий ключи парсера
    * @return Пустая строка в случае успеха, сообщение об ошибке в случае неудачи
    */
    std::string setCatalogAmount(const keyArgs_t &keys);

    /**
    * @brief С помощью ключей парсера устанавливает значение количества блоков данных
    * @param keys Объект, содержащий ключи парсера
    * @return Пустая строка в случае успеха, сообщение об ошибке в случае неудачи
    */
    std::string setCatalogOffset(const keyArgs_t &keys);
    static constexpr char NOT_ENOUGH_ARGS[] = "Not enough arguments (see INIT --help).";/**< Сообщение об ошибке из-за недостаточного количества аргументов */
    static constexpr char TOO_MANY_ARGS[] = "Too many arguments (see INIT --help)."; /**< Сообщение об ошибке для слишком большого количества аргументов */
    static constexpr char CATALOGAMOUNT_CANT_CONVERT[] = "Catalog Amount has incorrect format.";/**< Сообщение об ошибке для неправильного формата */
    static constexpr char CATALOGAMOUNT_RESTRICTED[] = "Catalog amount must be in range [1, 65535].";/**< ообщение об ошибке для длины вне допустимого диапазона */
    static constexpr char NO_CATALOGAMOUNT_VALUE[] = "Catalog amount can’t be empty.";/**< Сообщение об ошибке для пустого значения */
    static constexpr char CATALOGOFFSET_CANT_CONVERT[] = "Catalog offset has incorrect format.";/**< Сообщение об ошибке для неправильного формата длины */
    static constexpr char CATALOGOFFSET_RESTRICTED[] = "Catalog offset must be in range [1, 65535].";/**< ообщение об ошибке для длины вне допустимого диапазона */
    static constexpr char NO_CATALOGOFFSET_VALUE[] = "Catalog offset can’t be empty.";/**< Сообщение об ошибке для пустого значения */

public:

    /**
    * @brief Конструктор объекта Init
    * @param libraryData Ссылка на данные библиотеки
    */
    explicit Init(LibraryData &libraryData);

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
#endif //BND_INIT_H
