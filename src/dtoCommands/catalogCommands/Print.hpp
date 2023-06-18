//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGPRINT_HPP
#define BND_CATALOGPRINT_HPP

#include "dto/Catalog.h"

namespace CatalogNS {
    /**
    * @class Print
    * @brief Выводит разделы БНД
    * @details реализует метод execute().
    */
    class Print {
    private:
        Catalog &catalog;/**< Ссылка на объект класса Catalog*/
    public:
        /**
        * @brief Конструктор класса Print с параметрами
        * @param catalog Ссылка на объект класса Catalog
        */
        explicit Print(Catalog &catalog);
        /**
        * @brief Выполняет команду печати каталога
        * @return Строка с информацией о каталоге
        */
        std::string execute();
        /**
        * @brief Деструктор класса Print
        */
        ~Print();
    };
}
#endif //BND_CATALOGPRINT_HPP
