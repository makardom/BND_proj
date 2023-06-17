//
// Created by Makar on 10.05.2023.
//
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#ifndef BND_PROJ_CATALOGUNIT_H
#define BND_PROJ_CATALOGUNIT_H
/**
 * @file CatalogUnit.h
 * @brief Содержит объявление класса catalogUnit
 */

/**
 * @class CatalogUnit
 * @brief Класс описывает один блок разделов
 * @details Реализует конструкторы, сеттеры и гетторы
 */

class CatalogUnit {
private:
    char name[10]{'0'};/**< Имя раздела*/
    unsigned int offset;/**< Смещение, указывающее на начало хранящихся данных*/
    unsigned int length;/**< Длина хранящихся данных*/

    /**
    * @brief Считает количество символов в массиве символов
    * @param n Указатель на символьный массив
    * @return Целое число, показывающее длину переденного символьного массива
    */
    static int getsize(const char * n){
        int size = 0;
        while(*n++) ++size;
        return size;
    }
public:
    /**
    * @brief Дефолтный конструктор объекта CatalogUnit
    */
    CatalogUnit(): offset(0), length(0){}

    /**
    * @brief Конструктор объекта CatalogUit
    * @param n Имя раздела
    * @param o Смещение данных
    * @param l Длина данных
    */
    CatalogUnit(const char* n, unsigned int o, unsigned int l): offset(o), length(l){
        for(int i=0; i< getsize(n); i++){
            name[i] = n[i];
        }
    }

    /**
    * @brief Устанавливает имя раздела
    * @param n Указатель на строку с именем
    */
    void setName(const char *n) {
        int size = getsize(name);
        for(int i=0; i< size; i++){
            name[i] = '\0';
        }
        if(getsize(n) != 0){
            for (int i = 0; i < getsize(n); i++) {
                name[i] = *(n + i);
            }
        }
    }

    /**
    * @brief Устанавливает смещение данных
    * @param o Число, показывающее смещение
    */
    void setOffset(unsigned int o) {
        offset = o;
    }
    /**
    * @brief Устанавливает длину данных
    * @param l Число, показывающее длину
    */
    void setLength(unsigned int l) {
        length = l;
    }

    /**
    * @brief Возвращает имя раздела
    * @return Указатель на строку с именем
    */
    char* getName() {
        return name;
    }

    /**
    * @brief Возвращает размер имени раздела
    * @return Размер строки с именем
    */
    [[nodiscard]] int getNameSize() const {
        return getsize(name);
    }

    /**
    * @brief Возвращает смещение данных
    * @return Смещение данных
    */
    [[nodiscard]] unsigned int getOffset() const {
        return offset;
    }

    /**
    * @brief Возвращает длину данных
    * @return Длина данных
    */
    [[nodiscard]] unsigned int getLength() const {
        return length;
    }

};


#endif //BND_PROJ_CATALOGUNIT_H
