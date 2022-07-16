#include "canvas.hpp"
#include "color.hpp"

#include <catch2/catch.hpp>

SCENARIO("Creating a canvas") {
  GIVEN("c = canvas(10, 20)") {
    const Canvas c{10, 20};
    constexpr Color expected_color{0, 0, 0};

    THEN("c is a Canvas with the correct attributes") {
      CHECK(c.width == 10);
      CHECK(c.height == 20);

      for (size_t y = 0; y < 20; ++y) {
        for (size_t x = 0; x < 10; ++x) {
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

      THEN("c.at(2, 3) == red") { CHECK(c[{2, 3}] == red); }
    }
  }
}

SCENARIO("Constructing the PPM header") {
  GIVEN("c = canvas(5, 3)") {
    const Canvas c{5, 3};

    WHEN("ppm = canvas_to_ppm(c)") {
      const auto ppm = to_ppm(c);

      THEN("ppm contains the correct header") {
        constexpr auto expected = "P3\n5 3\n255\n";
        CHECK(ppm.starts_with(expected));
      }
    }
  }
}

SCENARIO("Constructing the PPM pixel data") {
  GIVEN("A canvas c and three colors c1, c2, c3") {
    Canvas c{5, 3};
    constexpr Color c1{1.5, 0, 0};
    constexpr Color c2{0, 0.5, 0};
    constexpr Color c3{-0.5, 0, 1};

    WHEN("The colors are written to three distinct pixels") {
      c[{0, 0}] = c1;
      c[{2, 1}] = c2;
      c[{4, 2}] = c3;

      THEN("to_ppm(c) returns the correct PPM contents") {
        constexpr auto expected =
            "255 0 0 0 0 0 0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 128 0 0 0 0 0 0 "
            "0\n0 0 0 0 0 0 0 0 0 0 0 0 0 0 255\n";
        CHECK(to_ppm(c).ends_with(expected));
      }
    }
  }
}

SCENARIO("Splitting long lines in PPM files") {
  GIVEN("c = canvas(10, 2)") {
    Canvas c{10, 2};

    WHEN("Every pixel of c is set to color(1, 0.8, 0.6) and ppm = "
         "canvas_to_ppm(c)") {
      constexpr Color color{1.0f, 0.8f, 0.6f};
      for (size_t y = 0; y < c.height; ++y) {
        for (size_t x = 0; x < c.width; ++x) {
          c[{x, y}] = color;
        }
      }
      const auto ppm = to_ppm(c);

      THEN("Long lines in ppm are split correctly") {
        constexpr auto expected =
            "255 204 153 255 204 153 255 204 153 255 204 153 255 204 153 255 "
            "204\n153 255 204 153 255 204 153 255 204 153 255 204 153\n255 204 "
            "153 255 204 153 255 204 153 255 204 153 255 204 153 255 204\n153 "
            "255 204 153 255 204 153 255 204 153 255 204 153\n";
        CHECK(ppm.ends_with(expected));
      }
    }
  }
}

SCENARIO("PPM files are terminated by a newline character") {
  GIVEN("c = canvas(5, 3)") {
    const Canvas c{5, 3};

    WHEN("ppm = canvas_to_ppm(c)") {
      const auto ppm = to_ppm(c);

      THEN("ppm ends with a newline character") { CHECK(ppm.ends_with("\n")); }
    }
  }
}
