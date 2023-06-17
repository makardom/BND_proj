//
// Created by Makar on 10.05.2023.
//
#include <utility>
#include <vector>
#include <algorithm>

#include "Catalog.h"
#include "exceptions/CatalogSpaceFull.hpp"
#include "exceptions/CatalogSpaceUnspecified.hpp"
#include "exceptions/CatalogNameTooLong.hpp"
#include "exceptions/BNDCannotAddDataInDataArea.hpp"
#include "exceptions/BNDImpossibleToReorganize.hpp"

#ifndef BND_PROJ_BND_H
#define BND_PROJ_BND_H

/**
 * @class BND
 * @brief Описывает Библиотечный набор данных
 * @details Реализует конструкторы, геттеры и сеттеры.
 */
class BND {
private:
    const char LB[2] = {'L', 'B'};/**< Два символа "L" и "B", означающие, что это БНД*/
    unsigned short CatOffset = 0; /**< Количество блоков, которое выделено для БНД (смещение до начала разделов БНД)*/
    unsigned short Catamount = 0; /**< Количество разделов в БНД*/
    int *DataArea = nullptr;/**< Указатель на массив данных (1 - память занята, 0 - свободна)*/
    Catalog catalog;/**< Набор разделов в БНД*/
public:
    /**
    * @brief Конструктор класса BND с параметрами
    * @param catOffset Смещение каталога
    * @param catamount Количество записей в каталоге
    */
    BND(unsigned short catOffset, unsigned short catamount) : CatOffset(catOffset), Catamount(catamount), catalog() {
        DataArea = new int[catOffset]{0};
    }

    /**
    * @brief Конструктор класса BND
    */
    BND(): catalog(){}

    /**
    * @brief Конструктор копирования класса BND
    * @param bnd Объект класса BND для копирования
    */
    BND(const BND & bnd): catalog(bnd.catalog){
        DataArea = new int[bnd.CatOffset];
        for(int i = 0; i < bnd.CatOffset; i++){
            DataArea[i] = bnd.DataArea[i];
        }
    }

    /**
    * @brief Оператор присваивания класса BND
    * @param bnd Объект класса BND для присваивания
    * @return Ссылку на текущий объект
    */
    BND &operator=(const BND& bnd){
        if(this == &bnd) return *this;
        this->CatOffset = bnd.CatOffset;
        this->Catamount = bnd.Catamount;
        this->catalog = bnd.catalog;
        DataArea = new int[bnd.CatOffset];
        for(int i = 0; i < bnd.CatOffset; i++){
            DataArea[i] = bnd.DataArea[i];
        }
    }

    /**
    * @brief Возвращает метку BND записи
    * @return Указатель на строку с меткой BND
    */
    [[nodiscard]] const char *getLb() const {
        return LB;
    }

    /**
    * @brief Возвращает смещение каталога
    * @return Смещение каталога
    */
    [[nodiscard]] unsigned short getCatOffset() const {
        return CatOffset;
    }

    /**
    * @brief Возвращает количество записей в каталоге
    * @return Количество записей в каталоге
    */
    [[nodiscard]] unsigned short getCatamount() const { // Library Fragmentation
        return Catamount;
    }

    /**
    * @brief Возвращает указатель на массив данных
    * @return Указатель на массив данных
    */
    [[nodiscard]] int *getDataArea() const {
        return DataArea;
    }

    /**
    * @brief Возвращает набор разделов
    * @return Константная ссылка на объект класса Catalog
    */
    [[nodiscard]] const Catalog &getCatalog() const {
        return catalog;
    }

    /**
    * @brief Возвращает набор разделов
    * @return Ссылка на объект класса Catalog
    */
    Catalog &getCatalog(){
        return catalog;
    }

    /**
    * @brief Устанавливает массив данных
    * @param dataArea Указатель на массив данных зоны данных
    */
    void setDataArea(int *dataArea) {
        DataArea = dataArea;
    }

    /**
    * @brief Устанавливает набор разделов
    * @param cat Ссылка на объект класса Catalog
    */
    void setCatalog(const Catalog &cat) {
        BND::catalog = cat;
    }

    /**
    * @brief Устанавливает смещение каталога
    * @param catOffset Смещение каталога
    */
    void setCatOffset(unsigned short catOffset) {
        CatOffset = catOffset;
    }

    /**
    * @brief Устанавливает количество разделов
    * @param catamount Количество разделов
    */
    void setCatamount(unsigned short catamount) {
        Catamount = catamount;
    }
};


#endif //BND_PROJ_BND_H
