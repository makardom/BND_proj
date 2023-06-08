//
// Created by maksi on 09.06.2023.
//

#ifndef BND_LIBRARYDATANOTINITIALIZEDEXCEPTION_HPP
#define BND_LIBRARYDATANOTINITIALIZEDEXCEPTION_HPP
#include "LibraryDataException.hpp"

class FilesystemNotInitializedException : public LibraryDataException {
public:
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Library Data file not found. Please run init command.";
    }
};
#endif //BND_LIBRARYDATANOTINITIALIZEDEXCEPTION_HPP
