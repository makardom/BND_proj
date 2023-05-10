//
// Created by Makar on 10.05.2023.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include "CatalogUnit.h"
using namespace std;

#ifndef BND_PROJ_CATALOG_H
#define BND_PROJ_CATALOG_H


class Catalog {
private:
    CatalogUnit* records;
    int size;
public:
    Catalog() {
        records = nullptr;
        size = 0;
    }

//    Catalog(const char* file_name) {
//        ifstream file(file_name, ios::binary);
//        if (!file) {
//            cerr << "Error: file not found" << endl;
//            records = nullptr;
//            size = 0;
//        } else {
//            file.seekg(0, ios::end);
//            int file_size = file.tellg();
//            size = file_size / 19;
//            records = new CatalogUnit[size];
//            file.seekg(0, ios::beg);
//            for (int i = 0; i < size; i++) {
//                char name[10];
//                file.read(name, 10);
//                bool isMain = false;
//                char isMainChar;
//                file.read(&isMainChar, 1);
//                if (isMainChar == '1') {
//                    isMain = true;
//                }
//                int offset;
//                file.read((char*)(&offset), 4);
//                int length;
//                file.read((char*)(&length), 4);
//                records[i].setName(name);
//                records[i].setMain(isMain);
//                records[i].setOffset(offset);
//                records[i].setLength(length);
//            }
//            file.close();
//        }
//    }

    ~Catalog() {
        delete[] records;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            records[i].print();
        }
    }

    void addRecord(CatalogUnit record) {
        auto* new_records = new CatalogUnit[size + 1];
        for (int i = 0; i < size; i++) {
            new_records[i] = records[i];
        }
        new_records[size] = record;
        delete[] records;
        records = new_records;
        size++;
    }

//    void saveToFile(const char* file_name) {
//        ofstream file(file_name, ios::binary);
//        for (int i = 0; i < size; i++) {
//            file.write(records[i].getName(), 10);
//            char is_main = records[i].isMainCatalog() ? '1' : '0';
//            file.write(&is_main, 1);
//            file.write((char*)((&records[i])->getOffset()), 4);
//            file.write((char*)((&records[i])->getLength()), 4);
//        }
//        file.close();
//    }

    CatalogUnit* searchRecordByName(const char* name) {
        for (int i = 0; i < size; i++) {
            if (strcmp(records[i].getName(), name) == 0) {
                return &records[i];
            }
        }
        return nullptr;
    }
};


#endif //BND_PROJ_CATALOG_H
