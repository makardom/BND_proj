//
// Created by maksi on 12.06.2023.
//

#ifndef BND_SEARCHRECORDBYNAME_HPP
#define BND_SEARCHRECORDBYNAME_HPP

#include "dto/Catalog.h"

namespace CatalogNS {
    class SearchRecordByName{
    private:
        Catalog &catalog;
        const char * name;
    public:
        SearchRecordByName(Catalog &catalog, const char * name);
        CatalogUnit * execute();
    };
}
#endif //BND_SEARCHRECORDBYNAME_HPP
