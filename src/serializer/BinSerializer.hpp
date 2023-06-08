//
// Created by maksi on 04.06.2023.
//

#ifndef BND_PROJ_BINSERIALIZER_HPP
#define BND_PROJ_BINSERIALIZER_HPP

#include <fstream>
#include "serializer/ISerializer.hpp"
class BinSerializer : public ISerializer{
private:
    std::fstream file;
    static constexpr size_t BND_INFO_BLOCK_SIZE = 8;
    static constexpr size_t BND_DATA_BLOCK_SIZE = 4;
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

    void save(BND &bnd) override;
    void save(CatalogUnit &catalogUnit, off_t offset) override;
    void save(const Catalog &catalog, off_t offset) override;

    void load(BND &bnd) override;
    void load(CatalogUnit &catalogUnit, off_t offset) override;
    void load(Catalog &catalog, off_t offset, unsigned short amount) override;

    bool is_open() override;
};

#endif //BND_PROJ_BINSERIALIZER_HPP
