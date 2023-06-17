//
// Created by maksi on 12.06.2023.
//

#ifndef BND_ADD_HPP
#define BND_ADD_HPP
#include "BaseCommand.h"
#include "LibraryData.hpp"
/**
 * @file Add.hpp
 * @brief Содержит объявление класса Add
 */

/**
 * @class Add
 * @brief Добавляет запись в каталог
 * @details Наследуется от класса BaseCommand и реализует методы checkAndAssemble(), run() и help().
 */
class Add : public BaseCommand {
private:
    LibraryData &libraryData;/**< Ссылка на данные библиотеки */
    uint16_t length = 0; /**< Длина размера данных в блоках*/
    string name; /** Название записи каталога */

    /**
    * @brief Проверяет количество аргументов парсера
    * @param parser Объект, содержащий аргументы парсера
    * @return Пустая строка в случае успеха, сообщение об ошибке в случае неудачи
    */
    static std::string checkAmount(const Parser &parser);

    /**
    * @brief С помощью ключей парсера устанавливает значение длины
    * @param keys Объект, содержащий ключи парсера
    * @return Пустая строка в случае успеха, сообщение об ошибке в случае неудачи
    */
    std::string setLength(const keyArgs_t &keys);

    /**
    * @brief С помощью ключей парсера устанавливает значение имени
    * @param keys Объект, содержащий ключи парсера
    * @return Пустая строка в случае успеха, сообщение об ошибке в случае неудачи
    */
    std::string setName(const keyArgs_t &keys);
    static constexpr char NOT_ENOUGH_ARGS[] = "Not enough arguments (see INIT --help).";/**< Сообщение об ошибке из-за недостаточного количества аргументов */
    static constexpr char TOO_MANY_ARGS[] = "Too many arguments (see INIT --help)."; /**< Сообщение об ошибке для слишком большого количества аргументов */
    static constexpr char LENGTH_CANT_CONVERT[] = "Length has incorrect format."; /**< Сообщение об ошибке для неправильного формата длины */
    static constexpr char LENGTH_RESTRICTED[] = "Length must be in range [1, 65535]."; /**< Сообщение об ошибке для длины вне допустимого диапазона */
    static constexpr char NO_LENGTH_VALUE[] = "length can’t be empty."; /**< Сообщение об ошибке для пустой длины */
    static constexpr char NO_NAME_VALUE[] = "name can’t be empty.";/**<Сообщение об ошибке для пустого имени */
    static constexpr char NAME_TOO_LONG[] = "The name is too long (maximum 10 chars)."; /**< Сообщение об ошибке слишком длинном имени */
    static constexpr char NAME_INCORRECT[] = "Name has incorrect format."; /**< Сообщение об ошибке из-за неправильного формата имени */

public:

    /**
    * @brief Конструктор объекта Add
    * @param libraryData Ссылка на данные библиотеки
    */
    explicit Add(LibraryData &libraryData);

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
#endif //BND_ADD_HPP
