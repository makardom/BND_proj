//
// Created by maksi on 09.06.2023.
//
/**
 * @file LibraryDataException.hpp
 *  @brief Определение класса LibraryDataException.
 *
 * Этот файл содержит определение класса LibraryDataException, производного от std::exception.
 */
#ifndef BND_LIBRARYDATAEXCEPTION_HPP
#define BND_LIBRARYDATAEXCEPTION_HPP
#include <exception>
/**
 * @class LibraryDataException
 * @brief Объявление класса LibraryDataException.
 *
 * Это производный класс от std::exception, представляющий любое исключение, которое может возникнуть в библиотечных данных.
 */
class LibraryDataException : public std::exception {

};
#endif //BND_LIBRARYDATAEXCEPTION_HPP
