#pragma once

#include "Train.h"

void consoleFilling(Train** trains, const int numOfTrains); //������� ���������� ������� � �������
int getSizeFromFile(const std::string filepath); //������� ���������� ���������� ��������� ������� � �����
Train* fileInput(int* numOfTrains, const std::string filepath); //������� ���������� ������� �� �����
void fileSave(Train* trains, const int numOfTrains); //������� ���������� ����������� � ����