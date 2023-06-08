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
//
//
//    void print(){
//        cout<<"LB"<<CatOffset<<Catamount<<" ";
//        for(int i=0; i<CatOffset; i++)
//            cout<<*(DataArea+i);
//        catalog.print();
//        cout<<endl;
//    }
//
//    void create(unsigned short catamount, unsigned short dataamount){
//        Catamount = catamount;
//        CatOffset = dataamount;
//        DataArea = new int[dataamount]{0};
//    }
//
//
//    //для добавление нужна проверка на наличие свободного места в датаареа, возможность отформатировать пространство для добавления раздела
//    void add(const string &catname, unsigned int length){
//        if(catalog.getSize() == Catamount){
//            throw CatalogSpaceFull();
//        }
//        if (DataArea == nullptr){
//            throw CatalogSpaceUnspecified();
//        }
//        if (catname.length()>10){
//            throw CatalogNameTooLong();
//        }
//        char *name = new char[catname.length()+1];
//        //char name[10]{'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'};
//        for(int i=0; i<catname.length(); i++){
//            *(name+i) = catname[i];
//            *(name+i+1) = '\0';
//        }
//        int num = findSpace(length);
//        if(num == -1){
//            throw BNDCannotAddDataInDataArea();
//        }else{
//            for(int i = num; i<num+length; i++){
//                *(DataArea+i)=BLOCK;
//            }
//            CatalogUnit newCatU(name, num, length);
//            catalog.addRecord(newCatU);
//        }
//    }
//
//
//
//    void reorganization(){
//        unsigned int offsets[catalog.getSize()];
//        unsigned int lengths = 0;
//        auto *records = new CatalogUnit[Catamount];
//        for (int i=0; i<catalog.getSize(); i++){
//            offsets[i] = catalog.getRecords()[i].getOffset();
//            lengths += catalog.getRecords()[i].getLength();
//        }
//        if(lengths==CatOffset)
//            throw BNDImpossibleToReorganize();
//        for(int i=0; i<CatOffset-lengths; i++) //обходим столько раз, сколько свободных ячеек в DataArea
//        {
//            int nol = 0;
//            while(*(DataArea+nol)!=0){
//                nol++;
//            }
//            while (nol<=CatOffset-2){
//                if(*(DataArea+nol+1)==1)
//                {
//                    int sec = checkSection(nol+1, offsets);
//                    if(sec!=-1) {
//                        catalog.getRecords()[sec].setOffset(nol);
//                        offsets[checkPosition(offsets, catalog.getSize(), nol + 1)] = nol;
//                    }
//                }
//                nol++;
//                switchData(nol-1, nol);
//            }
//        }
//
//    }
//
//    void Delete(){
//        Catamount = 0;
//        CatOffset = 0;
//        delete[] DataArea;
//        DataArea = nullptr;
//        int k = catalog.getSize();
//        for(int i=0; i<k; i++){
//            catalog.decSize();
//        }
//        catalog.getRecords().clear();
//    }
//
//    void renameCatalog(string oldname, string newname){
//        if (newname.length()>10){
//            throw CatalogNameTooLong();
//        }
//        if (oldname.length()>10){
//            throw CatalogNameTooLong();
//        }
//        char *oldname1 = new char[oldname.length()];
//        for(int i=0; i<oldname.length(); i++){
//            *(oldname1+i) = oldname[i];
//            *(oldname1+i+1) = '\0';
//        }
//        char *newname1 = new char[newname.length()];
//        for(int i=0; i<newname.length(); i++){
//            *(newname1+i) = newname[i];
//            *(newname1+i+1) = '\0';
//        }
//        catalog.searchRecordByName(oldname1)->setName(newname1);
//    }
//
//    void OutFreeSpace(){
//        int kol = 0;
//        for(int i=0; i<CatOffset; i++){
//            if (*(DataArea+i)==0)
//                kol++;
//        }
//        cout<<"Amount free space: "<<kol<<endl;
//    }
//
//    void printCatalog(){
//        catalog.print();
//        cout<<endl;
//    }
//
//    void OutSectionAlphabet(){
//        string names[catalog.getSize()];
//        for (int i=0; i<catalog.getSize(); i++){
//            names[i] = catalog.getRecords()[i].getName();
//        }
//        vector<string> namevec;
//        for(auto &i : names)
//            namevec.push_back(i);
//        sort(namevec.begin(), namevec.end());
//        for(auto &i : namevec)
//            cout<<i<<endl;
//    }
//    void DeleteSection(const string& SecName){
//        if (SecName.length()>10){
//            throw CatalogNameTooLong();
//        }
//        char *namesec = new char[SecName.length()];
//        //char namesec[10]{'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o', 'o'};
//        for(int i=0; i<SecName.length(); i++){
//            *(namesec+i) = SecName[i];
//            *(namesec+i+1) = '\0';
//        }
//        unsigned int start =  catalog.searchRecordByName(namesec)->getOffset();
//        unsigned int len =  catalog.searchRecordByName(namesec)->getLength();
//        for(unsigned int i=start; i<start+len; i++){
//            *(DataArea+i) = 0;
//        }
//        catalog.searchRecordByName(namesec)->DeleteThisUnit();
//        catalog.decSize(); catalog.makeNewMassive();
//    }
//private:
//    int lengthSpace(int k){
//        int len = 0;
//        do{
//            len++;
//            k++;
//        }while(*(DataArea+k)==0);
//        return len;
//    }
//
//    int findSpace(unsigned int need){
//        int num = 0;
//        for (int i=0; i<CatOffset; i++){
//            if (*(DataArea+i)==0) num++;
//        }
//        if(num<need){
//            return -1;
//        }
//
//        for (int i = 0; i<CatOffset; i++){
//            if(*(DataArea+i)==0)
//                if(lengthSpace(i)>=need) {
//                    return i;
//                }
//        }
//
//        return -1;
//    }
//
//    int checkSection(unsigned int a, const unsigned int *offsets) const{
//        for(int i=0; i<catalog.getSize(); i++){
//            if (a==offsets[i])
//                return i;
//        }
//        return -1;
//    }
//
//    void switchData(int a, int b){
//        auto tmp = DataArea[a];
//        DataArea[a] = DataArea[b];
//        DataArea[b] = tmp;
//    }
//
//    static int checkPosition(const unsigned int *offsets, int n, unsigned int need){
//        for(int i=0; i<n; i++){
//            if (offsets[i]==need){
//                return i;
//            }
//        }
//        return -1;
//    }
};


#endif //BND_PROJ_BND_H
