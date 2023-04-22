#include "ModuleTests.h"
#include "Train.h"
#include "ArrayFilling.h"
#include "InputValidation.h"
#include "Lists.h"
#include <iostream>
#include <sstream>

//������� �������� ������ ����������
bool firstListTest() {
	bool result = true;
	std::pair <Train*, int> sortedTrains;
	int size{};
	int i{};
	Train testArray[2];
	testArray[0].setDestination("Pavlovsk");
	testArray[0].setTime("10:30");
	testArray[0].setNumber(10);
	testArray[0].setSeats(100);
	testArray[0].setCoupes(13);
	testArray[0].setReserved(70);
	testArray[1].setDestination("Pavlovsk");
	testArray[1].setTime("17:15");
	testArray[1].setNumber(36);
	testArray[1].setSeats(12);
	testArray[1].setCoupes(0);
	testArray[1].setReserved(12);

	std::string filepath = "testFile.txt";
	std::cout << "����� ���������� � ������� �� ����� '" << filepath
		<< "' �� �������� ��������� ������ ������� ��������� �� ��������� ������ ����������" << std::endl;
	Train* trains = fileInput(&size, filepath);
	if (size) {
		sortedTrains = destinationList(trains, size, "Pavlovsk");
		if (sortedTrains.second == 2) {
			for (i = 0; i < sortedTrains.second; i++) {
				if (sortedTrains.first[i].getDestination() != testArray[i].getDestination()
					|| sortedTrains.first[i].getTime() != testArray[i].getTime()
					|| sortedTrains.first[i].getNumber() != testArray[i].getNumber()
					|| sortedTrains.first[i].getSeats() != testArray[i].getSeats()
					|| sortedTrains.first[i].getCoupes() != testArray[i].getCoupes()
					|| sortedTrains.first[i].getReserved() != testArray[i].getReserved()) {
					std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
					result = false;
					break;
				}
				else {
					result = true;
				}
			}
		}
		else {
			std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
			result = false;
		}
	}
	if (!result) {
		std::cout << "��������� ���������:" << std::endl;
		for (i = 0; i < 2; i++) {
			testArray[i].showAll();
		}
		std::cout << "\n���������� ���������:" << std::endl;
		for (i = 0; i < sortedTrains.second; i++) {
			sortedTrains.first[i].showAll();
		}
	}
	return result;
}

//������� �������� 2� ����������
bool secondListTest() {
	bool result = true;
	std::pair <Train*, int> sortedTrain;
	int size{};
	int i{};
	Train tesTrain{};
	tesTrain.setDestination("Pavlovsk");
	tesTrain.setTime("17:15");
	tesTrain.setNumber(36);
	tesTrain.setSeats(12);
	tesTrain.setCoupes(0);
	tesTrain.setReserved(12);

	std::string filepath = "testFile.txt";
	std::cout << "����� ���������� � ������� �� ����� '" << filepath
		<< "' �� �������� ��������� ������ ������� ��������� �� ��������� ������ ���������� � �������������� ����� ��������� ����" << std::endl;
	Train* trains = fileInput(&size, filepath);
	if (size) {
		sortedTrain = destinationAndTimeList(trains, size, "Pavlovsk", 15);
		if (sortedTrain.second == 1) {
			for (i = 0; i < sortedTrain.second; i++) {
				if (sortedTrain.first[i].getDestination() != tesTrain.getDestination()
					|| sortedTrain.first[i].getTime() != tesTrain.getTime()
					|| sortedTrain.first[i].getNumber() != tesTrain.getNumber()
					|| sortedTrain.first[i].getSeats() != tesTrain.getSeats()
					|| sortedTrain.first[i].getCoupes() != tesTrain.getCoupes()
					|| sortedTrain.first[i].getReserved() != tesTrain.getReserved()) {
					std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
					result = false;

				}
				else {
					result = true;
				}
			}
		}
		else {
			std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
			result = false;
		}
	}
	if (!result) {
		std::cout << "��������� ���������:" << std::endl;
		tesTrain.showAll();
		std::cout << "\n���������� ���������:" << std::endl;
		for (i = 0; i < sortedTrain.second; i++) {
			sortedTrain.first[i].showAll();
		}
	}
	return result;
}

