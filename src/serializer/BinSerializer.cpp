//
// Created by maksi on 04.06.2023.
//
#include "BinSerializer.hpp"
#include "../exceptions/FileNotFoundException.hpp"
#include "../exceptions/FileCannotCreate.hpp"
#include "../exceptions/FileWriteException.hpp"

void BinSerializer::open(const std::string &filename) {
    file.open(filename);

    if (!file.is_open()) {
        throw FileNotFoundException();
    }
}

void BinSerializer::close() {
    file.close();
}


bool BinSerializer::is_open() {
    return file.is_open();
}

void BinSerializer::create(const std::string &filename) {
    file.open(filename, std::ios::in | std::ios::out | std::ios::trunc);

    if (!file.is_open()) {
        throw FileCannotCreate();
    }
}
void BinSerializer::save(BND &bnd){
    file.clear();
    file.seekp(0);
    file.write(reinterpret_cast<const char *>(bnd.getLb()), sizeof(char[2]));
    unsigned short catAmount = bnd.getCatamount();
    file.write(reinterpret_cast<const char *>(&catAmount), sizeof(unsigned short));
    unsigned short catOffset = bnd.getCatOffset();
    file.write(reinterpret_cast<const char *>(&catOffset), sizeof(unsigned short));
    for(int i = 0; i < catOffset; i ++){
        int block = bnd.getDataArea()[i];
        file.write(reinterpret_cast<const char *>(&block), sizeof(int));
    }
    save(bnd.getCatalog(),  static_cast<off_t>(file.tellg()));
    file.flush();
}
void BinSerializer::save(CatalogUnit &catalogUnit, off_t offset){
    file.seekp(offset, std::ios_base::beg);
    file.write(reinterpret_cast<const char *>(&catalogUnit), sizeof(CatalogUnit));

    if (file.bad()){
        throw FileWriteException();
    }
}
void BinSerializer::save(const Catalog &catalog, off_t offset){
    file.seekp(offset,std::ios_base::beg);
    int i = 0;
    for(CatalogUnit catalogUnit: catalog.getRecords()){
        save(catalogUnit, offset + (off_t)(sizeof(CatalogUnit) * i));
        i++;
    }
}
void BinSerializer::load(BND &bnd){
    bnd.Delete();
    unsigned short catAmount;
    unsigned short catOffset;
    file.seekg(sizeof(char[2]), std::ios::beg);
    file.read(reinterpret_cast<char *>(&catAmount), sizeof(unsigned short));
    file.read(reinterpret_cast<char *>(&catOffset), sizeof(unsigned short));
    bnd.create(catAmount, catOffset);
    for(int i = 0; i < catOffset; i++){
        int block;
        file.read(reinterpret_cast<char *>(&block), sizeof(int));
        bnd.getDataArea()[i] = block;
    }
    load(bnd.getCatalog(), (off_t)(BND_INFO_BLOCK_SIZE + (size_t)(BND_DATA_BLOCK_SIZE * catOffset)), catAmount);
}
void BinSerializer::load(CatalogUnit &catalogUnit, off_t offset){
    file.seekg(offset, std::ios_base::beg);
    file.read(reinterpret_cast<char *>(&catalogUnit), sizeof(CatalogUnit));
}
void BinSerializer::load(Catalog &catalog, off_t offset, unsigned short amount){
    vector<CatalogUnit> catalogs = catalog.getRecords();
    catalogs.clear();
    catalog.setSize(amount);
    for(int i = 0; i < amount; i++){
        CatalogUnit catalogUnit("d",1,2);
        load(catalogUnit, offset + (off_t)(sizeof(CatalogUnit) * i));
        catalogs.push_back(catalogUnit);
    }
    catalog.setRecords(catalogs);
}