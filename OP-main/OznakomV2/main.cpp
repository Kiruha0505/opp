#include "CMenu.h"
#include "CMenuItem.h"
#include "Hotel.h"
#include <iostream>

const int ITEM_NUMBER = 5;
const int SORT_QUANTITY = 5;
const int SEARCH_QUANTITY = 3;

bool operator==(const Date& d1, const Date& d2)
{
    return (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year);
}
bool operator < (const Date& d1, const Date& d2) {
    if (d1.getYear() != d2.getYear()) return d1.getYear() < d2.getYear();
    if (d1.getMonth() != d2.getMonth()) return d1.getMonth() < d2.getMonth();
    return d1.getDay() < d2.getDay();
}
bool operator > (const Date& d1, const Date& d2) {
    if (d1.getYear() != d2.getYear()) return d1.getYear() > d2.getYear();
    if (d1.getMonth() != d2.getMonth()) return d1.getMonth() > d2.getMonth();
    return d1.getDay() > d2.getDay();
}

int getValue();

int Sorting(std::vector<Hotel>& data)
{
    std::cout << "�������� ���� ����������\n";
    CMenuItem items[SORT_QUANTITY]{
     CMenuItem{"���������� �� �������", (CMenuItem::FunctionHotel)Hotel::SortByBody},
     CMenuItem{"���������� �� ���� �������", (CMenuItem::FunctionHotel)Hotel::SortByRoomType},
     CMenuItem{"���������� �� ������", (CMenuItem::FunctionHotel)Hotel::SortByName},
     CMenuItem{"���������� �� ����", (CMenuItem::FunctionHotel)Hotel::SortByCost},
     CMenuItem{"���������� �� ���� ������", (CMenuItem::FunctionHotel)Hotel::SortByArrivalDate},
    };
    CMenu menu("Choosing", items, SORT_QUANTITY);

    while (menu.runCommand(data)) {
    };

    return 4;
}

int Search(std::vector<Hotel>& data)
{
    std::cout << "�������� ���� ������\n";
    CMenuItem items[SEARCH_QUANTITY]{
     CMenuItem{"����� �� ���� �������", (CMenuItem::FunctionHotel)Hotel::SearchByRoomType},
     CMenuItem{"����� �� �������", (CMenuItem::FunctionHotel)Hotel::SearchByFavors},
     CMenuItem{"����� �� ���� ������", (CMenuItem::FunctionHotel)Hotel::SeatchByDate}
    };
    CMenu menu("Choosing", items, SEARCH_QUANTITY);

    while (menu.runCommand(data)) {
    };

    return 5;
}

int main()
{
    setlocale(LC_ALL, "RU");

    std::vector<Hotel> data;

    Hotel::ReadDataFromFile(data);

    CMenuItem items[ITEM_NUMBER]{
         CMenuItem{"������� ������������ �� �����", (CMenuItem::FunctionHotel)Hotel::PrintFullInfo},
         CMenuItem{"�������� ������������", (CMenuItem::FunctionHotel)Hotel::AddInfo},
         CMenuItem{"������� ������������", (CMenuItem::FunctionHotel)Hotel::DeleteInfo},
         CMenuItem{"����������", (CMenuItem::FunctionHotel)Sorting},
         CMenuItem{"�����", (CMenuItem::FunctionHotel)Search},
    };
    CMenu menu("Choosing", items, ITEM_NUMBER);

    while (menu.runCommand(data)) {
    };

    Hotel::UpdateDataInFile(data);

	return 0;
}