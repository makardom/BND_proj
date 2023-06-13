//
// Created by maksi on 13.06.2023.
//

#ifndef BND_CATALODMEMORYISNOTALLOCATED_HPP
#define BND_CATALODMEMORYISNOTALLOCATED_HPP
#include "IOException.hpp"
class CatalogMemoryIsNotAllocated : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Memory is not allocated!";
    }
};
#endif //BND_CATALODMEMORYISNOTALLOCATED_HPP
