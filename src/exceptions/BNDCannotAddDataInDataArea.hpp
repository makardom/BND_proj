//
// Created by maksi on 08.06.2023.
//

#ifndef BND_PROJ_BNDCANNOTADDDATAINDATAAREA_HPP
#define BND_PROJ_BNDCANNOTADDDATAINDATAAREA_HPP
#include "IOException.hpp"
class BNDCannotAddDataInDataArea : public IOException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Can't add data in DataArea!";
    }
};
#endif //BND_PROJ_BNDCANNOTADDDATAINDATAAREA_HPP
