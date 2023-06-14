//
// Created by maksi on 09.06.2023.
//
/**
 * @file UnexpectedEndOfFileException.hpp
 *
 * @brief Определяет класс UnexpectedEndOfFileException.
 */
#ifndef BND_UNEXPECTEDENDOFFILEEXCEPTION_HPP
#define BND_UNEXPECTEDENDOFFILEEXCEPTION_HPP
#include "IOException.hpp"
/**
 * @class UnexpectedEndOfFileException
 * @brief Возникает исключение, когда невозможно реорганизовать DataArea
 */
class UnexpectedEndOfFileException : public IOException {
public:
    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Unexpected end of file.";
    }
};
#endif //BND_UNEXPECTEDENDOFFILEEXCEPTION_HPP
