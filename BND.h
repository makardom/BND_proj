//
// Created by Makar on 10.05.2023.
//
#include "DataUnit.h"
#include "Catalog.h"

#ifndef BND_PROJ_BND_H
#define BND_PROJ_BND_H


class BND {
private:
    unsigned short LB = 0;
    unsigned short CatOffset = 0;
    unsigned short Catamount = 0;
    DataUnit* DataArea = nullptr;
    Catalog catalog;
public:
    BND(unsigned short lb, unsigned short catOffset, unsigned short catamount) : LB(lb), CatOffset(catOffset), Catamount(catamount) {}

    BND() {}

    unsigned short getLb() const {
        return LB;
    }

    unsigned short getCatOffset() const {
        return CatOffset;
    }

    unsigned short getCatamount() const {
        return Catamount;
    }

    DataUnit *getDataArea() const {
        return DataArea;
    }

    const Catalog &getCatalog() const {
        return catalog;
    }

    void setLb(unsigned short lb) {
        LB = lb;
    }

    void setCatOffset(unsigned short catOffset) {
        CatOffset = catOffset;
    }

    void setCatamount(unsigned short catamount) {
        Catamount = catamount;
    }
};


#endif //BND_PROJ_BND_H
