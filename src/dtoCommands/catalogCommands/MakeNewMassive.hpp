//
// Created by maksi on 09.06.2023.
//

#ifndef BND_MAKENEWMASSIVE_HPP
#define BND_MAKENEWMASSIVE_HPP
#include "CatalogCommand.hpp"
namespace CatalogNS {
    /**
    * @class MakeNewMassive
    * @brief Перераспределяет массив разделов после удаления одного из разделов
    * @details Наследуется от класса CatalogCommand и реализует метод execute().
    */
    class MakeNewMassive : CatalogCommand {
    public:
        /**
        * @brief Конструктор класса MakeNewMassive с параметрами
        * @param catalog Ссылка на объект класса Catalog
        */
        explicit MakeNewMassive(Catalog &catalog);
        /**
        * @brief Объявление виртуальной функции
        */
        void execute() override;
        /**
        * @brief Деструктор класса MakeNewMassive
        */
        ~MakeNewMassive() override;
    };
}
#endif //BND_MAKENEWMASSIVE_HPP
