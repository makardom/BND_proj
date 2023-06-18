//
// Created by maksi on 09.06.2023.
//

#ifndef BND_DELETETHISUNIT_HPP
#define BND_DELETETHISUNIT_HPP
#include "CatalogUnitCommand.hpp"
namespace CatalogUnitNS {
    /**
    * @class DeleteThisUnit
    * @brief Удаляет раздел из каталога
    * @details Реализует метод execute().
    */
    class DeleteThisUnit{
    public:
        CatalogUnit *catalogUnit;/**< Указатель на объект класса CatalogUnit*/
        /**
        * @brief Конструктор класса DeleteThisUnit.
        * @param catalogUnit Указатель на объект класса CatalogUnit.
        */
        explicit DeleteThisUnit(CatalogUnit *catalogUnit): catalogUnit(catalogUnit) {}
        /**
        * @brief Метод для выполнения операции удаления каталожного блока.
        */
        void execute() const{
            char * name = new char[10]{'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
            catalogUnit->setName(name);
            catalogUnit->setOffset(0);
            catalogUnit->setLength(0);
        }
        /**
        * @brief Виртуальный деструктор класса DeleteThisUnit.
        */
        ~DeleteThisUnit() = default;
    };

#endif //BND_DELETETHISUNIT_HPP
}