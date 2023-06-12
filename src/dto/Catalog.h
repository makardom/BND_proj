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
//    void print() {
//        for (int i = 0; i < size; i++) {
//            records[i].print();
//        }
//    }
//
//    void addRecord(CatalogUnit record) {
//        records.push_back(record);
//        size++;
//    }
//
//    CatalogUnit* searchRecordByName(const char* name) {
//        for (int i = 0; i < size; i++) {
//            if (strcmp(records[i].getName(), name) == 0) {
//                return &records[i];
//            }
//        }
//        return nullptr;
//    }
//
//    void makeNewMassive(){
//        if(size==0){
//            records.clear();
//        }else {
//            int i=0;
//            for(const auto & record : records){
//                if(record.getNameSize()==0){
//                    break;
//                }
//                i++;
//            }
//            records.erase(records.cbegin()+i);
//        }
//        copy(records.begin(), records.end(), records.begin());
//    }
//    void decSize(){
//        size--;
//    }
//
};


#endif //BND_PROJ_CATALOG_H
