//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGDecSize_HPP
#define BND_CATALOGDecSize_HPP
#include "CatalogCommand.hpp"
namespace CatalogNS {
/**
 * @class DecSize
 * @brief Уменьшает размер каталога
 * @details Наследуется от класса CatalogCommand и реализует метод execute().
 */
class DecSize: CatalogCommand{
public:
    /**
    * @brief Конструктор класса DecSize с параметрами
    * @param catalog Ссылка на объект класса Catalog
    */
    explicit DecSize(Catalog &catalog);
    /**
    * @brief Объявление виртуальной функции
    */
    void execute() override;
    /**
    * @brief Деструктор класса DecSize
    */
    ~DecSize() override;
};
}
#endif //BND_CATALOGDecSize_HPP
