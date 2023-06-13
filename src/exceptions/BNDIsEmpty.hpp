//
// Created by maksi on 13.06.2023.
//

#ifndef BND_BNDISEMPTY_HPP
#define BND_BNDISEMPTY_HPP
#include "IOException.hpp"
class BNDIsEmpty : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "BND is empty!";
    }
};
#endif //BND_BNDISEMPTY_HPP
