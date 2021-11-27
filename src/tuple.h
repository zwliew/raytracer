#ifndef RAYTRACER_TUPLE_H
#define RAYTRACER_TUPLE_H

#include "numeric.h"

class Tuple {
public:
    float x;
    float y;
    float z;
    float w;

    constexpr Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    [[nodiscard]] constexpr bool is_point() const {
        return equal(w, 1.0f);
    }

    [[nodiscard]] constexpr bool is_vector() const {
        return equal(w, 0.0f);
    }

    [[nodiscard]] bool operator==(const Tuple rhs) const {
        return equal(x, rhs.x) && equal(y, rhs.y) && equal(z, rhs.z) && equal(w, rhs.w);
    }

    constexpr Tuple &operator+=(const Tuple &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }

    constexpr Tuple &operator-=(const Tuple &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }

    constexpr Tuple &operator*=(float rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        w *= rhs;
        return *this;
    }

    constexpr Tuple &operator/=(float rhs) {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        w /= rhs;
        return *this;
    }
};

[[nodiscard]] constexpr Tuple point(float x, float y, float z) {
    return Tuple{x, y, z, 1.0f};
}

[[nodiscard]] constexpr Tuple vector(float x, float y, float z) {
    return Tuple{x, y, z, 0.0f};
}

[[nodiscard]] constexpr Tuple operator+(Tuple lhs, const Tuple &rhs) {
    lhs += rhs;
    return lhs;
}

[[nodiscard]] constexpr Tuple operator-(Tuple lhs, const Tuple &rhs) {
    lhs -= rhs;
    return lhs;
}

[[nodiscard]] constexpr Tuple operator-(Tuple tuple) {
    tuple *= -1;
    return tuple;
}

[[nodiscard]] constexpr Tuple operator*(Tuple lhs, float rhs) {
    lhs *= rhs;
    return lhs;
}

[[nodiscard]] constexpr Tuple operator/(Tuple lhs, float rhs) {
    lhs /= rhs;
    return lhs;
}

[[nodiscard]] constexpr float abs(const Tuple &tuple) {
    return hypot(tuple.x, tuple.y, tuple.z);
}

[[nodiscard]] constexpr Tuple norm(const Tuple &tuple) {
    return tuple / abs(tuple);
}

[[nodiscard]] constexpr float inner_product(const Tuple &lhs, const Tuple &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

[[nodiscard]] constexpr Tuple cross_product(const Tuple &lhs, const Tuple &rhs) {
    return vector(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}

#endif //RAYTRACER_TUPLE_H
