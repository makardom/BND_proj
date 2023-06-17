//
// Created by maksi on 04.06.2023.
//
/**
 * @file ISerializer.hpp
 * @brief Этот файл содержит объявление интерфейса ISerializer.
 *
 * Интерфейс ISerializer предоставляет методы для сохранения и загрузки  объектов в файл и из файла.
 */
#ifndef BND_PROJ_ISERIALIZER_HPP
#define BND_PROJ_ISERIALIZER_HPP

#include "LibraryData.hpp"

/**
 * @class ISerializer
 * @brief Интерфейс для сериализации и десериализации объектов в файл и из файла.
 */
class ISerializer {
public:

    /**
     * @brief Открывает файл с указанным именем.
     * @param filename Имя открываемого файла.
     */
    virtual void open(const std::string& filename) = 0;

    /**
     * @brief Создает новый файл с указанным именем файла..
     * @param filename Имя файла для создания.
     */
    virtual void create(const std::string& filename) = 0;

    /**
     * @brief Закрывает текущий открытый файл.
     */
    virtual void close() = 0;

    /**
     * @brief Возвращает true, если файл в данный момент открыт, иначе false.
     * @return значение true или false
     */
    virtual bool is_open() = 0;

    /**
     * @brief Сохраняет объект BND в текущий открытый файл.
     * @param bnd Объект для сохранения.
     */
    virtual void save(BND &bnd) = 0;

    /**
    * @brief Сохраняет объект CatalogUnit в текущий открытый файл с указанным смещением.
    * @param catalogUnit Объект для сохранения.
    * @param offset Смещение, по которому будет сохранен объект.
    */
    virtual void save(CatalogUnit &catalogUnit, off_t offset) = 0;

    /**
    * @brief Сохраняет объект Каталога в текущий открытый файл с указанным смещением.
    * @param catalog Объект для сохранения.
    * @param offset Смещение, по которому будет сохранен объект.
    */
    virtual void save(const Catalog &catalog, off_t offset) = 0;

    /**
    * @brief Загружает объект BND из открытого в данный момент файла.
    * @param bnd Объект для загрузки.
    */
    virtual void load(BND &bnd) = 0;

    /**
    * @brief Загружает объект CatalogUnit из текущего открытого файла по указанному смещению.
    * @param catalogUnit Объект для загрузки.
    * @param offset Смещение, с которого будет загружаться объект.
    */
    virtual void load(CatalogUnit &catalogUnit, off_t offset) = 0;

    /**
    * @brief Загружает объект Каталога из открытого в данный момент файла с указанным смещением и с указанным количеством записей.
    * @param catalog Объект для загрузки.
    * @param offset Смещение, с которого будет загружаться объект.
    * @param amount Количество CatalogUnits для загрузки.
    */
    virtual void load(Catalog &catalog, off_t offset, unsigned short amount) = 0;

    /**
    * @brief Деструктор по умолчанию.
    */
    virtual ~ISerializer() = default;
};
#endif //BND_PROJ_ISERIALIZER_HPP
