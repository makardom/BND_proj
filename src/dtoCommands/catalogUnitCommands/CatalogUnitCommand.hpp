//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGUNITCOMMAND_HPP
#define BND_CATALOGUNITCOMMAND_HPP

#include "dto/CatalogUnit.h"
namespace CatalogUnitNS {
    /**
    * @brief Класс, описывающий команду для каталожного блока.
    *
    * Данный класс представляет собой абстрактный базовый класс для конкретных команд каталожного блока.
    * Каждый унаследованный от него класс должен реализовывать метод execute(), который будет выполнять конкретную
    * команду.
    */
    class CatalogUnitCommand {
    public:
        CatalogUnit catalogUnit;/**< Раздел каталога БНД*/

        /**
        * @brief Конструктор класса CatalogUnitCommand.
        * @param catalogUnit Ссылка на объект класса CatalogUnit.
        */
        explicit CatalogUnitCommand(CatalogUnit &catalogUnit): catalogUnit(catalogUnit) {}
        /**
        * @brief Объявление чисто виртуальной функции execute
        */
        virtual void execute() = 0;
        /**
        * @brief Виртуальный деструктор класса CatalogUnitCommand.
        * Освобождает выделенные ресурсы при удалении объекта класса CatalogUnitCommand.
        */
        virtual ~CatalogUnitCommand() = default;
    };
}
#endif //BND_CATALOGUNITCOMMAND_HPP
