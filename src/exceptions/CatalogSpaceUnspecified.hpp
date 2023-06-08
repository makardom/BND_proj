//
// Created by maksi on 08.06.2023.
//

#ifndef BND_PROJ_CATALOGSPACEUNSPECIFIED_HPP
#define BND_PROJ_CATALOGSPACEUNSPECIFIED_HPP
#include "IOException.hpp"
class CatalogSpaceUnspecified : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "No space was specified";
    }
};
#endif //BND_PROJ_CATALOGSPACEUNSPECIFIED_HPP
