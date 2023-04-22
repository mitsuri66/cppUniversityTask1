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
		std::cout << "Заполнение информации о поезде №" << i + 1 << std::endl;
		std::cout << "Введите пункт назначения: ";
		std::getline(std::cin, _destination);
		(*trains)[i].setDestination(_destination);
		std::cout << "Введите время в формате (чч:мм): ";
		std::getline(std::cin, _time);
		while (!isValidTime(_time)) {
			std::cout << "Введенное время некорректно. Пожалуйста введите корректное значение: ";
			std::getline(std::cin, _time);
		}
		(*trains)[i].setTime(_time);
		std::cout << "Введите номер поезда: ";
		_number = getInt();
		while (_number <= 0) {
			std::cout << "Номер поезда не может быть отрицательным, попробуйте снова: ";
			_number = getInt();
		}
		(*trains)[i].setNumber(_number);
		std::cout << "Введите количество общих мест: ";
		_seats = getInt();
		while (_seats <= 0) {
			std::cout << "Колличество мест не может быть отрицательным, попробуйте снова: ";
			_seats = getInt();
		}
		(*trains)[i].setSeats(_seats);
		std::cout << "Введите количество купейных мест: ";
		_coupes = getInt();
		while (_coupes <= 0) {
			std::cout << "Колличество мест не может быть отрицательным, попробуйте снова: ";
			_coupes = getInt();
		}
		(*trains)[i].setCoupes(_coupes);
		std::cout << "Введите количество плацкартных мест: ";
		_reserved = getInt();
		while (_reserved <= 0) {
			std::cout << "Колличество мест не может быть отрицательным, попробуйте снова: ";
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
		std::cout << "Файл не существует. Повторите ввод." << std::endl;
		myFile.close();
		return 0;
	}

	std::error_code ec;
	if (!std::filesystem::is_regular_file(filepath, ec)) {
		std::cout << "Адрес содержит недопустимые значения. Повторите ввод." << std::endl;
		myFile.close();
		return 0;
	}

	if (!myFile) {
		std::cout << "Загрузка запрещена. Повторите ввод." << std::endl;
		myFile.close();
		return 0;
	}

	while (std::getline(myFile, data)) {
		if (!data.empty()) {
			tempLines++;
		}
	}
	if (tempLines == 0) {
		std::cout << "Файл пуст.";
		return 0;
	}
	if (tempLines % countOfParametrs != 0) {
		std::cout << "В файле недостаточно данных.";
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
				std::cout << "Указано неверное время или неподходящий формат. Оно будет изменено на '00:00'";
				_time = "00:00";
			}
			myFile >> _number;
			if (_number <= 0) {
				std::cout << "Номер поезда отрицательный или равен нулю. Он будет изменен на 1";
				_number = 1;
			}
			myFile >> _seats;
			if (_seats < 0) {
				std::cout << "Отрицательное число мест. Оно будет изменено на 0";
				_seats = 0;
			}
			myFile >> _coupes;
			if (_coupes < 0) {
				std::cout << "Отрицательное число мест. Оно будет изменено на 0";
				_coupes = 0;
			}
			myFile >> _reserved;
			if (_reserved < 0) {
				std::cout << "Отрицательное число мест. Оно будет изменено на 0";
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
		std::cout << "Введите путь к файлу, в который хотите сохранить результат: ";
		std::getline(std::cin, filepath);

		if (std::ifstream(filepath)) {
			std::cout << "Файл уже существует." << std::endl;
			std::cout << "0 - Перезаписать текущий файл.\n" << "1 - Ввести новый путь." << std::endl;
			int anotherFile = getInt();
			if (anotherFile) {
				continue;
			}
		}

		std::ofstream myFile(filepath, std::ofstream::app);

		std::error_code ec{};

		if (!std::filesystem::is_regular_file(filepath, ec)) {
			std::cout << "Адрес содержит недопустимые значения. Повторите ввод." << std::endl;
			myFile.close();
			continue;
		}

		if (!myFile) {
			std::cout << "Запись запрещена. Повторите ввод." << std::endl;
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
		std::cout << "Запись завершена." << std::endl;
		isDataSaved = true;
	}

}
