#include "../include/catch_amalgamated.hpp"
#include "../include/ExpressionEngine.hpp"

TEST_CASE("Проверка существования класса ExpressionEngine", "[ExpressionEngine]") {
	ExpressionEngine engine;
}

TEST_CASE("Преобразование простого выражения в ОПЗ", "[ExpressionEngine]") {
    ExpressionEngine engine;
    REQUIRE(engine.toPostfix("1+2") == "1 2 +");
}
