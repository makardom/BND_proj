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
    char name[10]{};
    bool isMain;
    int offset;
    int length;
public:
    CatalogUnit() {
        strcpy(name, "");
        isMain = false;
        offset = 0;
        length = 0;
    }

    CatalogUnit(const char* n, bool m, int o, int l) {
        strcpy(name, n);
        isMain = m;
        offset = o;
        length = l;
    }

    void setName(const char* n) {
        strcpy(name, n);
    }

    void setMain(bool m) {
        isMain = m;
    }

    void setOffset(int o) {
        offset = o;
    }

    void setLength(int l) {
        length = l;
    }

    const char* getName() {
        return name;
    }

    bool isMainCatalog() const {
        return isMain;
    }

    int getOffset() const {
        return offset;
    }

    int getLength() const {
        return length;
    }

    void print() {
        cout << name << " " << isMain << " " << offset << " " << length << endl;
    }
};


#endif //BND_PROJ_CATALOGUNIT_H
