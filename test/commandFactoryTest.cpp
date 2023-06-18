#include <gtest/gtest.h>

#include "serializer/BinSerializer.hpp"
#include "LibraryData.hpp"
#include "../src/commands/BNDCommands.hpp"
#include "Monitor.h"

namespace{
    TEST(commands, init) {
        BinSerializer serializer;
        auto libraryData = LibraryData(serializer);
        auto commandFactory = BNDCommands(libraryData);
        std::ifstream istream(R"(C:\Users\maksi\CLionProjects\BND_proj_separate\test\InitIn.txt)");
        ASSERT_EQ(istream.is_open(), 1);
        std::ofstream ostream(R"(C:\Users\maksi\CLionProjects\BND_proj_separate\test\InitOut.txt)");
        Monitor monitor(commandFactory, istream, ostream, false);
        monitor.setPrompt("BND> ");
        monitor.run();
        ASSERT_EQ(libraryData.bnd.getCatOffset(), 10);
        ASSERT_EQ(libraryData.bnd.getCatamount(), 3);
        ASSERT_EQ(libraryData.isInit, true);
        for(int i = 0; i < libraryData.bnd.getCatOffset(); i++){
            ASSERT_EQ(libraryData.bnd.getDataArea()[i], 0);
        }
    }
    TEST(commands, Add) {
        BinSerializer serializer;
        auto libraryData = LibraryData(serializer);
        auto commandFactory = BNDCommands(libraryData);
        std::ifstream istream(R"(C:\Users\maksi\CLionProjects\BND_proj_separate\test\AddIn.txt)");
        ASSERT_EQ(istream.is_open(), 1);
        std::ofstream ostream(R"(C:\Users\maksi\CLionProjects\BND_proj_separate\test\AddOut.txt)");
        Monitor monitor(commandFactory, istream, ostream, false);
        monitor.setPrompt("BND> ");
        monitor.run();
        ASSERT_EQ(libraryData.bnd.getCatalog().getSize(), 2);
        std::string name1(libraryData.bnd.getCatalog().getRecords().at(0).getName());
        ASSERT_EQ(name1, "kat1");
        ASSERT_EQ(libraryData.bnd.getCatalog().getRecords().at(0).getOffset(), 0);
        ASSERT_EQ(libraryData.bnd.getCatalog().getRecords().at(0).getLength(), 2);
        std::string name2(libraryData.bnd.getCatalog().getRecords().at(1).getName());
        ASSERT_EQ(name2, "kat2");
        ASSERT_EQ(libraryData.bnd.getCatalog().getRecords().at(1).getOffset(), 2);
        ASSERT_EQ(libraryData.bnd.getCatalog().getRecords().at(1).getLength(), 4);
        int  array [10] = {1,1,1,1,1,1,0,0,0,0};
        for(int i = 0; i < libraryData.bnd.getCatOffset(); i++){
            ASSERT_EQ(libraryData.bnd.getDataArea()[i], array[i]);
        }
    }
    TEST(commands, Delete) {
        BinSerializer serializer;
        auto libraryData = LibraryData(serializer);
        auto commandFactory = BNDCommands(libraryData);
        std::ifstream istream(R"(C:\Users\maksi\CLionProjects\BND_proj_separate\test\DeleteIn.txt)");
        ASSERT_EQ(istream.is_open(), 1);
        std::ofstream ostream(R"(C:\Users\maksi\CLionProjects\BND_proj_separate\test\DeleteOut.txt)");
        Monitor monitor(commandFactory, istream, ostream, false);
        monitor.setPrompt("BND> ");
        monitor.run();
        ASSERT_EQ(libraryData.bnd.getCatOffset(), 0);
        ASSERT_EQ(libraryData.bnd.getCatamount(), 0);
        ASSERT_EQ(libraryData.isInit, false);
        ASSERT_EQ(libraryData.bnd.getDataArea(), nullptr);
    }
    TEST(commands, DeleteSection) {
        BinSerializer serializer;
        auto libraryData = LibraryData(serializer);
        auto commandFactory = BNDCommands(libraryData);
        std::ifstream istream(R"(C:\Users\maksi\CLionProjects\BND_proj_separate\test\DeleteSectionIn.txt)");
        ASSERT_EQ(istream.is_open(), 1);
        std::ofstream ostream(R"(C:\Users\maksi\CLionProjects\BND_proj_separate\test\DeleteSectionOut.txt)");
        Monitor monitor(commandFactory, istream, ostream, false);
        monitor.setPrompt("BND> ");
        monitor.run();
        ASSERT_EQ(libraryData.bnd.getCatalog().getSize(), 2);
        std::string name1(libraryData.bnd.getCatalog().getRecords().at(0).getName());
        ASSERT_EQ(name1, "kat1");
        ASSERT_EQ(libraryData.bnd.getCatalog().getRecords().at(0).getOffset(), 0);
        ASSERT_EQ(libraryData.bnd.getCatalog().getRecords().at(0).getLength(), 2);
        std::string name2(libraryData.bnd.getCatalog().getRecords().at(1).getName());
        ASSERT_EQ(name2, "kat3");
        ASSERT_EQ(libraryData.bnd.getCatalog().getRecords().at(1).getOffset(), 6);
        ASSERT_EQ(libraryData.bnd.getCatalog().getRecords().at(1).getLength(), 2);
        int  array [10] = {1,1,0,0,0,0,1,1,0,0};
        for(int i = 0; i < libraryData.bnd.getCatOffset(); i++){
            ASSERT_EQ(libraryData.bnd.getDataArea()[i], array[i]);
        }
    }
}
