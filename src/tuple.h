#ifndef RAYTRACER_TUPLE_H
#define RAYTRACER_TUPLE_H


class Tuple {
public:
    float x;
    float y;
    float z;

    Tuple(float x, float y, float z, float w);

    [[nodiscard]] bool is_point() const;

    [[nodiscard]] bool is_vector() const;

    [[nodiscard]] bool operator==(Tuple rhs) const;

private:
    float w;
};

Tuple point(float x, float y, float z);
Tuple vector(float x, float y, float z);

#endif //RAYTRACER_TUPLE_H
