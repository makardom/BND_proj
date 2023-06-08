//
// Created by maksi on 08.06.2023.
//

#ifndef BND_PROJ_BNDIMPOSSIBLETOREORGANIZE_HPP
#define BND_PROJ_BNDIMPOSSIBLETOREORGANIZE_HPP
#include "IOException.hpp"
class BNDImpossibleToReorganize : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Impossible to reorganize DataArea!";
    }
};
#endif //BND_PROJ_BNDIMPOSSIBLETOREORGANIZE_HPP
