//
// Created by maksi on 08.06.2023.
//
/**
 * @file BNDCannotAddDataInDataArea.hpp
 */
#ifndef BND_PROJ_BNDCANNOTADDDATAINDATAAREA_HPP
#define BND_PROJ_BNDCANNOTADDDATAINDATAAREA_HPP
#include "IOException.hpp"
/**
 * @class BNDCannotAddDataInDataArea
 * @brief Возникает исключение, когда невозможно добавить данные в область данных.
 */
class BNDCannotAddDataInDataArea : public IOException {
public:
    /**
    * @brief Возвращает поясняющую строку.
    * @return Возвращающая строка.
    */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Can't add data in DataArea!";
    }
};
#endif //BND_PROJ_BNDCANNOTADDDATAINDATAAREA_HPP
