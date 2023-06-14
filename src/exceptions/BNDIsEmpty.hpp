//
// Created by maksi on 13.06.2023.
//
/**
 * @file BNDIsEmpty.hpp
 *
 * @brief Определяет класс BNDIsEmpty.
 */
#ifndef BND_BNDISEMPTY_HPP
#define BND_BNDISEMPTY_HPP
#include "IOException.hpp"
/**
 * \class BNDIsEmpty

 * @brief Возникает исключение, когда БНД пустой
 */
class BNDIsEmpty : public IOException {
public:
    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "BND is empty!";
    }
};
#endif //BND_BNDISEMPTY_HPP
