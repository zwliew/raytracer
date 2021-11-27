#ifndef RAYTRACER_NUMERIC_H
#define RAYTRACER_NUMERIC_H

#include <cstdlib>
#include <algorithm>

constexpr float EPSILON = 0.00001f;

// Based on http://realtimecollisiondetection.net/blog/?p=89
[[nodiscard]] constexpr bool equal(float lhs, float rhs) {
    return std::abs(lhs - rhs) <= EPSILON * std::max({1.0f, std::abs(lhs), std::abs(rhs)});
}

#endif //RAYTRACER_NUMERIC_H
