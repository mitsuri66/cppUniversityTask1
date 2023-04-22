#include "MenuInterface.h"
#include <string>

void showGreetings() {
	std::cout << "Здравствуйте!" << std::endl;
	std::cout << "Контрольная работа №1. Вариант №6" << std::endl;
	std::cout << "Работу выполнил: Губкин Максим\n" << "Группа №424\n" << std::endl;
}

void showTaskText() {
	std::cout << "Необходимо разработать класс для указанной\n"
		<< "предметной области. Доступ к данным реализовать с помощью методов Set, Get, Show.\n"
		<< "При выполнении контрольной работы нельзя использовать контейнеры и\n"
		<< "алгоритмы библиотеки STL или аналогичных сторонних библиотек.\n\n"
		<< "Поезд: пункт назначения, номер поезда, время отправления, число общих\n"
		<< "мест, купейных, плацкартных. Создать массив объектов. Реализовать\n"
		<< "возможность получения:\n"
		<< "– списка поездов, следующих до заданного пункта назначения,\n"
		<< "– списка поездов, следующих до заданного пункта назначения и\n"
		<< "отправляющихся после заданного часа,\n"
		<< "– списка поездов, отправляющихся до заданного пункта назначения и\n"
		<< "имеющих общие места.\n" << std::endl;
}

void showMainMenu() {
	std::cout << "Выберите пункт меню:" << std::endl;
	std::cout << "1 - Ввести исходные данные с клавиатуры" << std::endl;
	std::cout << "2 - Загрузить исходные данные из файла" << std::endl;
	std::cout << "3 - Запустить модульные тесты" << std::endl;
	std::cout << "4 - Закончить работу" << std::endl;
}

void showListMenu() {
	std::cout << "Какую информацию вы хотите получить?. Выберите из предложенных ниже." << std::endl;
	std::cout << "1 - Список поездов, следующих до заданного пункта назначения." << std::endl;
	std::cout << "2 - Список поездов, следующих до заданного пункта назначения и отправляющихся после заданного часа." << std::endl;
	std::cout << "3 - Список поездов, следующих до заданного пункта назначения и имеющих общие места." << std::endl;
	std::cout << "4 - Вернуться в главное меню." << std::endl;
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
			std::cout << "Введите пункт назначения поезда: ";
			std::getline(std::cin, destinationKey);
			std::cout << "\nВсе поезда следующие до данного пункта назначения: " << destinationKey << '\n' << std::endl;

			std::pair <Train*, int> sortedTrains = destinationList(trains, numOfTrains, destinationKey);

			showTrainArray(sortedTrains.first, sortedTrains.second);

			std::cout << "Хотите сохранить результаты в файл?\n" << "0 - Нет\n1 - Да" << std::endl;
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
			std::cout << "Введите пункт назначения поезда: ";
			std::getline(std::cin, destinationKey);
			std::cout << "\nПосле какого часа поезд должен отправляться?: ";
			timeKey = getInt();
			while (timeKey < 0 || timeKey > 23) {
				std::cout << "Введенное время некорректно. Пожалуйста введите корректное значение: ";
				timeKey = getInt();
			}
			std::cout << "\nВсе поезда следующие до " << destinationKey << " после " << timeKey << '\n' << std::endl;

			std::pair <Train*, int> sortedTrains = destinationAndTimeList(trains, numOfTrains, destinationKey, timeKey);

			showTrainArray(sortedTrains.first, sortedTrains.second);

			std::cout << "Хотите сохранить результаты в файл?\n" << "0 - Нет\n1 - Да" << std::endl;
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
			std::cout << "Введите пункт назначения поезда: ";
			std::getline(std::cin, destinationKey);
			std::cout << "\nВсе поезда следующие до " << destinationKey << " и имеющие общие места\n" << std::endl;

			std::pair <Train*, int> sortedTrains = destinationAndSeatsList(trains, numOfTrains, destinationKey);

			showTrainArray(sortedTrains.first, sortedTrains.second);

			std::cout << "Хотите сохранить результаты в файл?\n" << "0 - Нет\n1 - Да" << std::endl;
			save = getBool();
			if (save) {
				fileSave(sortedTrains.first, sortedTrains.second);
			}
			delete[]sortedTrains.first;
			sortedTrains.first = nullptr;
		}
		break;
		case back:
			std::cout << "Вы вернулись обратно." << std::endl;
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
			std::cout << "Сколько поездов вы хотите записать? ";
			numOfTrains = getInt();
		}
		switch (programSelection) {
		case start:
			trains = new Train[numOfTrains];
			consoleFilling(&trains, numOfTrains);
			std::cout << std::endl;
			std::cout << "Хотите сохранить данные в файл?\n" << "0 - Нет\n1 - Да" << std::endl;
			save = getBool();
			if (save) {
				fileSave(trains, numOfTrains);
			}
			listSelection(trains, numOfTrains);
			break;
		case fstart:
			std::cout << "Ввести данные из(укажите путь к файлу): ";
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
	std::cout << "До свидания!" << std::endl;
}