//
// Created by maksi on 09.06.2023.
//

#ifndef BND_CATALOGUNIT_PRINT_HPP
#define BND_CATALOGUNIT_PRINT_HPP

#include "dto/CatalogUnit.h"

namespace CatalogUnitNS {
    class Print {
    private:
        CatalogUnit &catalogUnit;
    public:
        explicit Print(CatalogUnit &catalogUnit) : catalogUnit(catalogUnit){}

        std::string execute(){
            string dopname;
            for (int i = 0; i < catalogUnit.getNameSize(); i++) {
                dopname.push_back(catalogUnit.getName()[i]);
            }
            std::string str;
            str = dopname + " " + to_string(catalogUnit.getOffset()) + " " + to_string(catalogUnit.getLength()) + " ";
            return str;
        }

        ~Print() = default;
    };
}
#endif //BND_CATALOGUNIT_PRINT_HPP
