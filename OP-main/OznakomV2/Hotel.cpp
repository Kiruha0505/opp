#include "Hotel.h"

int getValue()
{
	int a{};
	while (true) // ���� ������������ �� ��� ���, ���� ������������ �� ������
	{
		std::cin >> a;

		if (std::cin.fail()) // ���� ���������� ���������� ��������� ���������,
		{
			std::cin.clear(); // �� ���������� cin � '�������' ����� ������ 
			std::cin.ignore(32767, '\n'); // � ������� �������� �����������
			std::cout << "������������ ������, ������� ��� ���: ";
		}
		else // ���� �� ������, �� ���������� a 
			return a;
	}
}

Hotel::Hotel()
{

}

int Hotel::GetId()
{
	return this->id;
}

int Hotel::GetCorpus()
{
	return this->corpus;
}

std::vector<Service> Hotel::GetFavors()
{
	return this->favors;
}

int Hotel::GetCost()
{
	return this->cost;
}

std::string Hotel::GetFullName()
{
	return this->fullName;
}

std::string Hotel::GetPhoneNumber()
{
	return this->phoneNumber;
}

std::string Hotel::GetEMail()
{
	return this->eMail;
}

Date Hotel::GetDate()
{
	return this->date;
}

int Hotel::GetNightsNumber()
{
	return this->nightsNumber;
}

int Hotel::GetFullCost()
{
	return this->fullCost;
}

