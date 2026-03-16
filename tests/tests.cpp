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

TEST_CASE("Вычисление сложного выражения в ОПЗ", "[ExpressionEngine]") {
    ExpressionEngine engine;
    REQUIRE_THAT(engine.evaluate("3 5 2 / -"), Catch::Matchers::WithinRel(0.5, 0.0001));
}

TEST_CASE("Точность вычисления вещественных чисел", "[ExpressionEngine]") {
    ExpressionEngine engine;

    SECTION("Деление с остатком") {
        REQUIRE_THAT(engine.evaluate("5 2 /"), Catch::Matchers::WithinRel(2.5, 0.0001));
    }

    SECTION("Сложное выражение в ОПЗ") {
        // (3 + 4 * 2) / (1 - 5) = 11 / -4 = -2.75
        REQUIRE_THAT(engine.evaluate("3 4 2 * + 1 5 - /"), Catch::Matchers::WithinRel(-2.75, 0.0001));
    }
}

TEST_CASE("Обработка ошибок и исключений", "[ExpressionEngine]") {
    ExpressionEngine engine;

    SECTION("Деление на ноль") {
        REQUIRE_THROWS_AS(engine.evaluate("10 0 /"), std::runtime_error);
    }

    SECTION("Некорректные скобки") {
        REQUIRE_THROWS_AS(engine.toPostfix("(1+2"), std::invalid_argument);
        REQUIRE_THROWS_AS(engine.toPostfix("1+2)"), std::invalid_argument);
    }

    SECTION("Некорректное входное выражение") {
        REQUIRE_THROWS_AS(engine.evaluate("1 2 + +"), std::runtime_error);
        REQUIRE_THROWS_AS(engine.evaluate("1 2 3 +"), std::runtime_error);
    }
}