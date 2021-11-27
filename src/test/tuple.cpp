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

SCENARIO("Adding two tuples") {
    GIVEN("A vector a2 and a point a1") {
        const Tuple a1{3, -2, 5, 1};
        const Tuple a2{-2, 3, 1, 0};
        const Tuple expected{1, 1, 6, 1};

        THEN("Adding a1 and a2 gives the correct point") {
            CHECK(a1 + a2 == expected);
        }
    }
}

SCENARIO("Subtracting two points") {
    GIVEN("Two points p1 and p2") {
        const auto p1 = point(3, 2, 1);
        const auto p2 = point(5, 6, 7);
        const auto expected = vector(-2, -4, -6);

        THEN("Subtracting p2 from p1 gives the correct vector") {
            CHECK(p1 - p2 == expected);
        }
    }
}

SCENARIO("Subtracting a vector from a point") {
    GIVEN("A point p and a vector v") {
        const auto p = point(3, 2, 1);
        const auto v = vector(5, 6, 7);
        const auto expected = point(-2, -4, -6);

        THEN("Subtracting v from p gives the correct point") {
            CHECK(p - v == expected);
        }
    }
}

SCENARIO("Subtracting two vectors") {
    GIVEN("Two vectors v1 and v2") {
        const auto v1 = vector(3, 2, 1);
        const auto v2 = vector(5, 6, 7);
        const auto expected = vector(-2, -4, -6);

        THEN("Subtracting v2 from v1 returns the correct vector") {
            CHECK(v1 - v2 == expected);
        }
    }
}

SCENARIO("Subtracting a vector from the zero vector") {
    GIVEN("A vector v and the zero vector zero") {
        const auto v = vector(1, -2, 3);
        const auto zero = vector(0, 0, 0);
        const auto expected = vector(-1, 2, -3);

        THEN("Subtracting v from zero returns the negated vector") {
            CHECK(zero - v == expected);
        }
    }
}

SCENARIO("Negating a tuple") {
    GIVEN("a = tuple(1, -2, 3, -4)") {
        const Tuple a{1, -2, 3, -4};
        const Tuple expected{-1, 2, -3, 4};

        THEN("-a == tuple(-1, 2, -3, 4)") {
            CHECK(-a == expected);
        }
    }
}

SCENARIO("Multiplying a tuple by a scalar") {
    GIVEN("a = tuple(1, -2, 3, -4)") {
        const Tuple a{1, -2, 3, -4};
        const Tuple expected{3.5, -7, 10.5, -14};

        THEN("a * 3.5 == tuple(3.5, -7, 10.5, -14)") {
            CHECK(a * 3.5 == expected);
        }
    }
}

SCENARIO("Multiplying a tuple by a fraction") {
    GIVEN("a = tuple(1, -2, 3, -4") {
        const Tuple a{1, -2, 3, -4};
        const Tuple expected{0.5, -1, 1.5, -2};

        THEN("a * 0.5 == tuple(0.5, -1, 1.5, -2)") {
            CHECK(a * 0.5 == expected);
        }
    }
}

SCENARIO("Dividing a tuple by a scalar") {
    GIVEN("a = tuple(1, -2, 3, -4") {
        const Tuple a{1, -2, 3, -4};
        const Tuple expected{0.5, -1, 1.5, -2};

        THEN("a / 2 == tuple(0.5, -1, 1.5, -2)") {
            CHECK(a / 2 == expected);
        }
    }
}