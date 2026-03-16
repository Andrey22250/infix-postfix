#include <iostream>
#include <Windows.h>
#include <string>
#include "../include/ExpressionEngine.hpp"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    ExpressionEngine engine;
    std::string input;
    int choice;

    while (true) {
        std::cout << "Введите выражение (или 'exit' для выхода): ";
        std::getline(std::cin, input);

        if (input == "exit") break;
        if (input.empty()) continue;

        std::cout << "Выберите операцию:\n";
        std::cout << "1. Преобразовать в ОПЗ (постфиксная запись)\n";
        std::cout << "2. Вычислить результат\n";
        std::cout << "Ваш выбор: ";
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string rpn = engine.toPostfix(input);
            std::cout << "Результат в ОПЗ: " << rpn << std::endl << std::endl;
        }
        else if (choice == 2) {
            double result = engine.evaluate(input);
            std::cout << "Результат вычисления: " << result << std::endl << std::endl;
        }
        else {
            std::cout << "Ошибка: Неверный выбор операции.\n\n";
        }
    }

    std::cout << "Программа завершена.\n";
    return 0;
}
