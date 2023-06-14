//
// Created by maksi on 09.06.2023.
//
/**
 * @file InvalidFileFormatException.hpp
 *
 * @brief Определяет класс InvalidFileFormatException.
 */
#ifndef BND_INVALIDFILEFORMATEXCEPTION_HPP
#define BND_INVALIDFILEFORMATEXCEPTION_HPP
#include "IOException.hpp"
/**
 * \class InvalidFileFormatException
 * @brief Возникает исключение, когда формат файла не правильный
 */
class InvalidFileFormatException : public IOException {
public:
    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Invalid file format.";
    }
};
#endif //BND_INVALIDFILEFORMATEXCEPTION_HPP
