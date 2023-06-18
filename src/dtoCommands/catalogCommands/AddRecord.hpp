//
// Created by maksi on 09.06.2023.
//

#ifndef BND_ADDRECORD_HPP
#define BND_ADDRECORD_HPP
#include "CatalogCommand.hpp"
namespace CatalogNS {
    /**
    * @class AddRecord
    * @brief Добавляет запись в каталог
    * @details Наследуется от класса CatalogCommand и реализует метод execute().
    */
    class AddRecord : public CatalogCommand {
    private:
        CatalogUnit record;/**< Раздел БНД*/
    public:
        /**
        * @brief Декларация функции AddRecord для добавления записи в каталог
        * @param catalog Ссылка на объект класса Catalog
        * @param catalogUnit Ссылка на объект класса CatalogUnit
        */
        AddRecord(Catalog &catalog, CatalogUnit &catalogUnit);

        /**
        * @brief Объявление виртуальной функции
        */
        void execute() override;

        /**
        * @brief Деструктор класса AddRecord
        */
        ~AddRecord() override;
    };
}
#endif //BND_ADDRECORD_HPP
