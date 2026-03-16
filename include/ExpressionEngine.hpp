#ifndef EXPRESSION_ENGINE_HPP
#define EXPRESSION_ENGINE_HPP

#include <string>

class ExpressionEngine {
public:
    ExpressionEngine();
    
/**
     * Преобразует математическое выражение из инфиксной записи в постфиксную (ОПЗ).
     * @param expression Строка с математическим выражением (например, "3+4*2").
     * Должна содержать только цифры, операторы +,-,*,/ и скобки.
     * @return Строка в формате обратной польской записи, где токены разделены пробелами.
*/
    std::string toPostfix(const std::string& expression);
};

#endif // EXPRESSION_ENGINE_HPP
