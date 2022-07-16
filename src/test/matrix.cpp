#include "matrix.hpp"
#include "numeric.hpp"

#include <catch2/catch.hpp>

SCENARIO("Constructing and inspecting a 4x4 matrix") {
  GIVEN("A matrix M and some definitions") {
    const Matrix<float, 4> M = {1.0f,  2.0f,  3.0f,  4.0f,  5.5f,  6.5f,
                                7.5f,  8.5f,  9.0f,  10.0f, 11.0f, 12.0f,
                                13.5f, 14.5f, 15.5f, 16.5f};

    THEN("M has the correct attributes") {
      CHECK(equal(M[{0, 0}], 1.0f));
      CHECK(equal(M[{0, 3}], 4.0f));
      CHECK(equal(M[{1, 0}], 5.5f));
      CHECK(equal(M[{1, 2}], 7.5f));
      CHECK(equal(M[{2, 2}], 11.0f));
      CHECK(equal(M[{3, 0}], 13.5f));
      CHECK(equal(M[{3, 2}], 15.5f));
    }
  }
}

SCENARIO("A 2x2 matrix ought to be representable") {
  GIVEN("A 2x2 matrix M") {
    const Matrix<float, 2> M = {-3, 5, 1, -2};

    THEN("M has the correct attributes") {
      CHECK(equal(M[{0, 0}], -3));
      CHECK(equal(M[{0, 1}], 5));
      CHECK(equal(M[{1, 0}], 1));
      CHECK(equal(M[{1, 1}], -2));
    }
  }
}

SCENARIO("A 3x3 matrix ought to be representable") {
  GIVEN("A 3x3 matrix M") {
    const Matrix<float, 3> M = {-3, 5, 0, 1, -2, -7, 0, 1, 1};

    THEN("M has the correct attributes") {
      CHECK(equal(M[{0, 0}], -3));
      CHECK(equal(M[{1, 1}], -2));
      CHECK(equal(M[{2, 2}], 1));
    }
  }
}

SCENARIO("Matrix equality with identical matrices") {
  GIVEN("A 4x4 matrix A and an identical 4x4 matrix B") {
    const Matrix<int, 4> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
    const Matrix<int, 4> B = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};

    THEN("A = B") { CHECK(A == B); }
  }
}

SCENARIO("Matrix equality with different matrices") {
  GIVEN("A 4x4 matrix A and a different 4x4 matrix B") {
    const Matrix<int, 4> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
    const Matrix<int, 4> B = {2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    THEN("A = B") { CHECK(A != B); }
  }
}

SCENARIO("Multiplying two matrices") {
  GIVEN("Two matrices A and B") {
    const Matrix<int, 4> A = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 4, 3, 2};
    const Matrix<int, 4> B = {-2, 1, 2, 3, 3, 2, 1, -1, 4, 3, 6, 5, 1, 2, 7, 8};

    THEN("A * B has the correct elements") {
      const Matrix<int, 4> expected = {20, 22, 50,  48,  44, 54, 114, 108,
                                       40, 58, 110, 102, 16, 26, 46,  42};
      CHECK(A * B == expected);
    }
  }
}
