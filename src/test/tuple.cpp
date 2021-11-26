#include "tuple.h"

#include <catch2/catch.hpp>

SCENARIO("A tuple with w=1 is a point") {
    GIVEN("a = tuple(4.3, -4.2, 3.1, 1.0)") {
        const Tuple a{4.3, -4.2, 3.1, 1.0};

        THEN("a is a point with the correct attributes") {
            CHECK(a.x == 4.3f);
            CHECK(a.y == -4.2f);
            CHECK(a.z == 3.1f);
            CHECK(a.is_point());
        }
    }
}

SCENARIO("A tuple with w=0 is a vector") {
    GIVEN("a = tuple(4.3, -4.2, 3.1, 0)") {
        const Tuple a{4.3, -4.2, 3.1, 0};

        THEN("a is a vector with the correct attributes") {
            CHECK(a.x == 4.3f);
            CHECK(a.y == -4.2f);
            CHECK(a.z == 3.1f);
            CHECK(a.is_vector());
        }
    }
}