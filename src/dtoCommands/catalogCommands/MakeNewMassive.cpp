//
// Created by maksi on 09.06.2023.
//
#include "MakeNewMassive.hpp"
#include "Print.hpp"
#include "dtoCommands/catalogUnitCommands/Print.hpp"

namespace CatalogNS {
    MakeNewMassive::MakeNewMassive(Catalog &catalog) : CatalogCommand(catalog) {}

    void MakeNewMassive::execute() {
        //это я добавил
        cout<<CatalogNS::Print(catalog).execute();
        cout<<"\nsize = "<<catalog.getSize()<<endl;
        for(CatalogUnit catalogUnit: catalog.getRecords()) {
            cout<<CatalogUnitNS::Print(catalogUnit).execute()<<" ";
        }
        //вот до сюда, там получается что из вектора элемент не удалился
        if (catalog.getSize() == 0) {
            catalog.getRecords().clear();
        } else {
            int i = 0;
            for (const auto &record: catalog.getRecords()) {
                if (record.getNameSize() == 0) {
                    break;
                }
                i++;
            }
            catalog.getRecords().erase(catalog.getRecords().cbegin() + i);
        }
        copy(catalog.getRecords().begin(), catalog.getRecords().end(), catalog.getRecords().begin());
    }


    MakeNewMassive::~MakeNewMassive() = default;
}