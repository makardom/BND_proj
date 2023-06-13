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

const int BLOCK = 1;
class Catalog {
private:
    std::vector<CatalogUnit> records;
    unsigned short size;
public:
    Catalog(): records(), size(0){}

    ~Catalog() {
        records.clear();
    }
    std::vector<CatalogUnit> &getRecords() {
        return records;
    }
    [[nodiscard]] const std::vector<CatalogUnit> &getRecords() const{
        return records;
    }

    [[nodiscard]] unsigned short getSize() const {
        return size;
    }


    void setRecords(const std::vector<CatalogUnit> &recordsV) {
        Catalog::records = recordsV;
    }

    void setSize(unsigned short sizeUS) {
        Catalog::size = sizeUS;
    }

};


#endif //BND_PROJ_CATALOG_H
