//
// Created by maksi on 13.06.2023.
//

#ifndef BND_CATALOGNOTFOUND_HPP
#define BND_CATALOGNOTFOUND_HPP
#include "IOException.hpp"
class CatalogNotFound : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Catalog with this name is absent!";
    }
};
#endif //BND_CATALOGNOTFOUND_HPP
