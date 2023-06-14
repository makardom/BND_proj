//
// Created by maksi on 09.06.2023.
//
/**
 * @file LibraryDataNotInitializedException.hpp
 * @brief Определение класса LibraryDataNotInitializedException.
 *
 * Этот файл содержит определение класса LibraryDataNotInitializedException, производного от LibraryDataException.
 */
#ifndef BND_LIBRARYDATANOTINITIALIZEDEXCEPTION_HPP
#define BND_LIBRARYDATANOTINITIALIZEDEXCEPTION_HPP
#include "LibraryDataException.hpp"

/**
 * @class LibraryDataNotInitializedException
 * @brief Объявление класса LibraryDataCorruptedException.
 *
 * Это производный класс от класса LibraryDataException, представляющий случай, когда библиотечные данные не инициализированы.
 */
class LibraryDataNotInitializedException : public LibraryDataException {
public:

    /**
     * @brief Возвращает описание исключения.
     *
     * \return Строка, содержащая описание исключения.
     */
    [[nodiscard]] const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Library Data file not found. Please run init command.";
    }
};
#endif //BND_LIBRARYDATANOTINITIALIZEDEXCEPTION_HPP
