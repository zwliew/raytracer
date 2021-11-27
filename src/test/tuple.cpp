#include "tuple.h"

#include <catch2/catch.hpp>

SCENARIO("A tuple with w=1.0 is a point") {
    GIVEN("a = tuple(4.3, -4.2, 3.1, 1.0)") {
        const Tuple a{4.3, -4.2, 3.1, 1.0};

        THEN("a is a point with the correct attributes") {
            CHECK(a.x == 4.3f);
            CHECK(a.y == -4.2f);
            CHECK(a.z == 3.1f);
            CHECK(a.is_point());
            CHECK(!a.is_vector());
        }
    }
}

SCENARIO("A tuple with w=0 is a vector") {
    GIVEN("a = tuple(4.3, -4.2, 3.1, 0)") {
        const Tuple a{4.3f, -4.2f, 3.1f, 0.0f};

        THEN("a is a vector with the correct attributes") {
            CHECK(a.x == 4.3f);
            CHECK(a.y == -4.2f);
            CHECK(a.z == 3.1f);
            CHECK(!a.is_point());
            CHECK(a.is_vector());
        }
    }
}

SCENARIO("point() creates tuples with w=1.0") {
    GIVEN("p = point(4, -4, 3)") {
        const auto p = point(4, -3, 3);
        const Tuple expected{4, -3, 3, 1};

        THEN("p = tuple(4, -4, 3, 1)") {
            CHECK(p == expected);
        }
    }
}

SCENARIO("vector() creates tuples with w=0") {
    GIVEN("v = vector(4, -3, 3") {
        const auto v = vector(4, -3, 3);
        const Tuple expected{4, -3, 3, 0};

        THEN("v = tuple(4, -3, 3, 0)") {
            CHECK(v == expected);
        }
    }
}