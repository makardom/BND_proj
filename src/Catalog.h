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
    vector<CatalogUnit> records;
    unsigned short size;
public:
    Catalog() {
        size = 0;
    }

    ~Catalog() {
        records.clear();
    }

    void print() {
        for (int i = 0; i < size; i++) {
            records[i].print();
        }
    }

    void addRecord(CatalogUnit record) {
        records.push_back(record);
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

    void makeNewMassive(){
        if(size==0){
            records.clear();
        }else {
            int i=0;
            for(const auto & record : records){
                if(record.getNameSize()==0){
                    break;
                }
                i++;
            }
            records.erase(records.cbegin()+i);
        }
        copy(records.begin(), records.end(), records.begin());
    }

    vector<CatalogUnit> &getRecords() {
        return records;
    }
    const vector<CatalogUnit> &getRecords() const{
        return records;
    }

    unsigned short getSize() const {
        return size;
    }

    void decSize(){
        size--;
    }

    void setRecords(const vector<CatalogUnit> &records) {
        Catalog::records = records;
    }

    void setSize(unsigned short size) {
        Catalog::size = size;
    }
};


#endif //BND_PROJ_CATALOG_H
