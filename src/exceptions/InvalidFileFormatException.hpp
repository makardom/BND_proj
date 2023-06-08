//
// Created by maksi on 09.06.2023.
//

#ifndef BND_INVALIDFILEFORMATEXCEPTION_HPP
#define BND_INVALIDFILEFORMATEXCEPTION_HPP
#include "IOException.hpp"

class InvalidFileFormatException : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Invalid file format.";
    }
};
#endif //BND_INVALIDFILEFORMATEXCEPTION_HPP
