#pragma once
#include "Date.h"
#include <vector>
#include <fstream>
#include "Date.h"

enum Body {
	Alpha = 1,
	Beta,
	Vega,
	Delta,
	Gamma
};

enum RoomType {

	Standard = 1,
	BusinessClass,
	FirstClass,
	Deluxe
};

enum Service {
	SwimmingPool = 1,
	Lucnh,
	FitnessRoom,
	Spa,
	Transport,
	FreeWifi
};

class Hotel {
public:

	Hotel();

	int GetId();
	int GetCorpus();
	std::vector<Service> GetFavors();
	int GetCost();
	std::string GetFullName();
	std::string GetPhoneNumber();
	std::string GetEMail();
	Date GetDate();
	int GetNightsNumber();
	int GetFullCost();

	static int AddInfo(std::vector<Hotel> &data);
	void PrintInfo();
	static int PrintFullInfo(std::vector<Hotel> &data);
	static int DeleteInfo(std::vector<Hotel>& data);

	static void ReadDataFromFile(std::vector<Hotel> &data);
	static void UpdateDataInFile(std::vector<Hotel> &data);
	
	static int SortByBody(std::vector<Hotel>& data);
	static int SortByRoomType(std::vector<Hotel>& data);
	static int SortByCost(std::vector<Hotel>& data);
	static int SortByName(std::vector<Hotel>& data);
	static int SortByArrivalDate(std::vector<Hotel>& data);

	static int SearchByRoomType(std::vector<Hotel>& data);
	static int SearchByFavors(std::vector<Hotel>& data);
	static int SeatchByDate(std::vector<Hotel>& data);

private:

	int id{};
	Body corpus;
	RoomType room;
	std::vector<Service> favors;
	int cost;
	std::string fullName;
	std::string phoneNumber;
	std::string eMail;
	Date date;
	int nightsNumber;
	int fullCost;

};