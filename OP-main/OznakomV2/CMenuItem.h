#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Hotel.h"
#include "Date.h"
using namespace std;

class CMenuItem {

public:
    typedef int(*Func)();
    typedef int (*FunctionHotel)(std::vector<Hotel>&);

    CMenuItem(string, FunctionHotel);
    CMenuItem(string, Func);

    FunctionHotel function{};
    Func func{};

    string item_name{};
    void print();

    int run(std::vector<Hotel>& human);

    int run();
};

