//
// Created by Makar on 10.05.2023.
//
#include <utility>

#include "Catalog.h"

#ifndef BND_PROJ_BND_H
#define BND_PROJ_BND_H

struct Error{
    string str;
};


class BND {
private:
    string Name;
    const string LB = "LB";
    unsigned short CatOffset = 0; // кол-во блоков, которое выделено для БНД (смещение до начала разделов БНД)
    unsigned short Catamount = 0; // кол-во разделов в БНД
    int *DataArea = nullptr;
    Catalog catalog;

    int lengthSpace(int k){
        int len = 0;
        do{
            len++;
            k++;
        }while(*(DataArea+k)==0);
        return len;
    }

    int findSpace(unsigned int need){
        int num = 0;
        for (int i=0; i<CatOffset; i++){
            if (*(DataArea+i)==0) num++;
        }
        if(num<need){
            return -1;
        }
        for (int i = 0; i<CatOffset; i++){
            if(*(DataArea+i)==0)
                if(lengthSpace(i)>=need) {
                    return i;
                }
        }

        int start = 0;
        reorganization();
        while(*(DataArea+start)!=0){
            start ++;
        }
        return start;
    }
public:
    BND(string name, unsigned short catOffset, unsigned short catamount) : Name(std::move(name)), CatOffset(catOffset), Catamount(catamount) {
        DataArea = new int[catOffset]{0};
    }
    BND(unsigned short catOffset, unsigned short catamount) : CatOffset(catOffset), Catamount(catamount) {
        DataArea = new int[catOffset]{0};
    }

    BND() = default;

    string getLb() const {
        return LB;
    }

    unsigned short getCatOffset() const {
        return CatOffset;
    }

    unsigned short getCatamount() const {
        return Catamount;
    }

    int *getDataArea() const {
        return DataArea;
    }

    const Catalog &getCatalog() const {
        return catalog;
    }

    void setCatOffset(unsigned short catOffset) {
        CatOffset = catOffset;
    }

    void setCatamount(unsigned short catamount) {
        Catamount = catamount;
    }

    void setName(const string &name) {
        Name = name;
    }

    static BND create(const string &name, unsigned short catamount, unsigned short dataamount){
        return {name, dataamount, catamount};
    }
    //для добавление нужна проверка на наличие свободного места в датаареа, возможность отформатировать пространство для добавления раздела
    void add(const string &catname, unsigned int length){
        if (DataArea == nullptr){
            throw Error("No space was specified");
        }
        if (catname.length()>10){
            throw Error("Name is too long");
        }
        char *name = new char[catname.length()];
        for(int i=0; i<catname.length(); i++){
            *(name+i) = catname[i];
        }
        int num = findSpace(length);
        if(num == -1){
            throw Error("There is not enough space");
        }else{
            for(int i = num; i<num+length; i++){
                *(DataArea+i)=BLOCK;
            }
            CatalogUnit newCatU(name, num, length);
        }
    }

    void reorganization(){

    }

};


#endif //BND_PROJ_BND_H
