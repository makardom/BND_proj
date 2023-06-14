//
// Created by maksi on 13.06.2023.
//
/**
 * @file CatalogMemoryIsNotAllocated.hpp
 *
 * @brief Определяет класс CatalogMemoryIsNotAllocated.
 */
#ifndef BND_CATALODMEMORYISNOTALLOCATED_HPP
#define BND_CATALODMEMORYISNOTALLOCATED_HPP
#include "IOException.hpp"
/**
 * \class CatalogMemoryIsNotAllocated
 * @brief Возникает исключение, когда не выделена пямять под каталог
 */
class CatalogMemoryIsNotAllocated : public IOException {
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
#endif //BND_CATALODMEMORYISNOTALLOCATED_HPP
