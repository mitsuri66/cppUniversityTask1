#include "ArrayFilling.h"
#include "InputValidation.h"
#include "MenuItems.h"
#include <iostream>
#include <fstream>
#include <filesystem>

void consoleFilling(Train** trains, const int numOfTrains) {
	std::string _destination{};
	std::string _time{};
	int _number{};
	int _seats{};
	int _coupes{};
	int _reserved{};
	for (int i = 0; i < numOfTrains; i++) {
		std::cout << "���������� ���������� � ������ �" << i + 1 << std::endl;
		std::cout << "������� ����� ����������: ";
		std::getline(std::cin, _destination);
		(*trains)[i].setDestination(_destination);
		std::cout << "������� ����� � ������� (��:��): ";
		std::getline(std::cin, _time);
		while (!isValidTime(_time)) {
			std::cout << "��������� ����� �����������. ���������� ������� ���������� ��������: ";
			std::getline(std::cin, _time);
		}
		(*trains)[i].setTime(_time);
		std::cout << "������� ����� ������: ";
		_number = getInt();
		while (_number <= 0) {
			std::cout << "����� ������ �� ����� ���� �������������, ���������� �����: ";
			_number = getInt();
		}
		(*trains)[i].setNumber(_number);
		std::cout << "������� ���������� ����� ����: ";
		_seats = getInt();
		while (_seats <= 0) {
			std::cout << "����������� ���� �� ����� ���� �������������, ���������� �����: ";
			_seats = getInt();
		}
		(*trains)[i].setSeats(_seats);
		std::cout << "������� ���������� �������� ����: ";
		_coupes = getInt();
		while (_coupes <= 0) {
			std::cout << "����������� ���� �� ����� ���� �������������, ���������� �����: ";
			_coupes = getInt();
		}
		(*trains)[i].setCoupes(_coupes);
		std::cout << "������� ���������� ����������� ����: ";
		_reserved = getInt();
		while (_reserved <= 0) {
			std::cout << "����������� ���� �� ����� ���� �������������, ���������� �����: ";
			_reserved = getInt();
		}
		(*trains)[i].setReserved(_reserved);
		std::cout << std::endl;
	}
}

int getSizeFromFile(const std::string filepath) {
	std::string data{};
	int tempLines{};
	int size{};
	std::ifstream myFile{};
	myFile.open(filepath);
	if (!std::ifstream(filepath)) {
		std::cout << "���� �� ����������. ��������� ����." << std::endl;
		myFile.close();
		return 0;
	}

	std::error_code ec;
	if (!std::filesystem::is_regular_file(filepath, ec)) {
		std::cout << "����� �������� ������������ ��������. ��������� ����." << std::endl;
		myFile.close();
		return 0;
	}

	if (!myFile) {
		std::cout << "�������� ���������. ��������� ����." << std::endl;
		myFile.close();
		return 0;
	}

	while (std::getline(myFile, data)) {
		if (!data.empty()) {
			tempLines++;
		}
	}
	if (tempLines == 0) {
		std::cout << "���� ����.";
		return 0;
	}
	if (tempLines % countOfParametrs != 0) {
		std::cout << "� ����� ������������ ������.";
		myFile.close();
		return 0;
	}
	else {
		size = tempLines / countOfParametrs;
		myFile.close();
		return  size;
	}
}

Train* fileInput(int* numOfTrains, const std::string filepath) {
	std::string data{};
	int i{};
	int size{};
	std::ifstream myFile{};
	myFile.open(filepath);

	size = getSizeFromFile(filepath);
	*numOfTrains = size;
	if (size) {
		Train* array = new Train[size];
		std::string _destination{};
		std::string _time{};
		int _number{};
		int _seats{};
		int _coupes{};
		int _reserved{};
		for (i = 0; i < size; i++) {
			myFile >> _destination;
			myFile >> _time;
			if (!isValidTime(_time)) {
				std::cout << "������� �������� ����� ��� ������������ ������. ��� ����� �������� �� '00:00'";
				_time = "00:00";
			}
			myFile >> _number;
			if (_number <= 0) {
				std::cout << "����� ������ ������������� ��� ����� ����. �� ����� ������� �� 1";
				_number = 1;
			}
			myFile >> _seats;
			if (_seats < 0) {
				std::cout << "������������� ����� ����. ��� ����� �������� �� 0";
				_seats = 0;
			}
			myFile >> _coupes;
			if (_coupes < 0) {
				std::cout << "������������� ����� ����. ��� ����� �������� �� 0";
				_coupes = 0;
			}
			myFile >> _reserved;
			if (_reserved < 0) {
				std::cout << "������������� ����� ����. ��� ����� �������� �� 0";
				_reserved = 0;
			}

			array[i].setDestination(_destination);
			array[i].setTime(_time);
			array[i].setNumber(_number);
			array[i].setSeats(_seats);
			array[i].setCoupes(_coupes);
			array[i].setReserved(_reserved);
		}
		myFile.close();
		return array;
	}
	else {
		return nullptr;
	}
}

void fileSave(Train* trains, const int numOfTrains) {
	std::string filepath{};
	bool isDataSaved = false;
	while (!isDataSaved) {
		std::cout << "������� ���� � �����, � ������� ������ ��������� ���������: ";
		std::getline(std::cin, filepath);

		if (std::ifstream(filepath)) {
			std::cout << "���� ��� ����������." << std::endl;
			std::cout << "0 - ������������ ������� ����.\n" << "1 - ������ ����� ����." << std::endl;
			int anotherFile = getInt();
			if (anotherFile) {
				continue;
			}
		}

		std::ofstream myFile(filepath, std::ofstream::app);

		std::error_code ec{};

		if (!std::filesystem::is_regular_file(filepath, ec)) {
			std::cout << "����� �������� ������������ ��������. ��������� ����." << std::endl;
			myFile.close();
			continue;
		}

		if (!myFile) {
			std::cout << "������ ���������. ��������� ����." << std::endl;
			myFile.close();
			continue;
		}

		myFile.close();
		myFile.open(filepath, std::ofstream::trunc);

		for (int i = 0; i < numOfTrains; i++) {
			myFile << trains[i].getDestination() << "\n" << trains[i].getTime() << "\n" << trains[i].getNumber() << "\n"
				<< trains[i].getSeats() << "\n" << trains[i].getCoupes() << "\n" << trains[i].getReserved() << std::endl;
		}
		myFile.close();
		std::cout << "������ ���������." << std::endl;
		isDataSaved = true;
	}

}
