//
// Created by maksi on 13.06.2023.
//
/**
 * @file DataAreaIsNotAllocated.hpp
 *
 * @brief Определяет класс DataAreaIsNotAllocated.
 */
#ifndef BND_DATAAREAISNOTALLOCATED_HPP
#define BND_DATAAREAISNOTALLOCATED_HPP
#include "IOException.hpp"
/**
 * \class DataAreaIsNotAllocated
 * @brief Возникает исключение, когда не выделена пямять под DataArea
 */
class DataAreaIsNotAllocated : public IOException {
public:
    /**
    * @brief Возвращает описательную строку исключения
    *
    * @return Строка, содержащая описание исключения
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Memory is not allocated!";
    }
};
#endif //BND_DATAAREAISNOTALLOCATED_HPP
