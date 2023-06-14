//
// Created by maksi on 08.06.2023.
//
/**
 * @file BNDImpossibleToReorganize.hpp
 *
 * @brief Определяет класс BNDImpossibleToReorganize.
 */
#ifndef BND_PROJ_BNDIMPOSSIBLETOREORGANIZE_HPP
#define BND_PROJ_BNDIMPOSSIBLETOREORGANIZE_HPP
#include "IOException.hpp"

/**
 * @class BNDImpossibleToReorganize
 * @brief Возникает исключение, когда невозможно реорганизовать DataArea
 */
class BNDImpossibleToReorganize : public IOException {
public:

    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Impossible to reorganize DataArea!";
    }
};
#endif //BND_PROJ_BNDIMPOSSIBLETOREORGANIZE_HPP
