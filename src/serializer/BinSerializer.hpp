//
// Created by maksi on 04.06.2023.
//

#ifndef BND_PROJ_BINSERIALIZER_HPP
#define BND_PROJ_BINSERIALIZER_HPP

#include <fstream>
#include <rpcndr.h>
#include "ISerializer.hpp"
class BinSerializer : public ISerializer{
private:
    std::fstream file;
public:
    BinSerializer() : file() {}

    explicit BinSerializer(const std::string &filename) : file(filename) {}

    BinSerializer(BinSerializer &binSerializer) = delete;

    BinSerializer(BinSerializer &&binSerializer) noexcept : file() {
        file = std::move(binSerializer.file);
    }

    BinSerializer &operator =(const BinSerializer &filesystem) = delete;

    BinSerializer &operator =(BinSerializer &&binSerializer) noexcept {
        file = std::move(binSerializer.file);
        return *this;
    }

    void open(const std::string& filename) override;
    void create(const std::string &filename) override;
    void close() override;

    bool is_open() override;

};

#endif //BND_PROJ_BINSERIALIZER_HPP
