//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGUNIT_PRINT_HPP
#define BND_CATALOGUNIT_PRINT_HPP

#include "dto/CatalogUnit.h"

namespace CatalogUnitNS {
    /**
    * @class Print
    * @brief Выводит данные раздела
    * @details реализует метод execute().
    */
    class Print {
    private:
        CatalogUnit &catalogUnit;/**< Ссылка на объект класса CatalogUnit*/
    public:
        /**
        * @brief Конструктор класса Print с параметрами
        * @param catalog Ссылка на объект класса CatalogUnit
        */
        explicit Print(CatalogUnit &catalogUnit) : catalogUnit(catalogUnit){}

        /**
        * @brief Выполняет команду печати раздела
        * @return Строка с информацией о разделе
        */
        std::string execute(){
            string dopname;
            for (int i = 0; i < catalogUnit.getNameSize(); i++) {
                dopname.push_back(catalogUnit.getName()[i]);
            }
            std::string str;
            str = dopname + " " + to_string(catalogUnit.getOffset()) + " " + to_string(catalogUnit.getLength()) + " ";
            return str;
        }
        /**
        * @brief Деструктор класса Print
        */
        ~Print() = default;
    };
}
#endif //BND_CATALOGUNIT_PRINT_HPP
