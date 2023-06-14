//
// Created by maksi on 08.06.2023.
//
/**
 * @file CatalogNameTooLong.hpp
 *
 * @brief Определяет класс CatalogNameTooLong.
 */
#ifndef BND_PROJ_CATALOGNAMETOOLONG_HPP
#define BND_PROJ_CATALOGNAMETOOLONG_HPP
#include "IOException.hpp"

/**
 * @class CatalogNameTooLong
 * @brief Возникает исключение, когда имя каталога слишком длинное
 */
class CatalogNameTooLong : public IOException {
public:

    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Name is too long!";
    }
};
#endif //BND_PROJ_CATALOGNAMETOOLONG_HPP
