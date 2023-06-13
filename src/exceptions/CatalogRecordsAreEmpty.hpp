//
// Created by maksi on 13.06.2023.
//

#ifndef BND_CATALOGRECORDSAREEMPTY_HPP
#define BND_CATALOGRECORDSAREEMPTY_HPP
#include "IOException.hpp"
class CatalogRecordsAreEmpty : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "No catalogs!";
    }
};
#endif //BND_CATALOGRECORDSAREEMPTY_HPP
