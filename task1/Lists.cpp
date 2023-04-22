#include "InputValidation.h"
#include "Lists.h"
#include <iostream>
#include <string>

std::pair <Train*, int> destinationList(Train* trainsArray, const int size, const std::string destinationKey) {
	int newSize{};
	int i{};
	int iter{};
	for (i = 0; i < size; i++) {
		if (trainsArray[i].getDestination() == destinationKey)
			newSize++;
	}

	Train* tempArr = new Train[newSize];

	for (i = 0; i < size; i++) {
		if (iter < newSize) {
			if (trainsArray[i].getDestination() == destinationKey) {
				tempArr[iter] = trainsArray[i];
				++iter;
			}
		}
		else {
			break;
		}
	}
	std::pair <Train*, int> result = std::make_pair(tempArr, newSize); 
	return result;
}

std::pair<Train*, int> destinationAndTimeList(Train* trainsArray, const int size, const std::string destinationKey, const int timeKey) {
	int newSize{};
	int hoursDefault{};
	int i{};
	int iter{};
	Train* tempArr = nullptr;
	for (i = 0; i < size; i++) {
		hoursDefault = stoi((trainsArray[i].getTime()).substr(0, 2));
		if (trainsArray[i].getDestination() == destinationKey && hoursDefault >= timeKey)
			newSize++;
	}

	tempArr = new Train[newSize];

	for (i = 0; i < size; i++) {
		if (iter < newSize) {
			hoursDefault = stoi((trainsArray[i].getTime()).substr(0, 2));
			if (trainsArray[i].getDestination() == destinationKey && hoursDefault >= timeKey) {
				tempArr[iter] = trainsArray[i];
				iter++;
			}
		}
		else {
			break;
		}
	}
	std::pair <Train*, int> result = std::make_pair(tempArr, newSize);
	return result;
}

std::pair<Train*, int> destinationAndSeatsList(Train* trainsArray, const int size, const std::string destinationKey) {
	int newSize{};
	int i{};
	int iter{};
	for (i = 0; i < size; i++) {
		if (trainsArray[i].getDestination() == destinationKey && trainsArray[i].getSeats() > 0)
			newSize++;
	}

	Train* tempArr = new Train[newSize];

	for (i = 0; i < size; i++) {
		if (iter < newSize) {
			if (trainsArray[i].getDestination() == destinationKey) {
				tempArr[iter] = trainsArray[i];
				++iter;
			}
		}
		else {
			break;
		}
	}
	std::pair <Train*, int> result = std::make_pair(tempArr, newSize);
	return result;
}