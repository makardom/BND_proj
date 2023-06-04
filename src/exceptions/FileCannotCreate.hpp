//
// Created by maksi on 04.06.2023.
//

#ifndef BND_PROJ_FILECANNOTCREATE_HPP
#define BND_PROJ_FILECANNOTCREATE_HPP
#include "IOException.hpp"

class FileCannotCreate : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Cannot create file.";
    }
};
#endif //BND_PROJ_FILECANNOTCREATE_HPP
