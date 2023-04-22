#pragma once
#include "Train.h"

//все функции возвращают структуру pair которая содержит указатель на массив и размер этого массива

//функция сортировки по месту назначения
std::pair<Train*, int> destinationList(Train* trainsArray, const int size, const std::string destinationKey);
//функция сортировки по месту назначения и времени
std::pair<Train*, int> destinationAndTimeList(Train* trainsArray, const int size, const std::string destinationKey, const int timeKey);
//функция сортировки по месту назначения и кол-ву общих мест
std::pair<Train*, int> destinationAndSeatsList(Train* trainsArray, const int size, const std::string destinationKey);