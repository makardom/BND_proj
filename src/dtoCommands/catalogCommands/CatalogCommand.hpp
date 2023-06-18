//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGCOMMAND_HPP
#define BND_CATALOGCOMMAND_HPP

#include "dto/Catalog.h"
namespace CatalogNS {
    /**
    * @class CatalogCommand
    * @brief Доступ к командам класса Catalog
    * @details реализует метод execute().
    */
    class CatalogCommand {
    public:
        Catalog &catalog;/**< Ссылка на объект класса Catalog*/
        /**
        * @brief Конструктор класса CatalogCommand с параметрами
        * @param catalog Ссылка на объект класса Catalog
        */
        explicit CatalogCommand(Catalog &catalog);

        /**
        * @brief Объявление чисто виртуальной функции execute
        */
        virtual void execute() = 0;
        /**
        * @brief Конструктор класса CatalogCommand с параметрами
        */
        virtual ~CatalogCommand();
    };
}
#endif //BND_CATALOGCOMMAND_HPP
