#include "color.h"

#include <catch2/catch.hpp>

SCENARIO("Colors are (red, green, blue) tuples") {
    GIVEN("c = color(-0.5, 0.4, 1.7)") {
        constexpr Color c{-0.5f, 0.4f, 1.7f};

        THEN("c has the correct r, g, and b components") {
            CHECK(equal(c.r(), -0.5f));
            CHECK(equal(c.g(), 0.4f));
            CHECK(equal(c.b(), 1.7f));
        }
    }
}