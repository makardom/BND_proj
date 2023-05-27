//
// Created by Makar on 10.05.2023.
//
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#ifndef BND_PROJ_CATALOGUNIT_H
#define BND_PROJ_CATALOGUNIT_H


class CatalogUnit {
private:
    char name[10]{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
//    bool isMain;
    unsigned int offset;
    unsigned int length;

    static int getsize(const char * n){
        int size = 0;
        while(*n++) ++size;
        return size;
    }
public:
    CatalogUnit() {
        //strcpy(name, "");
//        isMain = false;
        offset = 0;
        length = 0;
    }

    CatalogUnit(const char* n, unsigned int o, unsigned int l) {
//        for(int i=0; i< getsize(n); i++){
//            name[i] = *(n+i);
//        }
        strcpy(name, n);
//        isMain = m;
        offset = o;
        length = l;
    }

    void setName(const char *n) {
//        for(int i=0; i< getsize(n); i++){
//            name[i] = *(n+i);
//        }
        strcpy(name, n);
    }

//    void setMain(bool m) {
//        isMain = m;
//    }

    void setOffset(int o) {
        offset = o;
    }

    void setLength(int l) {
        length = l;
    }

    const char* getName() {
        return name;
    }

//    bool isMainCatalog() const {
//        return isMain;
//    }

    unsigned int getOffset() const {
        return offset;
    }

    unsigned int getLength() const {
        return length;
    }

    void DeleteThisUnit(){
        for(char & i : name){
            i = '\0';
        }
        offset = 0;
        length = 0;
    }

    void print() {
        string dopname;
        for(char i : name){
            dopname.push_back(i);
        }
        cout <<dopname<< " " << offset << " " << length;
    }
};


#endif //BND_PROJ_CATALOGUNIT_H
