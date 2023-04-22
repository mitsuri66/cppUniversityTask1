#pragma once

#include "Train.h"

void consoleFilling(Train** trains, const int numOfTrains); //функция заполнения массива с консоли
int getSizeFromFile(const std::string filepath); //функция вычисления количества элементов массива в файле
Train* fileInput(int* numOfTrains, const std::string filepath); //функция заполнения массива из файла
void fileSave(Train* trains, const int numOfTrains); //функция сохранения результатов в файл