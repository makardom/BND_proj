//
// Created by maksi on 04.06.2023.
//

#ifndef BND_PROJ_FILENOTFOUNDEXCEPTION_HPP
#define BND_PROJ_FILENOTFOUNDEXCEPTION_HPP
#include "IOException.hpp"

class FileNotFoundException : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "File not found.";
    }
};
#endif //BND_PROJ_FILENOTFOUNDEXCEPTION_HPP
