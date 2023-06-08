//
// Created by maksi on 08.06.2023.
//

#ifndef BND_PROJ_CATALOGSPACEFULL_HPP
#define BND_PROJ_CATALOGSPACEFULL_HPP
#include "IOException.hpp"
class CatalogSpaceFull : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Space for catalogs is full!";
    }
};
#endif //BND_PROJ_CATALOGSPACEFULL_HPP
