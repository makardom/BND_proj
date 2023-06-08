//
// Created by maksi on 09.06.2023.
//

#ifndef BND_UNEXPECTEDENDOFFILEEXCEPTION_HPP
#define BND_UNEXPECTEDENDOFFILEEXCEPTION_HPP
#include "IOException.hpp"

class UnexpectedEndOfFileException : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Unexpected end of file.";
    }
};
#endif //BND_UNEXPECTEDENDOFFILEEXCEPTION_HPP
