#include "CMenu.h"

CMenu::CMenu(string title, CMenuItem* items, size_t count) : title(title), items(items), count(count) {}

void CMenu::print() {
    for (size_t i{}; i < count; ++i) {
        std::cout << i + 1 << ".";
        items[i].print();
        std::cout << std::endl;
    }
    std::cout << "0.Выход" << std::endl;
}

int CMenu::runCommand(std::vector<Hotel> &human)
{
    print();
    while (true) {
        std::cout << "\nВаш выбор: ";
        select = getValue();
        if (select >= 0 && select <= count) break;
    }
    if (select == 0) {
        return 0;
    }
    return items[select - 1].run(human);
}

int CMenu::runCommand() {
    print();
    while (true) {
        std::cout << "\nВаш выбор: ";
        select = getValue();
        if (select >= 0 && select <= count) break;
    }
    if (select == 0) {
        return 0;
    }
    return items[select - 1].run();
}