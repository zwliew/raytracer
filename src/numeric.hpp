#ifndef RAYTRACER_NUMERIC_H
#define RAYTRACER_NUMERIC_H

#include <algorithm>
#include <cmath>

// Based on
// https://stackoverflow.com/questions/58067259/will-there-be-a-concept-for-arithmetic-types-in-c-standard-library
template <class T>
concept arithmetic = std::is_arithmetic_v<T>;

constexpr float EPSILON = 0.00001f;

// Based on http://realtimecollisiondetection.net/blog/?p=89
[[nodiscard]] constexpr bool equal(float lhs, float rhs) {
  return std::abs(lhs - rhs) <=
         EPSILON * std::max({1.0f, std::abs(lhs), std::abs(rhs)});
}

// Note: beware of floating point imprecision
[[nodiscard]] constexpr float hypot(float x, float y, float z) {
  return sqrt(x * x + y * y + z * z);
}

#endif // RAYTRACER_NUMERIC_H
