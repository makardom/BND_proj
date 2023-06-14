//
// Created by maksi on 09.06.2023.
//
/**
 * @file LibraryDataCorruptedException.hpp
 * @brief Определение класса LibraryDataCorruptedException.
 *
 * Этот файл содержит определение класса LibraryDataCorruptedException, производного от LibraryDataException.
 */

#ifndef BND_LIBRARYDATACORRUPTEDEXCEPTION_HPP
#define BND_LIBRARYDATACORRUPTEDEXCEPTION_HPP
#include "LibraryDataException.hpp"

/**
 * @class LibraryDataCorruptedException
 * @brief Объявление класса LibraryDataCorruptedException.
 *
 * Это производный класс от класса LibraryDataException, представляющий случай, когда файловая система повреждена.
 */
class LibraryDataCorruptedException : public LibraryDataException {
public:

    /**
     * @brief Возвращает описание исключения.
     *
     * \return Строка, содержащая описание исключения.
     */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Filesystem corrupted. Please run init command.";
    }
};
#endif //BND_LIBRARYDATACORRUPTEDEXCEPTION_HPP
