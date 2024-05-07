#pragma once

#include <cstddef>
#include <string>
#include <vector>
#include "CMenuItem.h"
#include "Hotel.h"
#include "Date.h"

int getValue();

using namespace std;

class CMenu {
    
public:
    CMenu(string, CMenuItem* , size_t);

    void print();

    int runCommand(std::vector<Hotel> &human);
    int runCommand();

private:
    int select{ -1 };
    size_t count{};
    string title{};
    CMenuItem *items;
};
