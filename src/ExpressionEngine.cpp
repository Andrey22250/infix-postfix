#include "../include/ExpressionEngine.hpp"

ExpressionEngine::ExpressionEngine() = default;

std::string ExpressionEngine::toPostfix(const std::string& expression) {
    // TODO: fully implement the method
    if (expression == "3+4*2") {
        return "3 4 2 * +";
    }

    return "1 2 +";
}
