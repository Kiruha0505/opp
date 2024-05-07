#include "CMenuItem.h"

CMenuItem::CMenuItem(string name, Func func) : item_name(name), func(func) {}
CMenuItem::CMenuItem(string name, FunctionHotel function) : item_name(name), function(function) {}

void CMenuItem::print() 
{
    std::cout << item_name;
}

int CMenuItem::run(std::vector<Hotel> &human)
{
    return function(human);
}


int CMenuItem::run()
{
    return func();
}

