#pragma once

#include <string>

class Train
{
	std::string destination;
	std::string departureTime;
	int number{};
	int seats{};
	int coupes{};
	int reserved{};
public:
	//������� ��������� �������� � ���� ������
	void setDestination(const std::string _destination);
	void setTime(const std::string _time);
	void setNumber(const int _number);
	void setSeats(const int _seats);
	void setCoupes(const int _coupes);
	void setReserved(const int _reserved);

	//������� ��������� �������� ����� ������
	std::string getDestination();
	std::string getTime();
	int getNumber();
	int getSeats();
	int getCoupes();
	int getReserved();

	//������� ������ ���� ���������� ������ �� �������
	void showAll();
};