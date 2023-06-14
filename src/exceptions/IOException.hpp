//
// Created by maksi on 04.06.2023.
//
/**
 * @file IOException.hpp
 * @brief Определение класса IOException.
 *
 * Этот файл содержит определение класса IOException, производного от std::exception.
 */
#ifndef BND_PROJ_IOEXCEPTION_HPP
#define BND_PROJ_IOEXCEPTION_HPP
#include <exception>

/**
 * @class IOException
 * @brief Базовый класс для всех исключений, связанных с вводом/выводом.
 *
 * Это производный класс от std::exception, представляющий любое исключение, связанное с вводом/выводом
 */
class IOException : public std::exception {

};
#endif //BND_PROJ_IOEXCEPTION_HPP
