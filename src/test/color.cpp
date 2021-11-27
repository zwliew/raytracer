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

SCENARIO("Adding colors") {
    GIVEN("Two colors c1 and c2") {
        constexpr Color c1{0.9f, 0.6f, 0.75f};
        constexpr Color c2{0.7f, 0.1f, 0.25f};

        THEN("c1 + c2 == Color(1.6, 0.7, 1.0)") {
            CHECK(c1 + c2 == Color{1.6f, 0.7f, 1.0f});
        }
    }
}

SCENARIO("Subtracting colors") {
    GIVEN("Two colors c1 and c2") {
        constexpr Color c1{0.9f, 0.6f, 0.75f};
        constexpr Color c2{0.7f, 0.1f, 0.25f};

        THEN("c1 - c2 == Color(0.2, 0.5, 0.5)") {
            CHECK(c1 - c2 == Color{0.2f, 0.5f, 0.5f});
        }
    }
}

SCENARIO("Multiplying a color by a scalar") {
    GIVEN("c = Color(0.2, 0.3, 0.4)") {
        constexpr Color c{0.2f, 0.3f, 0.4f};

        THEN("c * 2 == Color(0.4, 0.6, 0.8)") {
            CHECK(c * 2 == Color{0.4f, 0.6f, 0.8f});
        }
    }
}

SCENARIO("Multiplying colors") {
    GIVEN("Two colors c1 and c2") {
        constexpr Color c1{1.0f, 0.2f, 0.4f};
        constexpr Color c2{0.9f, 1.0f, 0.1f};

        THEN("c1 * c2 == Color(0.9, 0.2, 0.4)") {
            CHECK(c1 * c2 == Color{0.9f, 0.2f, 0.04f});
        }
    }
}