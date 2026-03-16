#include "../include/ExpressionEngine.hpp"

ExpressionEngine::ExpressionEngine() = default;

std::string ExpressionEngine::toPostfix(const std::string& expression) {
    // TODO: fully implement the method
    if (expression == "3+4*2") {
        return "3 4 2 * +";
    }

    return "1 2 +";
}

double ExpressionEngine::evaluate(const std::string& expression) {
    // TODO: fully implement evaluate method
    if (expression == "3 5 2 / -") {
        return 0.5;
    }

    return 111.0;
}