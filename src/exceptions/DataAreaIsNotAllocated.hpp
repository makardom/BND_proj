//
// Created by maksi on 13.06.2023.
//

#ifndef BND_DATAAREAISNOTALLOCATED_HPP
#define BND_DATAAREAISNOTALLOCATED_HPP
#include "IOException.hpp"
class DataAreaIsNotAllocated : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Memory is not allocated!";
    }
};
#endif //BND_DATAAREAISNOTALLOCATED_HPP
