#include "../include/ExpressionEngine.hpp"
#include <stack>
#include <stdexcept>
#include <sstream>

// Вспомогательная функция для определения приоритета операторов
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

ExpressionEngine::ExpressionEngine() = default;

std::string ExpressionEngine::toPostfix(const std::string& expression) {
    std::string result;
    std::stack<char> operators;

    for (size_t i = 0; i < expression.length(); ++i) {
        char c = expression[i];

        if (std::isspace(c)) continue;

        // Если число — считываем его целиком
        if (std::isdigit(c)) {
            while (i < expression.length() && (std::isdigit(expression[i]) || expression[i] == '.')) {
                result += expression[i++];
            }

            result += ' ';
            --i;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                result += operators.top();
                result += ' ';
                operators.pop();
            }

            if (operators.empty()) throw std::invalid_argument("Некорректные скобки");
            operators.pop(); // Удаляем '('
        }
        else { // Оператор
            while (!operators.empty() && getPriority(operators.top()) >= getPriority(c)) {
                result += operators.top();
                result += ' ';
                operators.pop();
            }

            operators.push(c);
        }
    }

    while (!operators.empty()) {
        if (operators.top() == '(') throw std::invalid_argument("Некорректные скобки");
        result += operators.top();
        result += ' ';
        operators.pop();
    }

    // Удаляем лишний пробел в конце
    if (!result.empty()) result.pop_back();
    return result;
}

double ExpressionEngine::evaluate(const std::string& expression) {
    std::stringstream ss(expression);
    std::stack<double> values;
    std::string token;

    while (ss >> token) {
        if (std::isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            values.push(std::stod(token));
        }
        else {
            if (values.size() < 2) throw std::runtime_error("Некорретное входное выражение");

            double b = values.top(); values.pop();
            double a = values.top(); values.pop();

            if (token == "+") values.push(a + b);
            else if (token == "-") values.push(a - b);
            else if (token == "*") values.push(a * b);
            else if (token == "/") {
                if (b == 0) throw std::runtime_error("Деление на 0");
                values.push(a / b);
            }
        }
    }

    if (values.size() != 1) throw std::runtime_error("Некорретное входное выражение");
    return values.top();
}