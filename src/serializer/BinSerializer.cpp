//
// Created by maksi on 04.06.2023.
//
#include "BinSerializer.hpp"
#include "../exceptions/FileNotFoundException.hpp"
#include "../exceptions/FileCannotCreate.hpp"
#include "../exceptions/FileWriteException.hpp"
#include "dtoCommands/Create.hpp"

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
    file.open(filename, std::ios::in | std::ios::out | std::ios::trunc|std::ios::binary);

    if (!file.is_open()) {
        throw FileCannotCreate();
    }
}
void BinSerializer::save(BND &bnd){
    file.seekp(0, std::ios::beg);
    file.write(reinterpret_cast<const char *>(bnd.getLb()), sizeof(char[2]));
    unsigned short catAmount = bnd.getCatamount();
    file.write(reinterpret_cast<const char *>(&catAmount), sizeof(unsigned short));
    unsigned short catOffset = bnd.getCatOffset();
    file.write(reinterpret_cast<const char *>(&catOffset), sizeof(unsigned short));
    unsigned short actualAmount = bnd.getCatalog().getSize();
    file.write(reinterpret_cast<const char *>(&actualAmount), sizeof(unsigned short));
    for(int i = 0; i < catOffset; i ++){
        int block = bnd.getDataArea()[i];
        file.write(reinterpret_cast<const char *>(&block), sizeof(int));
    }
    save(bnd.getCatalog(),  static_cast<off_t>(file.tellg()));
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
        save(catalogUnit, offset + static_cast<off_t>(sizeof(CatalogUnit) * static_cast<unsigned long long int>(i)));
        i++;
    }
}
void BinSerializer::load(BND &bnd){
    unsigned short catAmount;
    unsigned short catOffset;
    unsigned short actualAmount;
    file.seekg(sizeof(char[2]), std::ios::beg);
    file.read(reinterpret_cast<char *>(&catAmount), sizeof(unsigned short));
    file.read(reinterpret_cast<char *>(&catOffset), sizeof(unsigned short));
    file.read(reinterpret_cast<char *>(&actualAmount), sizeof(unsigned short));
    Create bndcreate(bnd, catAmount, catOffset);
    bndcreate.execute();
    for(int i = 0; i < catOffset; i++){
        int block;
        file.read(reinterpret_cast<char *>(&block), sizeof(int));
        bnd.getDataArea()[i] = block;
    }
    load(bnd.getCatalog(), static_cast<off_t> (BND_INFO_BLOCK_SIZE + static_cast<size_t> (BND_DATA_BLOCK_SIZE * catOffset)), actualAmount);
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
        CatalogUnit catalogUnit("error",99,99);
        load(catalogUnit, offset + static_cast<off_t> (sizeof(CatalogUnit) * static_cast<unsigned long long int>(i)));
        catalogs.push_back(catalogUnit);
    }
    catalog.setRecords(catalogs);
}