//
// Created by maksi on 04.06.2023.
//
/**
 * @file BinSerializer.hpp
 * @brief Этот файл содержит объявление класса 'BinSerializer`.
 */
#ifndef BND_PROJ_BINSERIALIZER_HPP
#define BND_PROJ_BINSERIALIZER_HPP

#include <fstream>
#include "serializer/ISerializer.hpp"

/**
 * @brief Класс для сериализации объектов в двоичные файлы.
 *
 * Наследуется от класса `ISerializer`. Реализует все методы, определенные в базовом классе.
 */
class BinSerializer : public ISerializer{
private:
    std::fstream file; /**< Файловый объект для обработки двоичных файлов. */
    static constexpr size_t BND_INFO_BLOCK_SIZE = 8; /**< Постоянный размер информационного блока BND. */
    static constexpr size_t BND_DATA_BLOCK_SIZE = 4; /**< Константа, определяющая размер блока данных BND. */
public:

    /**
     * @brief Конструктор по умолчанию.
     */
    BinSerializer() : file() {}

    /**
    * @brief Конструктор с параметром имени файла.
    *
    * @param filename Имя открываемого файла.
    */
    explicit BinSerializer(const std::string &filename) : file(filename) {}

    /**
     * @brief Конструктор копирования удален, чтобы предотвратить копирование объекта.
     */
    BinSerializer(BinSerializer &binSerializer) = delete;

    /**
     * @brief Перемещающий конструктор.
     *
     * @param binSerializer Объект для перемещения.
     */
    BinSerializer(BinSerializer &&binSerializer) noexcept : file() {
        file = std::move(binSerializer.file);
    }

    /**
    * @brief Оператор присваивания копирования удален, чтобы предотвратить копирование объекта.
    */
    BinSerializer &operator =(const BinSerializer &filesystem) = delete;

    /**
     * @brief Оператор присваивания перемещения.
     *
     * @param binSerializer Объект для перемещения.
     * @return Ссылка на объект BinSerializer.
     */
    BinSerializer &operator =(BinSerializer &&binSerializer) noexcept {
        file = std::move(binSerializer.file);
        return *this;
    }

    /**
    * @brief Открывает файл с указанным именем.
    * Переопределяет функцию из базового класса.
    * @param filename Имя открываемого файла.
    */
    void open(const std::string& filename) override;

    /**
     * @brief Создает новый файл с указанным именем файла.
     * Переопределяет функцию из базового класса.
     * @param filename Имя файла для создания.
     */
    void create(const std::string &filename) override;

    /**
     * @brief Закрывает текущий открытый файл.
     * Переопределяет функцию из базового класса.
     */
    void close() override;

    /**
     * @brief Сохраняет объект BND в текущий открытый файл.
     * Переопределяет функцию из базового класса.
     * @param bnd Объект для сохранения.
     */
    void save(BND &bnd) override;

    /**
    * @brief Сохраняет объект CatalogUnit в текущий открытый файл с указанным смещением.
    * Переопределяет функцию из базового класса.
    * @param catalogUnit Объект для сохранения.
    * @param offset Смещение, по которому будет сохранен объект.
    */
    void save(CatalogUnit &catalogUnit, off_t offset) override;

    /**
    * @brief Сохраняет объект Каталога в текущий открытый файл с указанным смещением.
    * Переопределяет функцию из базового класса.
    * @param catalog Объект для сохранения.
    * @param offset Смещение, по которому будет сохранен объект.
    */
    void save(const Catalog &catalog, off_t offset) override;

    /**
    * @brief Загружает объект BND из открытого в данный момент файла.
    * Переопределяет функцию из базового класса.
    * @param bnd Объект для загрузки.
    */
    void load(BND &bnd) override;

    /**
    * @brief Загружает объект CatalogUnit из текущего открытого файла по указанному смещению.
    * Переопределяет функцию из базового класса.
    * @param catalogUnit Объект для загрузки.
    * @param offset Смещение, с которого будет загружаться объект.
    */
    void load(CatalogUnit &catalogUnit, off_t offset) override;

    /**
    * @brief Загружает объект Каталога из открытого в данный момент файла с указанным смещением и с указанным количеством записей.
    * Переопределяет функцию из базового класса.
    * @param catalog Объект для загрузки.
    * @param offset Смещение, с которого будет загружаться объект.
    * @param amount Количество CatalogUnits для загрузки.
    */
    void load(Catalog &catalog, off_t offset, unsigned short amount) override;

    /**
     * @brief Возвращает true, если файл в данный момент открыт, иначе false.
     * Переопределяет функцию из базового класса.
     * @return значение true или false
     */
    bool is_open() override;
};

#endif //BND_PROJ_BINSERIALIZER_HPP
