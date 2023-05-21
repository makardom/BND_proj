//
// Created by Makar on 10.05.2023.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include "CatalogUnit.h"
using namespace std;

const int BLOCK = 1;
//сделать сериализатор

#ifndef BND_PROJ_CATALOG_H
#define BND_PROJ_CATALOG_H


class Catalog {
private:
    CatalogUnit* records;
    unsigned short size;
public:
    Catalog() {
        records = nullptr;
        size = 0;
    }

    ~Catalog() {
        delete[] records;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            records[i].print();
        }
    }

    void addRecord(CatalogUnit record) {
        if(records!= nullptr) {
            auto *new_records = new CatalogUnit[size + 1];
            for (int i = 0; i < size; i++) {
                new_records[i] = records[i];
            }
            new_records[size] = record;
            delete[] records;
            records = new_records;
        }else{
            records = new CatalogUnit[1];
            records[0] = record;
        }
        size++;
    }

    CatalogUnit* searchRecordByName(const char* name) {
        for (int i = 0; i < size; i++) {
            if (strcmp(records[i].getName(), name) == 0) {
                return &records[i];
            }
        }
        return nullptr;
    }

    CatalogUnit *getRecords() const {
        return records;
    }

    unsigned short getSize() const {
        return size;
    }
};


#endif //BND_PROJ_CATALOG_H
