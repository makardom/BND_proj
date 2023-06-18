//
// Created by maksi on 18.06.2023.
//

#ifndef BND_TESTFUNCTIONS_HPP
#define BND_TESTFUNCTIONS_HPP

#include <string>
#include <fstream>


static bool compareFiles(const std::string& first, const std::string& second)
{
    std::ifstream file1(first);
    std::ifstream file2(second);

    std::string line1, line2;
    while (std::getline(file1, line1) && std::getline(file2, line2))
    {
        if (line1 != line2)
        {
            return false;
        }
    }

    return true;
}
#endif //BND_TESTFUNCTIONS_HPP
