//
// Created by maksi on 05.06.2023.
//

#ifndef BND_PROJ_FILEWRITEEXCEPTION_HPP
#define BND_PROJ_FILEWRITEEXCEPTION_HPP
#include "IOException.hpp"

class FileWriteException : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Couldn't write to file.";
    }
};
#endif //BND_PROJ_FILEWRITEEXCEPTION_HPP
