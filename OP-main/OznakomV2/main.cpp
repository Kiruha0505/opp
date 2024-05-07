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
    std::cout << "Выберите поле сортировки\n";
    CMenuItem items[SORT_QUANTITY]{
     CMenuItem{"Сортировка по корпусу", (CMenuItem::FunctionHotel)Hotel::SortByBody},
     CMenuItem{"Сортировка по типу комнаты", (CMenuItem::FunctionHotel)Hotel::SortByRoomType},
     CMenuItem{"Сортировка по именам", (CMenuItem::FunctionHotel)Hotel::SortByName},
     CMenuItem{"Сортировка по цене", (CMenuItem::FunctionHotel)Hotel::SortByCost},
     CMenuItem{"Сортировка по дате заезда", (CMenuItem::FunctionHotel)Hotel::SortByArrivalDate},
    };
    CMenu menu("Choosing", items, SORT_QUANTITY);

    while (menu.runCommand(data)) {
    };

    return 4;
}

int Search(std::vector<Hotel>& data)
{
    std::cout << "Выберите поле поиска\n";
    CMenuItem items[SEARCH_QUANTITY]{
     CMenuItem{"Поиск по типу комнаты", (CMenuItem::FunctionHotel)Hotel::SearchByRoomType},
     CMenuItem{"Поиск по услугам", (CMenuItem::FunctionHotel)Hotel::SearchByFavors},
     CMenuItem{"Поиск по дате заезда", (CMenuItem::FunctionHotel)Hotel::SeatchByDate}
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
         CMenuItem{"Вывести бронирования на экран", (CMenuItem::FunctionHotel)Hotel::PrintFullInfo},
         CMenuItem{"Добавить бронирование", (CMenuItem::FunctionHotel)Hotel::AddInfo},
         CMenuItem{"Удалить бронирование", (CMenuItem::FunctionHotel)Hotel::DeleteInfo},
         CMenuItem{"Сортировка", (CMenuItem::FunctionHotel)Sorting},
         CMenuItem{"Поиск", (CMenuItem::FunctionHotel)Search},
    };
    CMenu menu("Choosing", items, ITEM_NUMBER);

    while (menu.runCommand(data)) {
    };

    Hotel::UpdateDataInFile(data);

	return 0;
}