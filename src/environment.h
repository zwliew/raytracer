#ifndef RAYTRACER_ENVIRONMENT_H
#define RAYTRACER_ENVIRONMENT_H

#include "tuple.h"

class Environment {
public:
    Tuple<float> gravity;
    Tuple<float> wind;

    constexpr Environment(Tuple<float> gravity, Tuple<float> wind) : gravity(gravity), wind(wind) {}
};

#endif //RAYTRACER_ENVIRONMENT_H
