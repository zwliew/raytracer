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

Tuple point(float x, float y, float z);

Tuple vector(float x, float y, float z);

constexpr Tuple operator+(Tuple lhs, const Tuple &rhs) {
    lhs += rhs;
    return lhs;
}

constexpr Tuple operator-(Tuple lhs, const Tuple &rhs) {
    lhs -= rhs;
    return lhs;
}

constexpr Tuple operator-(Tuple tuple) {
    tuple *= -1;
    return tuple;
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
