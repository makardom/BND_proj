//
// Created by maksi on 04.06.2023.
//
/**
 * @file FileCannotCreate.hpp
 *
 * @brief Определяет класс FileCannotCreate.
 */
#ifndef BND_PROJ_FILECANNOTCREATE_HPP
#define BND_PROJ_FILECANNOTCREATE_HPP
#include "IOException.hpp"

/**
 * @class FileCannotCreate
 * @brief Возникает исключение, когда невозможно реорганизовать DataArea
 */
class FileCannotCreate : public IOException {
public:

    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Cannot create file.";
    }
};
#endif //BND_PROJ_FILECANNOTCREATE_HPP
