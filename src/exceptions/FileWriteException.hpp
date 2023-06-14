//
// Created by maksi on 05.06.2023.
//
/**
 * @file FileWriteException.hpp
 *
 * @brief Определяет класс FileWriteException.
 */
#ifndef BND_PROJ_FILEWRITEEXCEPTION_HPP
#define BND_PROJ_FILEWRITEEXCEPTION_HPP
#include "IOException.hpp"
/**
 * @class FileWriteException
 * @brief Возникает исключение, когда невозможно записать в файл
 */
class FileWriteException : public IOException {
public:
    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Couldn't write to file.";
    }
};
#endif //BND_PROJ_FILEWRITEEXCEPTION_HPP
