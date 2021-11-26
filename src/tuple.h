#ifndef RAYTRACER_TUPLE_H
#define RAYTRACER_TUPLE_H


class Tuple {
public:
    float x;
    float y;
    float z;

    Tuple(float x, float y, float z, float w);
    bool is_point() const;
    bool is_vector() const;
private:
    float w;
};


#endif //RAYTRACER_TUPLE_H
