//
// Created by maksi on 09.06.2023.
//

#ifndef BND_LIBRARYDATACORRUPTEDEXCEPTION_HPP
#define BND_LIBRARYDATACORRUPTEDEXCEPTION_HPP
#include "LibraryDataException.hpp"

class LibraryDataCorruptedException : public LibraryDataException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Filesystem corrupted. Please run init command.";
    }
};
#endif //BND_LIBRARYDATACORRUPTEDEXCEPTION_HPP
