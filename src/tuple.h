#ifndef RAYTRACER_TUPLE_H
#define RAYTRACER_TUPLE_H

#include "numeric.h"

#include <iostream>

template<class T>
class Tuple {
public:
    T x;
    T y;
    T z;
    T w;

    constexpr Tuple(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {}

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

    constexpr Tuple &operator*=(const Tuple &rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        w *= rhs.w;
        return *this;
    }

    constexpr Tuple &operator*=(arithmetic auto rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        w *= rhs;
        return *this;
    }

    constexpr Tuple &operator/=(arithmetic auto rhs) {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        w /= rhs;
        return *this;
    }
};

[[nodiscard]] constexpr Tuple<float> point(float x, float y, float z) {
    return Tuple{x, y, z, 1.0f};
}

[[nodiscard]] constexpr Tuple<float> vector(float x, float y, float z) {
    return Tuple{x, y, z, 0.0f};
}

template<class T>
[[nodiscard]] constexpr Tuple<T> operator+(Tuple<T> lhs, const Tuple<T> &rhs) {
    lhs += rhs;
    return lhs;
}

template<class T>
[[nodiscard]] constexpr Tuple<T> operator-(Tuple<T> lhs, const Tuple<T> &rhs) {
    lhs -= rhs;
    return lhs;
}

template<class T>
[[nodiscard]] constexpr Tuple<T> operator-(Tuple<T> tuple) {
    tuple *= -1;
    return tuple;
}

template<class T>
[[nodiscard]] constexpr Tuple<T> operator*(Tuple<T> lhs, const Tuple<T> &rhs) {
    lhs *= rhs;
    return lhs;
}

template<class T>
[[nodiscard]] constexpr Tuple<T> operator*(Tuple<T> lhs, arithmetic auto rhs) {
    lhs *= rhs;
    return lhs;
}

template<class T>
[[nodiscard]] constexpr Tuple<T> operator/(Tuple<T> lhs, arithmetic auto rhs) {
    lhs /= rhs;
    return lhs;
}

template<class T>
[[nodiscard]] constexpr T abs(const Tuple<T> &tuple) {
    return hypot(tuple.x, tuple.y, tuple.z);
}

template<class T>
[[nodiscard]] constexpr Tuple<T> norm(const Tuple<T> &tuple) {
    return tuple / abs(tuple);
}

template<class T>
[[nodiscard]] constexpr T inner_product(const Tuple<T> &lhs, const Tuple<T> &rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z + lhs.w * rhs.w;
}

template<class T>
[[nodiscard]] constexpr Tuple<T> cross_product(const Tuple<T> &lhs, const Tuple<T> &rhs) {
    return vector(lhs.y * rhs.z - lhs.z * rhs.y, lhs.z * rhs.x - lhs.x * rhs.z, lhs.x * rhs.y - lhs.y * rhs.x);
}

template<class T>
constexpr std::ostream &operator<<(std::ostream &os, const Tuple<T> &tuple) {
    os << "Tuple{" << tuple.x << ", " << tuple.y << ", " << tuple.z << "}";
    return os;
}

#endif //RAYTRACER_TUPLE_H
