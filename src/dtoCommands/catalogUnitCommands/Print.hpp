//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CatalogUnitPRINT_HPP
#define BND_CatalogUnitPRINT_HPP
#include "CatalogUnitCommand.hpp"
namespace CatalogUnitNS {
    class Print : CatalogUnitCommand {
    public:
        explicit Print(CatalogUnit &catalogUnit) : CatalogUnitCommand(catalogUnit) {}

        void execute() override{
            string dopname;
            for (int i = 0; i < catalogUnit.getNameSize(); i++) {
                dopname.push_back(catalogUnit.getName()[i]);
            }
            cout << dopname << " " << catalogUnit.getOffset() << " " << catalogUnit.getLength() << " ";
        }

        ~Print() override = default;
    };

#endif //BND_CatalogUnitPRINT_HPP
}