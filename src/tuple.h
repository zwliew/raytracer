#ifndef RAYTRACER_TUPLE_H
#define RAYTRACER_TUPLE_H

class Tuple {
public:
    float x;
    float y;
    float z;
    float w;

    constexpr Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    [[nodiscard]] bool is_point() const;

    [[nodiscard]] bool is_vector() const;

    [[nodiscard]] bool operator==(Tuple rhs) const;

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

Tuple point(float x, float y, float z);

Tuple vector(float x, float y, float z);

// TODO: make this more efficient by reducing copies:
// 1. take rhs by const reference.
// 2. take lhs by copy and modify it in-place before returning it.
constexpr Tuple operator+(Tuple lhs, Tuple rhs) {
    return Tuple{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
}

constexpr Tuple operator-(Tuple lhs, Tuple rhs) {
    return Tuple{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
}

constexpr Tuple operator-(Tuple tuple) {
    return Tuple{-tuple.x, -tuple.y, -tuple.z, -tuple.w};
}

constexpr Tuple operator*(Tuple lhs, float rhs) {
    lhs *= rhs;
    return lhs;
}

constexpr Tuple operator/(Tuple lhs, float rhs) {
    lhs /= rhs;
    return lhs;
}

#endif //RAYTRACER_TUPLE_H
