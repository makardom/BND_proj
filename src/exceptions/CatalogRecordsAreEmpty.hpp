//
// Created by maksi on 13.06.2023.
//
/**
 * @file CatalogRecordsAreEmpty.hpp
 *
 * @brief Определяет класс CatalogRecordsAreEmpty.
 */
#ifndef BND_CATALOGRECORDSAREEMPTY_HPP
#define BND_CATALOGRECORDSAREEMPTY_HPP
#include "IOException.hpp"

/**
 * @class CatalogRecordsAreEmpty
 * @brief Возникает исключение, когда в каталоге нет ни одной записи
 */
class CatalogRecordsAreEmpty : public IOException {
public:

    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "No catalogs!";
    }
};
#endif //BND_CATALOGRECORDSAREEMPTY_HPP
