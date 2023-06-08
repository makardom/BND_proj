//
// Created by maksi on 08.06.2023.
//

#ifndef BND_PROJ_CATALOGNAMETOOLONG_HPP
#define BND_PROJ_CATALOGNAMETOOLONG_HPP
#include "IOException.hpp"
class CatalogNameTooLong : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Name is too long!";
    }
};
#endif //BND_PROJ_CATALOGNAMETOOLONG_HPP
