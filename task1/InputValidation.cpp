#include <iostream>
#include <string>

template<typename T>
T getInput() {
    T userInput{};
    std::cin >> userInput;
    if (std::cin.fail()) {
        std::cout << "������������ ��������, ��������� �������." << std::endl;
        while (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cin >> userInput;
        }
    }
    std::cin.ignore(INT_MAX, '\n');
    return userInput;
}

int getInt() {
    return getInput<int>();
}

bool getBool() {
    int x = getInt();
    while (x != 0 && x != 1) {
        std::cout << "�� ������ ������ ������ 1 ��� 0";
        x = getInt();
    }
    return static_cast<bool>(x);
}

bool isValidTime(const std::string time) {
    if (time.length() > 5) {
        return false;
    }
    size_t colon_pos = time.find(":");
    if (colon_pos == std::string::npos) {
        return false; // ������ ":" �� ������
    }
    std::string hours = time.substr(0, colon_pos);
    std::string minutes = time.substr(colon_pos + 1);
    if (hours.empty() || minutes.empty()) {
        return false; // ������ �� �������� �����
    }
    int hours_int, minutes_int;
    try {
        hours_int = std::stoi(hours);
        minutes_int = std::stoi(minutes);
    }
    catch ([[maybe_unused]] const std::invalid_argument& e) {
        return false; // ������ �������� ������������ �������
    }
    catch ([[maybe_unused]] const std::out_of_range& e) {
        return false; // ����� ������� �� �������� ���������� ��������
    }
    return hours_int >= 0 && hours_int <= 23 && minutes_int >= 0 && minutes_int <= 59;
}