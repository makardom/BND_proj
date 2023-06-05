//
// Created by maksi on 04.06.2023.
//

#ifndef BND_PROJ_ISERIALIZER_HPP
#define BND_PROJ_ISERIALIZER_HPP

#include <string>
#include "../BND.h"

class ISerializer {
public:
    virtual void open(const std::string& filename) = 0;
    virtual void create(const std::string& filename) = 0;
    virtual void close() = 0;
    virtual bool is_open() = 0;

    virtual void save(BND &bnd) = 0;
    virtual void save(CatalogUnit &catalogUnit, off_t offset) = 0;
    virtual void save(const Catalog &catalog, off_t offset) = 0;

    virtual void load(BND &bnd) = 0;
    virtual void load(CatalogUnit &catalogUnit, off_t offset) = 0;
    virtual void load(Catalog &catalog, off_t offset, unsigned int amount) = 0;

    virtual ~ISerializer() = default;
};
#endif //BND_PROJ_ISERIALIZER_HPP
