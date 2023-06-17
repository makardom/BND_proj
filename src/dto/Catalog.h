//
// Created by Makar on 10.05.2023.
//

#ifndef BND_PROJ_CATALOG_H
#define BND_PROJ_CATALOG_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "CatalogUnit.h"
using namespace std;

const int BLOCK = 1;/**< Глобальная переменная, выражающая размер блока данных*/

/**
 * @class Catalog
 * @brief Содержит данные всех разделов БНД
 * @details Реализует конструктор, деструктор, геттеры и сетторы
 */
class Catalog {
private:
    std::vector<CatalogUnit> records;/**< Вестор, хранящий разделы*/
    unsigned short size; /**< Значение, показывающее количество заполненных разделов*/
public:
    /**
    * @brief Конструктор класса Catalog без параметров
    */
    Catalog(): records(), size(0){}

    /**
    * @brief Деструктор класса Catalog
    */
    ~Catalog() {
        records.clear();
    }

    /**
    * @brief Получает записи каталога
    * @return Ссылка на вектор записей каталога
    */
    std::vector<CatalogUnit> &getRecords() {
        return records;
    }

    /**
    * @brief Получает записи каталога
    * @return Константная ссылка на вектор записей каталога
    */
    [[nodiscard]] const std::vector<CatalogUnit> &getRecords() const{
        return records;
    }

    /**
    * @brief Возвращает размер каталога
    * @return Размер каталога
    */
    [[nodiscard]] unsigned short getSize() const {
        return size;
    }

    /**
    * @brief Устанавливает записи каталога
    * @param recordsV Ссылка на вектор записей каталога
    */
    void setRecords(const std::vector<CatalogUnit> &recordsV) {
        Catalog::records = recordsV;
    }

    /**
    * @brief Устанавливает размер каталога
    * @param sizeUS Размер каталога
    */
    void setSize(unsigned short sizeUS) {
        Catalog::size = sizeUS;
    }

};


#endif //BND_PROJ_CATALOG_H
