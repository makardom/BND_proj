//
// Created by maksi on 12.06.2023.
//

#ifndef BND_SEARCHRECORDBYNAME_HPP
#define BND_SEARCHRECORDBYNAME_HPP

#include "dto/Catalog.h"

namespace CatalogNS {
    /**
    * @class SearchRecordByName
    * @brief Выполняет поиск записи в каталоге по заданному имени
    * @details Реализует методы execute().
    */
    class SearchRecordByName{
    private:
        Catalog &catalog;/**< Ссылка на объект класса Catalog*/
        const char * name;/**< Указатель на строку с именем*/
    public:
        /**
        * @brief Конструктор класса SearchRecordByName с параметрами
        * @param catalog Ссылка на объект класса Catalog
        * @param name Указатель на строку с именем для поиска в каталоге
        */
        SearchRecordByName(Catalog &catalog, const char * name);
        /**
        * @brief Выполняет команду поиска записи в каталоге по заданному имени
        * @return Указатель на объект класса CatalogUnit, если запись найдена, иначе nullptr
        */
        CatalogUnit * execute();
    };
}
#endif //BND_SEARCHRECORDBYNAME_HPP