//������� �������� 3� ����������
bool thirdListTest() {
	bool result = true;
	std::pair <Train*, int> sortedTrain;
	int size{};
	int i{};
	Train tesTrain{};
	tesTrain.setDestination("Vyborg");
	tesTrain.setTime("15:00");
	tesTrain.setNumber(13955);
	tesTrain.setSeats(36);
	tesTrain.setCoupes(12);
	tesTrain.setReserved(24);

	std::string filepath = "testFile.txt";
	std::cout << "����� ���������� � ������� �� ����� '" << filepath
		<< "' �� �������� ��������� ������ ������� ��������� �� ��������� ������ ���������� � ������� ����� �����" << std::endl;
	Train* trains = fileInput(&size, filepath);
	if (size) {
		sortedTrain = destinationAndSeatsList(trains, size, "Vyborg");
		if (sortedTrain.second == 1) {
			for (i = 0; i < sortedTrain.second; i++) {
				if (sortedTrain.first[i].getDestination() != tesTrain.getDestination()
					|| sortedTrain.first[i].getTime() != tesTrain.getTime()
					|| sortedTrain.first[i].getNumber() != tesTrain.getNumber()
					|| sortedTrain.first[i].getSeats() != tesTrain.getSeats()
					|| sortedTrain.first[i].getCoupes() != tesTrain.getCoupes()
					|| sortedTrain.first[i].getReserved() != tesTrain.getReserved()) {
					std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
					result = false;
				}
				else {
					result = true;
				}
			}
		}
		else {
			std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
			result = false;
		}
	}
	if (!result) {
		std::cout << "��������� ���������:" << std::endl;
		tesTrain.showAll();
		std::cout << "\n���������� ���������:" << std::endl;
		for (i = 0; i < sortedTrain.second; i++) {
			sortedTrain.first[i].showAll();
		}
	}
	return result;
}

//�������� ������� ����������� ������� ������� �� ����� (getSizeFromFile)
bool fourthTest() {
	std::string filepath = "testFile.txt";
	std::cout << "����� ���������� � ������� �� ����� '" << filepath
		<< "' �� �������� ������������ �������� ���-�� �����" << std::endl;
	int size = getSizeFromFile(filepath);
	if (size == 6)
		return true;
	else {
		std::cout << "�� ����� ����� ��������� ������." << std::endl;
		std::cout << "��������� ���������: " << 6 << std::endl;
		std::cout << "���������� ���������: " << size << std::endl;
		return false;
	}
}

bool fifthTest() {
	bool result = true;
	int size{};
	int i{};
	Train tesTrain{};
	tesTrain.setDestination("Vyborg");
	tesTrain.setTime("15:00");
	tesTrain.setNumber(13955);
	tesTrain.setSeats(36);
	tesTrain.setCoupes(12);
	tesTrain.setReserved(24);

	std::string filepath = "testFile2.txt";
	std::cout << "����� ���������� � ������� �� ����� '" << filepath
		<< "' �� �������� ���������� ������ �� �����" << std::endl;
	Train* trains = fileInput(&size, filepath);
	if (size == 1) {
		for (i = 0; i < size; i++) {
			if (trains[i].getDestination() != tesTrain.getDestination()
				|| trains[i].getTime() != tesTrain.getTime()
				|| trains[i].getNumber() != tesTrain.getNumber()
				|| trains[i].getSeats() != tesTrain.getSeats()
				|| trains[i].getCoupes() != tesTrain.getCoupes()
				|| trains[i].getReserved() != tesTrain.getReserved()) {
				std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
				result = false;
			}
			else {
				result = true;
			}
		}
	}
	else {
		std::cout << "�� ����� ����� ��������� ������\n" << std::endl;
		result = false;
	}
	if (!result) {
		std::cout << "��������� ���������:" << std::endl;
		tesTrain.showAll();
		std::cout << "\n���������� ���������:" << std::endl;
		for (i = 0; i < size; i++) {
			trains[i].showAll();
		}
	}
	return result;
}

void mainTest() {
	std::cout << std::endl;
	bool firstCheck = firstListTest();
	std::cout << std::endl;
	if (firstCheck) {
		std::cout << "������ ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "������ ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool secondCheck = secondListTest();
	std::cout << std::endl;
	if (secondCheck) {
		std::cout << "������ ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "������ ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool thirdCheck = thirdListTest();
	std::cout << std::endl;
	if (thirdCheck) {
		std::cout << "������ ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "������ ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool fourthCheck = fourthTest();
	std::cout << std::endl;
	if (fourthCheck) {
		std::cout << "��������� ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "��������� ��������� ���� �� �������." << std::endl;
	}
	std::cout << std::endl;
	bool fifthCheck = fifthTest();
	std::cout << std::endl;
	if (fifthCheck) {
		std::cout << "����� ��������� ���� �������." << std::endl;
	}
	else {
		std::cout << "����� ��������� ���� �� �������." << std::endl;
	}
}