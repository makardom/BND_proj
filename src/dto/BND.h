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

class BND {
private:
    const char LB[2] = {'L', 'B'};
    unsigned short CatOffset = 0; // кол-во блоков, которое выделено для БНД (смещение до начала разделов БНД)
    unsigned short Catamount = 0; // кол-во разделов в БНД
    int *DataArea = nullptr;
    Catalog catalog;
public:
    BND(unsigned short catOffset, unsigned short catamount) : CatOffset(catOffset), Catamount(catamount), catalog() {
        DataArea = new int[catOffset]{0};
    }

    BND(): catalog(){}
    BND(const BND & bnd): catalog(bnd.catalog){
        DataArea = new int[bnd.CatOffset];
        for(int i = 0; i < bnd.CatOffset; i++){
            DataArea[i] = bnd.DataArea[i];
        }
    }
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
    [[nodiscard]] const char *getLb() const {
        return LB;
    }

    [[nodiscard]] unsigned short getCatOffset() const {
        return CatOffset;
    }

    [[nodiscard]] unsigned short getCatamount() const { // Library Fragmentation
        return Catamount;
    }

    [[nodiscard]] int *getDataArea() const {
        return DataArea;
    }

    [[nodiscard]] const Catalog &getCatalog() const {
        return catalog;
    }
    Catalog &getCatalog(){
        return catalog;
    }
    void setDataArea(int *dataArea) {
        DataArea = dataArea;
    }

    void setCatalog(const Catalog &cat) {
        BND::catalog = cat;
    }
    void setCatOffset(unsigned short catOffset) {
        CatOffset = catOffset;
    }

    void setCatamount(unsigned short catamount) {
        Catamount = catamount;
    }
};


#endif //BND_PROJ_BND_H