int Hotel::AddInfo(std::vector<Hotel>& data)
{
	static int count = data.size() + 1;
	Hotel buff;
	buff.id = count++;
	int variant{};
	std::cout << "�������� ������: \n1.�����; \n2.����;  \n3.����; \n4.������; \n5.�����. \n�����: ";
	while (true) {
		variant = getValue();
		std::cin.ignore(32767, '\n'); // � ������� �������� �����������
		if (variant >= 1 && variant <= 5) break;
		else std::cout << "������������ ������, ������� ��� ���: ";
	}
	switch (variant)
	{
	case 1: buff.corpus = Alpha; break;
	case 2: buff.corpus = Beta; break;
	case 3: buff.corpus = Vega; break;
	case 4: buff.corpus = Delta; break;
	case 5: buff.corpus = Gamma; break;
	}
	std::cout << std::endl;

	std::cout << "�������� ��� �������: \n1.��������; \n2.������-�����;  \n3.������ �����; \n4.������; \n�����: ";
	while (true) {
		variant = getValue();
		std::cin.ignore(32767, '\n'); // � ������� �������� �����������
		if (variant >= 1 && variant <= 4) break;
		else std::cout << "������������ ������, ������� ��� ���: ";
	}

	switch (variant)
	{
	case 1: buff.room = Standard; break;
	case 2: buff.room = BusinessClass; break;
	case 3: buff.room = FirstClass; break;
	case 4: buff.room = Deluxe; break;
	}
	std::cout << std::endl;

	variant = 0;
	std::cout << "�������� ���. ������: \n1.�������; \n2.��������; \n3.�������-���; \n4.���; \n5.���������; \n6.Wifi. \n�����(0-�����): ";
	do
	{
		variant = getValue();
		std::cin.ignore(32767, '\n'); // � ������� �������� �����������
		switch (variant)
		{
		case 1: buff.favors.push_back(SwimmingPool); break;
		case 2: buff.favors.push_back(Lucnh); break;
		case 3: buff.favors.push_back(FitnessRoom); break;
		case 4: buff.favors.push_back(Spa); break;
		case 5: buff.favors.push_back(Transport); break;
		case 6: buff.favors.push_back(FreeWifi); break;
		}
	} while (variant != 0);
	std::cout << std::endl;

	std::cout << "���� 1 ����: ";
	while (true) {
		buff.cost = getValue();
		std::cin.ignore(32767, '\n');
		if (buff.cost > 0) break;
		else std::cout << "������������ ������, ������� ��� ���: ";
	}
	std::cout << std::endl;

	std::cout << "������� ���: ";
	std::getline(std::cin, buff.fullName);
	std::cout << std::endl;


	std::cout << "������� ����� ��������: ";
	std::getline(std::cin, buff.phoneNumber);
	std::cout << std::endl;

	std::cout << "������� ����� ����������� �����: ";
	std::getline(std::cin, buff.eMail);
	std::cout << std::endl;

	int day, month, year;
	std::cout << "������� ���� ������\n";
	std::cout << "����: ";
	while (true) {
		day = getValue();
		std::cin.ignore(32767, '\n');
		if (day >= 1 && day <= 31) break;
		else std::cout << "������������ ������, ������� ��� ���: ";
	}

	std::cout << "�����: ";
	while (true) {
		month = getValue();
		std::cin.ignore(32767, '\n');
		if (month >= 1 && month <= 12) break;
		else std::cout << "������������ ������, ������� ��� ���: ";
	}

	std::cout << "���: ";
	while (true) {
		year = getValue();
		std::cin.ignore(32767, '\n');
		if (year >= 2000 && year <= 2100) break;
		else std::cout << "������������ ������, ������� ��� ���: ";
	}

	buff.date = Date(day, month, year);

	std::cout << std::endl;

	std::cout << "������� ���������� �����: ";
	while (true) {

		buff.nightsNumber = getValue();
		std::cin.ignore(32767, '\n');
		if (buff.nightsNumber >= 1) break;
		else std::cout << "������������ ������, ������� ��� ���: ";
	}


	buff.fullCost = ((buff.nightsNumber) * buff.cost) + (1000 * buff.favors.size());

	data.push_back(buff);
	return 2;
}
void Hotel::PrintInfo() {
	std::cout << std::endl;
	std::cout << "ID: " << GetId() << std::endl;
	std::cout << "������: ";
	switch (this->corpus) {
	case 1: std::cout << "�����"; break;
	case 2: std::cout << "����"; break;
	case 3: std::cout << "����"; break;
	case 4: std::cout << "������"; break;
	case 5: std::cout << "�����"; break;
	}
	std::cout << std::endl;

	std::cout << "��� �������: ";
	switch (this->room) {
	case 1: std::cout << "��������"; break;
	case 2: std::cout << "�������-�����"; break;
	case 3: std::cout << "������ �����"; break;
	case 4: std::cout << "������"; break;
	}
	std::cout << std::endl;

	std::cout << "������: ";
	for (int i = 0; i < this->favors.size(); i++) {
		switch (this->favors[i]) {
		case 1: std::cout << "�������"; break;
		case 2: std::cout << "��������"; break;
		case 3: std::cout << "�������-���"; break;
		case 4: std::cout << "���"; break;
		case 5: std::cout << "���������"; break;
		case 6: std::cout << "Wifi"; break;
		}
		if (favors.size() > 1 && i != favors.size() - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;

	std::cout << "���� 1 ����: " << GetCost() << std::endl;
	std::cout << "���: " << GetFullName() << std::endl;
	std::cout << "����� ��������: " << GetPhoneNumber() << std::endl;
	std::cout << "����� ����������� �����: " << GetEMail() << std::endl;
	std::cout << "���� ������: ";
	this->date.PrintDate();
	std::cout << std::endl;

	std::cout << "���������� �����: " << GetNightsNumber() << std::endl;
	std::cout << "������ ���������: " << GetFullCost() << std::endl << std::endl;

}
int Hotel::PrintFullInfo(std::vector<Hotel>& data)
{
	for (int i = 0; i < data.size(); i++) {
		data[i].PrintInfo();
		std::cout << std::endl;
	}
	return 1;
}
int Hotel::DeleteInfo(std::vector<Hotel>& data)
{
	PrintFullInfo(data);
	int variant{};
	std::cout << "�������� ����������: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= data.size()) break;
	}

	variant--;

	data.erase(data.begin() + variant);
	return 3;
}

int Hotel::SortByBody(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "1. �� �����������. " << std::endl << "2. �� ��������. " << std::endl << "�����: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && data[j].corpus < data[j + 1].corpus) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && data[j].corpus > data[j + 1].corpus) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	PrintFullInfo(data);
	return 1;
}
int Hotel::SortByRoomType(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "1. �� �����������. " << std::endl << "2. �� ��������. " << std::endl << "�����: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && data[j].room < data[j + 1].room) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && data[j].room > data[j + 1].room) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	PrintFullInfo(data);
	return 1;
}
int Hotel::SortByName(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "1. �� �����������. " << std::endl << "2. �� ��������. " << std::endl << "�����: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && strcmp(data[j].fullName.c_str(), data[j + 1].fullName.c_str()) < 0) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && strcmp(data[j].fullName.c_str(), data[j + 1].fullName.c_str()) > 0) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	PrintFullInfo(data);
	return 1;
}
int Hotel::SortByArrivalDate(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "1. �� �����������. " << std::endl << "2. �� ��������. " << std::endl << "�����: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && data[j].date < data[j + 1].date) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && data[j].date > data[j + 1].date) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	PrintFullInfo(data);
	return 1;
}
int Hotel::SortByCost(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "1. �� �����������. " << std::endl << "2. �� ��������. " << std::endl << "�����: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 2) break;
	}
	for (int l = 0; l < data.size() - 1; l++) {
		for (int j = 0; j < data.size() - l - 1; j++) {
			if (variant == 1 && data[j].cost > data[j + 1].cost) {
				std::swap(data[j], data[j + 1]);
			}
			if (variant == 2 && data[j].cost < data[j + 1].cost) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
	PrintFullInfo(data);
	return 1;
}

int Hotel::SearchByRoomType(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "�������� ����: " << std::endl << "1.��������. \n" << "2.������-�����. \n" << "3.������ �����. \n" << "4.������. \n" << "�����: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 4) break;
	}
	for (int i{}; i < data.size(); i++)
	{
		if (data[i].room == variant)
		{
			data[i].PrintInfo();
		}
	}
	return 1;
}
int Hotel::SearchByFavors(std::vector<Hotel>& data)
{
	int variant{};
	std::cout << "�������� ����: \n" << "1.�������. \n" << "2.��������. \n" << "3.�������-���. \n" << "4.���.\n" << "5.���������. \n" << "6.Wifi. \n" << "�����: ";
	while (true) {
		variant = getValue();
		if (variant >= 1 && variant <= 6) break;
	}
	for (int i{}; i < data.size(); i++)
	{
		for (int j{}; j < data[i].favors.size(); j++) {
			if (data[i].favors[j] == variant)
			{
				data[i].PrintInfo();
				break;
			}
		}
	}
	return 1;
}
int Hotel::SeatchByDate(std::vector<Hotel>& data)
{
	int d{}, m{}, y{};
	std::cout << "������� ����: ";
	while (true) {
		d = getValue();
		if (d >= 1 && d <= 31) break;
	}
	std::cout << "������� �����: ";
	while (true) {
		m = getValue();
		if (m >= 1 && m <= 12) break;
	}
	std::cout << "������� ���: ";
	while (true) {
		y = getValue();
		if (y >= 2000 && y <= 2100) break;
	}

	Date buff = (d, m, y);

	for (int i{}; i < data.size(); i++)
	{
		if (data[i].date == buff)
		{
			data[i].PrintInfo();
		}
	}
	return 1;
}

void Hotel::ReadDataFromFile(std::vector<Hotel>& data)
{
	std::ifstream fsin("Hotel.txt", std::ios::in);
	Hotel buff;
	int count = 1;
	int room;
	int body;
	int d, m, y;
	std::string n, f, o;
	int favor[6]{};
	if (fsin.is_open()) {
		while (fsin >> body >> room >> favor[0] >> favor[1] >> favor[2] >> favor[3] >> favor[4] >> favor[5] >> buff.cost >> f >> n >> o >> buff.phoneNumber >> buff.eMail >> d >> m >> y >> buff.nightsNumber >> buff.fullCost) {
			buff.id = count++;
			//fsin >> buff.id >> body >> room >> favor[0] >> favor[1] >> favor[2] >> favor[3] >> favor[4] >> favor[5] >> buff.cost >> n >> f >> o >> buff.phoneNumber >> buff.eMail >> d >> m >> y >> buff.nightsNumber >> buff.fullCost;
			if (body == 1) buff.corpus = Body::Alpha;
			else if (body == 2) buff.corpus = Body::Beta;
			else if (body == 3) buff.corpus = Body::Delta;
			else if (body == 4) buff.corpus = Body::Gamma;
			else buff.corpus = Body::Vega;

			if (room == 1) buff.room = RoomType::Standard;
			else if (room == 2) buff.room = RoomType::BusinessClass;
			else if (room == 3) buff.room = RoomType::FirstClass;
			else if (room == 4) buff.room = RoomType::Deluxe;

			for (int j{}; j < 6; j++) {
				switch (favor[j]) {
				case 1: buff.favors.push_back(SwimmingPool); break;
				case 2: buff.favors.push_back(Lucnh); break;
				case 3: buff.favors.push_back(FitnessRoom); break;
				case 4: buff.favors.push_back(Spa); break;
				case 5: buff.favors.push_back(Transport); break;
				case 6: buff.favors.push_back(FreeWifi); break;
				}
				favor[j] = 0;
			}
			buff.date = Date(d, m, y);
			buff.fullName = f + ' ' + n + ' ' + o;
			data.push_back(buff);
			for (int k{}; k < 6; k++) { favor[k] = 0; }
			buff.favors.clear();
		}

	}
	fsin.close();
}

void Hotel::UpdateDataInFile(std::vector<Hotel>& data)
{
	std::ofstream fout("Hotel.txt", std::ios::out);
	for (int i{}; i < data.size(); i++)
	{
		int favors[6]{};
		for (int j{}; j < 6; j++) {
			for (int r{}; r < data[i].favors.size(); r++) {
				if (data[i].favors[r] == j + 1) {
					favors[j] = data[i].favors[r];
				}
			}
		}

		fout << data[i].corpus << '\t' << data[i].room << '\t' << favors[0] << '\t' << favors[1] << '\t' << favors[2] << '\t' << favors[3] << '\t' << favors[4] << '\t' << favors[5] << '\t' << data[i].GetCost() << '\t' << data[i].GetFullName() << '\t' << data[i].GetPhoneNumber() << '\t' << data[i].GetEMail() << '\t' << data[i].date.getDay() << '\t' << data[i].date.getMonth() << '\t' << data[i].date.getYear() << '\t' << data[i].GetNightsNumber() << '\t' << data[i].GetFullCost() << '\n';

	}
	fout.close();

}
