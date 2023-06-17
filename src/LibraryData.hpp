//
// Created by maksi on 08.06.2023.
//
/**
 * @file LibraryData.hpp
 * @brief Этот файл содержит объявление класса 'LibraryData`.
 */
#ifndef BND_PROJ_LIBRARYDATA_HPP
#define BND_PROJ_LIBRARYDATA_HPP

#include "dto/BND.h"
#include "serializer/ISerializer.hpp"
/**
 * @brief объявляет класс с именем ISerializer. Этот класс не определен в представленном фрагменте.
 */
class ISerializer;
/**
 * @brief Класс обеспечивает работу библиотечного набора данных с монитором..
 */
class LibraryData{
public:
    ISerializer &serializer;/**< Сериализатор для работы с БНД */
    BND bnd;/**< БНД */
    bool isInit = false;/**< true сли инициализированб false если нет*/
public:

    /**
    * @brief Конструктор с параметром сериализатора.
    *
    * @param serializer Ссылка на сериализатор для БНД.
    */
    explicit LibraryData(ISerializer &serializer) : serializer(serializer), bnd() {}

    /**
     * @brief Конструктор копирования удален, чтобы предотвратить копирование объекта.
     */
    LibraryData(LibraryData &libraryData) = delete; // can't copy serializer and info about library data

    /**
     * @brief Перемещающий конструктор.
     *
     * @param LibraryData Объект для перемещения.
     */
    LibraryData(LibraryData &&libraryData) noexcept = default;

    /**
    * @brief Оператор присваивания копирования удален, чтобы предотвратить копирование объекта.
    */
    LibraryData &operator =(const LibraryData &libraryData) = delete; // can't copy serializer and info about library data

    /**
    * @brief Использует сериалайзер для открытия файла с указанным именем.
    * @param filename Имя открываемого файла.
    */
    void open(const std::string& filename);

    /**
     * @brief С помощью сериализатора закрывает текущий открытый файл.
     */
    void close();
};
#endif //BND_PROJ_LIBRARYDATA_HPP
