#include "Monitor.h"

#include "commands/BNDCommands.hpp"
#include "serializer/BinSerializer.hpp"
#include "LibraryData.hpp"
#include "exceptions/FileWriteException.hpp"

int main() {
    BinSerializer serializer;

    auto libraryData = LibraryData(serializer);

    try {
        libraryData.open("bnd.bin");
    } catch (FilesystemException &e) {
        std::cerr << e.what() << std::endl;
    } catch (std::bad_alloc &e){
        std::cerr << "Not enough memory." << std::endl;
        return -1;
    } catch (FileWriteException &e) {
        std::cerr << "Can't save libraryData state. Check permissions or free space on a disk." << std::endl;
    }

    auto commandFactory = FSCommands(libraryData);
}