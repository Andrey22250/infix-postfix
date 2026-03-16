#ifndef EXPRESSION_ENGINE_HPP
#define EXPRESSION_ENGINE_HPP

#include <string>

class ExpressionEngine {
public:
    ExpressionEngine();
    std::string toPostfix(const std::string& expression);
};

#endif // EXPRESSION_ENGINE_HPP
