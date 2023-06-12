//
// Created by maksi on 09.06.2023.
//

#ifndef BND_ADDRECORD_HPP
#define BND_ADDRECORD_HPP
#include "CatalogCommand.hpp"
namespace CatalogNS {
    class AddRecord : public CatalogCommand {
    private:
        CatalogUnit record;
    public:
        AddRecord(Catalog &catalog, CatalogUnit &catalogUnit);

        void execute() override;

        ~AddRecord() override;
    };
}
#endif //BND_ADDRECORD_HPP
