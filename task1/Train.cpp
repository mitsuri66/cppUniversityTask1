#include "Train.h"
#include <iostream>

void Train::setDestination(const std::string _destination) {
	Train::destination = _destination;
}

void Train::setTime(const std::string _time) {
	Train::departureTime = _time;
}

void Train::setNumber(const int _number) {
	Train::number = _number;
}

void Train::setSeats(const int _seats) {
	Train::seats = _seats;
}

void Train::setCoupes(const int _coupes) {
	Train::coupes = _coupes;
}

void Train::setReserved(const int _reserved) {
	Train::reserved = _reserved;
}

std::string Train::getDestination() { return Train::destination; }

std::string Train::getTime() { return Train::departureTime; }

int Train::getNumber() { return Train::number; }

int Train::getSeats() { return Train::seats; }

int Train::getCoupes() { return Train::coupes; }

int Train::getReserved() { return Train::reserved; }

void Train::showAll() {
	std::cout << "Пункт назначения поезда: " << destination
		<< "\nВремя отправления: " << departureTime
		<< "\nНомер поезда: " << number
		<< "\nОбщих мест: " << seats
		<< "\nКупейных мест: " << coupes
		<< "\nПлацкартных мест: " << reserved << "\n" << std::endl;
}