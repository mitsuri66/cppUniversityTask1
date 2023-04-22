#pragma once
#include "Train.h"

//��� ������� ���������� ��������� pair ������� �������� ��������� �� ������ � ������ ����� �������

//������� ���������� �� ����� ����������
std::pair<Train*, int> destinationList(Train* trainsArray, const int size, const std::string destinationKey);
//������� ���������� �� ����� ���������� � �������
std::pair<Train*, int> destinationAndTimeList(Train* trainsArray, const int size, const std::string destinationKey, const int timeKey);
//������� ���������� �� ����� ���������� � ���-�� ����� ����
std::pair<Train*, int> destinationAndSeatsList(Train* trainsArray, const int size, const std::string destinationKey);