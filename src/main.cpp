#include "Monitor.h"

#include "commands/BNDCommands.hpp"
#include "serializer/BinSerializer.hpp"
#include "LibraryData.hpp"
#include "exceptions/FileWriteException.hpp"
#include "exceptions/LibraryDataException.hpp"

int main() {
    BinSerializer serializer;

    auto libraryData = LibraryData(serializer);

    try {
        libraryData.open("bnd.bin");
    } catch (LibraryDataException &e) {
        std::cerr << e.what() << std::endl;
    } catch (std::bad_alloc &e){
        std::cerr << "Not enough memory." << std::endl;
        return -1;
    } catch (FileWriteException &e) {
        std::cerr << "Can't save libraryData state. Check permissions or free space on a disk." << std::endl;
    }
    libraryData.close();

    auto commandFactory = BNDCommands(libraryData);
#ifdef MONITOR_WITHFILE
    std::ifstream istream("input.txt");
    if(!istream.is_open()){
        std::cerr << "Can't find input file: input.txt" << std::endl;
        filesystem.close();
        return -7;
    }

    std::ofstream ostream("output.txt");
    if(!ostream.is_open()){
        std::cerr << "Can't find output file: output.txt" << std::endl;
        filesystem.close();
        return -8;
    }

    Monitor monitor(commandFactory, istream, ostream, true);
#else //MONITOR_WITHFILE
    Monitor monitor(commandFactory, std::cin, std::cout, false);
#endif //MONITOR_WITHFILE

    monitor.setPrompt("BND> ");
    monitor.setExitMessage("Goodbye.\n");
    try {
        monitor.run();
    } catch (std::bad_alloc &e){
        std::cerr << "Not enough memory." << std::endl;
        libraryData.close();
        return -1;
    } catch (LibraryDataException &e) {
        std::cerr << e.what() << std::endl;
        libraryData.close();
        return -2;
    } catch (FileWriteException &e) {
        std::cerr << "Can't save filesystem state. Check permissions or free space on a disk." << std::endl;
        libraryData.close();
        return -3;
    }
}