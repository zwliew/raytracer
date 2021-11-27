#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include "tuple.h"

class Color : public Tuple {
public:
    constexpr Color(float r, float g, float b) : Tuple(r, g, b, 0) {}

    [[nodiscard]] constexpr float r() const {
        return x;
    }

    [[nodiscard]] constexpr float g() const {
        return y;
    }

    [[nodiscard]] constexpr float b() const {
        return z;
    }

    constexpr Color &operator*=(const Color &rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }
};

[[nodiscard]] Color operator*(Color lhs, const Color &rhs) {
    lhs *= rhs;
    return lhs;
}

#endif //RAYTRACER_COLOR_H
