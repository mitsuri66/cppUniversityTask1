#include "MenuInterface.h"
#include <string>

void showGreetings() {
	std::cout << "������������!" << std::endl;
	std::cout << "����������� ������ �1. ������� �6" << std::endl;
	std::cout << "������ ��������: ������ ������\n" << "������ �424\n" << std::endl;
}

void showTaskText() {
	std::cout << "���������� ����������� ����� ��� ���������\n"
		<< "���������� �������. ������ � ������ ����������� � ������� ������� Set, Get, Show.\n"
		<< "��� ���������� ����������� ������ ������ ������������ ���������� �\n"
		<< "��������� ���������� STL ��� ����������� ��������� ���������.\n\n"
		<< "�����: ����� ����������, ����� ������, ����� �����������, ����� �����\n"
		<< "����, ��������, �����������. ������� ������ ��������. �����������\n"
		<< "����������� ���������:\n"
		<< "� ������ �������, ��������� �� ��������� ������ ����������,\n"
		<< "� ������ �������, ��������� �� ��������� ������ ���������� �\n"
		<< "�������������� ����� ��������� ����,\n"
		<< "� ������ �������, �������������� �� ��������� ������ ���������� �\n"
		<< "������� ����� �����.\n" << std::endl;
}

void showMainMenu() {
	std::cout << "�������� ����� ����:" << std::endl;
	std::cout << "1 - ������ �������� ������ � ����������" << std::endl;
	std::cout << "2 - ��������� �������� ������ �� �����" << std::endl;
	std::cout << "3 - ��������� ��������� �����" << std::endl;
	std::cout << "4 - ��������� ������" << std::endl;
}

void showListMenu() {
	std::cout << "����� ���������� �� ������ ��������?. �������� �� ������������ ����." << std::endl;
	std::cout << "1 - ������ �������, ��������� �� ��������� ������ ����������." << std::endl;
	std::cout << "2 - ������ �������, ��������� �� ��������� ������ ���������� � �������������� ����� ��������� ����." << std::endl;
	std::cout << "3 - ������ �������, ��������� �� ��������� ������ ���������� � ������� ����� �����." << std::endl;
	std::cout << "4 - ��������� � ������� ����." << std::endl;
}

void showTrainArray(Train* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i].showAll();
		std::cout << std::endl;
	}
}

void listSelection(Train* trains, int numOfTrains) {
	int secondSelection{};
	std::string destinationKey{};
	int timeKey{};
	bool save{};
	bool quit = false;
	while (!quit) {
		showListMenu();
		secondSelection = getInt();
		switch (secondSelection) {
		case dest:
		{
			std::cout << "������� ����� ���������� ������: ";
			std::getline(std::cin, destinationKey);
			std::cout << "\n��� ������ ��������� �� ������� ������ ����������: " << destinationKey << '\n' << std::endl;

			std::pair <Train*, int> sortedTrains = destinationList(trains, numOfTrains, destinationKey);

			showTrainArray(sortedTrains.first, sortedTrains.second);

			std::cout << "������ ��������� ���������� � ����?\n" << "0 - ���\n1 - ��" << std::endl;
			save = getBool();
			if (save) {
				fileSave(sortedTrains.first, sortedTrains.second);
			}
			delete[]sortedTrains.first;
			sortedTrains.first = nullptr;
		}
		break;

		case destNtime:
		{
			std::cout << "������� ����� ���������� ������: ";
			std::getline(std::cin, destinationKey);
			std::cout << "\n����� ������ ���� ����� ������ ������������?: ";
			timeKey = getInt();
			while (timeKey < 0 || timeKey > 23) {
				std::cout << "��������� ����� �����������. ���������� ������� ���������� ��������: ";
				timeKey = getInt();
			}
			std::cout << "\n��� ������ ��������� �� " << destinationKey << " ����� " << timeKey << '\n' << std::endl;

			std::pair <Train*, int> sortedTrains = destinationAndTimeList(trains, numOfTrains, destinationKey, timeKey);

			showTrainArray(sortedTrains.first, sortedTrains.second);

			std::cout << "������ ��������� ���������� � ����?\n" << "0 - ���\n1 - ��" << std::endl;
			save = getBool();
			if (save) {
				fileSave(sortedTrains.first, sortedTrains.second);
			}
			delete[]sortedTrains.first;
			sortedTrains.first = nullptr;
		}
		break;

		case destNseats:
		{
			std::cout << "������� ����� ���������� ������: ";
			std::getline(std::cin, destinationKey);
			std::cout << "\n��� ������ ��������� �� " << destinationKey << " � ������� ����� �����\n" << std::endl;

			std::pair <Train*, int> sortedTrains = destinationAndSeatsList(trains, numOfTrains, destinationKey);

			showTrainArray(sortedTrains.first, sortedTrains.second);

			std::cout << "������ ��������� ���������� � ����?\n" << "0 - ���\n1 - ��" << std::endl;
			save = getBool();
			if (save) {
				fileSave(sortedTrains.first, sortedTrains.second);
			}
			delete[]sortedTrains.first;
			sortedTrains.first = nullptr;
		}
		break;
		case back:
			std::cout << "�� ��������� �������." << std::endl;
			quit = true;
		}
	}
}

void startProgram() {
	bool quit = false;
	bool save{};
	Train* trains = nullptr;
	std::string filepath{};
	int numOfTrains{};
	int programSelection{};
	showGreetings();
	showTaskText();
	while (!quit) {
		showMainMenu();
		programSelection = getInt();
		if (programSelection == start) {
			std::cout << "������� ������� �� ������ ��������? ";
			numOfTrains = getInt();
		}
		switch (programSelection) {
		case start:
			trains = new Train[numOfTrains];
			consoleFilling(&trains, numOfTrains);
			std::cout << std::endl;
			std::cout << "������ ��������� ������ � ����?\n" << "0 - ���\n1 - ��" << std::endl;
			save = getBool();
			if (save) {
				fileSave(trains, numOfTrains);
			}
			listSelection(trains, numOfTrains);
			break;
		case fstart:
			std::cout << "������ ������ ��(������� ���� � �����): ";
			std::getline(std::cin, filepath);
			trains = fileInput(&numOfTrains, filepath);
			std::cout << std::endl;
			showTrainArray(trains, numOfTrains);
			listSelection(trains, numOfTrains);
			break;
		case test:
			mainTest();
			break;
		case end:
			quit = true;
			continue;
		}
	}
	delete[]trains;
	trains = nullptr;
	std::cout << "�� ��������!" << std::endl;
}