//
// Created by maksi on 08.06.2023.
//
/**
 * @file CatalogSpaceUnspecified.hpp
 *
 * @brief Определяет класс CatalogSpaceUnspecified.
 */
#ifndef BND_PROJ_CATALOGSPACEUNSPECIFIED_HPP
#define BND_PROJ_CATALOGSPACEUNSPECIFIED_HPP
#include "IOException.hpp"
/**
 * @class CatalogSpaceUnspecified
 * @brief Возникает исключение, когда каталог не инициализирован
 */
class CatalogSpaceUnspecified : public IOException {
public:
    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "No space was specified";
    }
};
#endif //BND_PROJ_CATALOGSPACEUNSPECIFIED_HPP
