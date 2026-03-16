#include "../include/catch_amalgamated.hpp"
#include "../include/ExpressionEngine.hpp"

TEST_CASE("Проверка существования класса ExpressionEngine", "[ExpressionEngine]") {
	ExpressionEngine engine;
}

TEST_CASE("Преобразование простого выражения в ОПЗ", "[ExpressionEngine]") {
    ExpressionEngine engine;
    REQUIRE(engine.toPostfix("1+2") == "1 2 +");
}

TEST_CASE("Преобразование выражения с учетом приоритета", "[ExpressionEngine]") {
    ExpressionEngine engine;
    REQUIRE(engine.toPostfix("3+4*2") == "3 4 2 * +");
}

TEST_CASE("Вычисление простого выражения в ОПЗ", "[ExpressionEngine]") {
    ExpressionEngine engine;
    REQUIRE_THAT(engine.evaluate("42 69 +"), Catch::Matchers::WithinRel(111.0, 0.0001));
}
