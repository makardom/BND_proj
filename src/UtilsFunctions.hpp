//
// Created by maksi on 09.06.2023.
//

#ifndef BND_UTILSFUNCTIONS_HPP
#define BND_UTILSFUNCTIONS_HPP

#include <memory>
#include <sstream>
#include "Parser.h"
#include "commands/BNDCommands.hpp"

class UtilsFunctions{
public:
    static bool isASCII(const std::string &str){
        return !std::any_of(std::begin(str), std::end(str), [](const char character) -> bool {
            return character < 0;
        });
    }

    /**
     * Функция переводит строку в число
     * @tparam Num_t числовой тип в который происходит конвертация
     * @param strValue строка с числом
     * @param numberVar ссылка на переменную принимающую значение
     * @return true при возникновении ошибки конвертации, false otherwise
     */
    template<class Num_t>
    static bool convertToNumber(const std::string &strValue, Num_t& numberVar){
        try {
            std::size_t pos{};
            numberVar = std::stoi(strValue, &pos);
            if (pos != strValue.length()) {
                return true;
            }
        } catch (std::out_of_range const &ex) {
            return true;
        } catch (std::invalid_argument const &ex) {
            return true;
        }

        return false;
    }

    /**
     * Находит и устанавливает переменные лоигческого типа из переданного отображения в переданную ссылку переменной
     * @tparam Values переменной длины массив строковых значений ключей
     * @param args массив ключей
     * @param boolVar переменная для установки в нее логического значения
     * @param values строки для поиска ключей
     */
    template<class ...Values>
    static void findAndSetBoolArg(const posArgs_t &args, bool &boolVar, Values... values){
        if(std::find_if(std::begin(args), std::end(args), [&values...](const std::string &argGiven) -> bool {
            return std::any_of(std::begin({values...}), std::end({values...}), [&argGiven](const std::string &argNeeded) -> bool {
                return argGiven == argNeeded;
            });
        }) != std::end(args)){
            boolVar = true;
        } else{
            boolVar = false;
        }
    }

    /**
     * Подготавливает вывод команд к отображению на монитор. Убирает завершающий перевод строки.
     *
     * @param str исходный текст для вывода
     * @return текст для вывода без завершающего перевода строки
     */
    static std::string removeClosingEndl(std::string& str) {
        size_t len = str.length();
        if (str.at(len - 1) == '\n') {
            str.erase(len - 1);
        }
        return str;
    }

    /**
     * Конец рекурсии для кортежа команд, выводит завершающее сообщение справки.
     *
     * @tparam index Индекс класса команды в кортеже
     * @tparam Args Дополнительные аргументы, необходимые конструктору класса команды
     * @return Завершающая строка справочного сообщения
     */
    template<std::size_t index, class ...Args>
    static typename std::enable_if<index == std::tuple_size_v<BNDCommandsTuple>, std::string>::type
    forEachHelp([[maybe_unused]] Args... args){
        return "";
    }

    /**
     * Рекурсивно проходит по кортежу команд и выводит для них справку.
     *
     * @tparam index Индекс класса команды в кортеже
     * @tparam Args Дополнительные аргументы, необходимые конструктору класса команды
     * @return Собранная строка справочного сообщения
     */
    template<std::size_t index = 0, class ...Args>
    static typename std::enable_if<index < std::tuple_size_v<BNDCommandsTuple>, std::string>::type
    forEachHelp(Args... args){
        using CommandClass = std::tuple_element_t<index, BNDCommandsTuple>;

        std::stringstream str;

        auto command = std::make_shared<CommandClass>(args...);

        str << "    " << CommandClass::getQuery() << " - " << CommandClass::description() << std::endl
            << "        " << command->help() << std::endl
            << forEachHelp<index + 1>(args...);

        return str.str();
    }
    static unsigned int lengthSpace(BND &bnd, int k){
        unsigned int len = 0;
        do{
            len++;
            k++;
        }while(*(bnd.getDataArea()+k)==0);
        return len;
    }

    static int findSpace(BND &bnd, unsigned int need){
        unsigned int num = 0;
        for (int i=0; i<bnd.getCatOffset(); i++){
            if (*(bnd.getDataArea()+i)==0) num++;
        }
        if(num < need){
            return -1;
        }

        for (int i = 0; i<bnd.getCatOffset(); i++){
            if(*(bnd.getDataArea()+i)==0)
                if(lengthSpace(bnd, i) >= need) {
                    return i;
                }
        }

        return -1;
    }

    static int checkSection(BND &bnd, unsigned int a, const unsigned int *offsets){
        for(int i=0; i<bnd.getCatalog().getSize(); i++){
            if (a==offsets[i])
                return i;
        }
        return -1;
    }

    static void switchData(BND &bnd, int a, int b){
        auto tmp = bnd.getDataArea()[a];
        bnd.getDataArea()[a] = bnd.getDataArea()[b];
        bnd.getDataArea()[b] = tmp;
    }

    static int checkPosition(const unsigned int *offsets, int n, unsigned int need){
        for(int i=0; i<n; i++){
            if (offsets[i]==need){
                return i;
            }
        }
        return -1;
    }
    static std::string deleteFile(const std::string& filename){
        std::string str;
        if (remove(filename.c_str()) != 0) {
            str = "Error while removing!";
        } else {
            str = "File" + filename + " was deleted successfully";
        }
        return str;
    }
};
#endif //BND_UTILSFUNCTIONS_HPP
