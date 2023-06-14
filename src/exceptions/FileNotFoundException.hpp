//
// Created by maksi on 04.06.2023.
//
/**
 * @file FileNotFoundException.hpp
 *
 * @brief Определяет класс FileNotFoundException.
 */
#ifndef BND_PROJ_FILENOTFOUNDEXCEPTION_HPP
#define BND_PROJ_FILENOTFOUNDEXCEPTION_HPP
#include "IOException.hpp"
/**
 * \class FileNotFoundException
 * @brief Возникает исключение, когда файл не найден
 */
class FileNotFoundException : public IOException {
public:
    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "File not found.";
    }
};
#endif //BND_PROJ_FILENOTFOUNDEXCEPTION_HPP
