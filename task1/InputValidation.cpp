#include <iostream>
#include <string>

template<typename T>
T getInput() {
    T userInput{};
    std::cin >> userInput;
    if (std::cin.fail()) {
        std::cout << "Некорректное значение, повторите попытку." << std::endl;
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
        std::cout << "Вы можете ввести только 1 или 0";
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
        return false; // символ ":" не найден
    }
    std::string hours = time.substr(0, colon_pos);
    std::string minutes = time.substr(colon_pos + 1);
    if (hours.empty() || minutes.empty()) {
        return false; // строка не содержит чисел
    }
    int hours_int, minutes_int;
    try {
        hours_int = std::stoi(hours);
        minutes_int = std::stoi(minutes);
    }
    catch ([[maybe_unused]] const std::invalid_argument& e) {
        return false; // строка содержит недопустимые символы
    }
    catch ([[maybe_unused]] const std::out_of_range& e) {
        return false; // число выходит за диапазон допустимых значений
    }
    return hours_int >= 0 && hours_int <= 23 && minutes_int >= 0 && minutes_int <= 59;
}