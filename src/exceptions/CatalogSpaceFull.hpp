//
// Created by maksi on 08.06.2023.
//
/**
 * @file CatalogSpaceFull.hpp
 *
 * @brief Определяет класс CatalogSpaceFull.
 */
#ifndef BND_PROJ_CATALOGSPACEFULL_HPP
#define BND_PROJ_CATALOGSPACEFULL_HPP
#include "IOException.hpp"
/**
 * @class CatalogSpaceFull
 * @brief Возникает исключение, когда каталог заполнен
 */
class CatalogSpaceFull : public IOException {
public:
    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Space for catalogs is full!";
    }
};
#endif //BND_PROJ_CATALOGSPACEFULL_HPP
