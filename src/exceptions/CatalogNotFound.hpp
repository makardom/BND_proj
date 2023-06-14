//
// Created by maksi on 13.06.2023.
//
/**
 * @file CatalogNotFound.hpp
 *
 * @brief Определяет класс CatalogNotFound.
 */
#ifndef BND_CATALOGNOTFOUND_HPP
#define BND_CATALOGNOTFOUND_HPP
#include "IOException.hpp"
/**
 * @class CatalogNotFound
 * @brief Возникает исключение, когда не найден каталог
 */
class CatalogNotFound : public IOException {
public:
    /**
   * @brief Возвращает описательную строку исключения
   *
   * @return Строка, содержащая описание исключения
   */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Catalog with this name is absent!";
    }
};
#endif //BND_CATALOGNOTFOUND_HPP
