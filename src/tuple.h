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
};

Tuple point(float x, float y, float z);

Tuple vector(float x, float y, float z);

constexpr Tuple operator+(Tuple lhs, Tuple rhs) {
    return Tuple{lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z, lhs.w + rhs.w};
}

constexpr Tuple operator-(Tuple lhs, Tuple rhs) {
    return Tuple{lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z, lhs.w - rhs.w};
}

constexpr Tuple operator-(Tuple tuple) {
    return Tuple{-tuple.x, -tuple.y, -tuple.z, -tuple.w};
}

#endif //RAYTRACER_TUPLE_H
