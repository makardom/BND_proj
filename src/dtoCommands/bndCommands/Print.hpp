//
// Created by maksi on 09.06.2023.
//

#ifndef BND_PRINT_HPP
#define BND_PRINT_HPP

#include "dto/BND.h"

namespace BNDNS {
    /**
    * @class Print
    * @brief Выводит БНД
    * @details реализует метод execute().
    */
    class Print {
    private:
        BND &bnd;/**< Объявление ссылки на объект класса BND*/
    public:
        /**
        * @brief Конструктор класса Print с параметрами
        * @param bnd Ссылка на объект класса BND
        */
        explicit Print(BND &bnd);
        /**
        * @brief Выполняет команду печати информации о БНД
        * @return Строка с информацией о файле .bn
        */
        std::string execute();
        /**
        * @brief Деструктор класса Print
        */
        ~Print();
    };
}
#endif //BND_PRINT_HPP
