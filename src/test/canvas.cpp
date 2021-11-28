#include "color.h"
#include "canvas.h"

#include <catch2/catch.hpp>

SCENARIO("Creating a canvas") {
    GIVEN("c = canvas(10, 20)") {
        const Canvas c{10, 20};
        constexpr Color expected_color{0, 0, 0};

        THEN("c is a Canvas with the correct attributes") {
            CHECK(c.width == 10);
            CHECK(c.height == 20);

            for (size_t x = 0; x < 10; ++x) {
                for (size_t y = 0; y < 20; ++y) {
                    CHECK(c[{x, y}] == expected_color);
                }
            }
        }
    }
}

SCENARIO("Writing pixels to a canvas") {
    GIVEN("A canvas c and a color red") {
        Canvas c{10, 20};
        constexpr Color red{1, 0, 0};

        WHEN("c.write(2, 3, red)") {
            c[{2, 3}] = red;

            THEN("c.at(2, 3) == red") {
                CHECK(c[{2, 3}] == red);
            }
        }
    }
}

SCENARIO("Constructing the PPM header") {
    GIVEN("c = canvas(5, 3)") {
        const Canvas c{5, 3};

        WHEN("ppm = canvas_to_ppm(c)") {
            const auto ppm = to_ppm(c);
            const auto expected = "P3\n5 3\n255\n";

            THEN("ppm contains the correct header") {
                CHECK(ppm.starts_with(expected));
            }
        }
    }
}