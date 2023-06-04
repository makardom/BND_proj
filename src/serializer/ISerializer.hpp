//
// Created by maksi on 04.06.2023.
//

#ifndef BND_PROJ_ISERIALIZER_HPP
#define BND_PROJ_ISERIALIZER_HPP

#include <string>

class ISerializer {
public:
    virtual void open(const std::string& filename) = 0;
    virtual void create(const std::string& filename) = 0;
    virtual void close() = 0;

    virtual bool is_open() = 0;

    virtual ~ISerializer() = default;
};
#endif //BND_PROJ_ISERIALIZER_HPP
