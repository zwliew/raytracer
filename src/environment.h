#ifndef RAYTRACER_ENVIRONMENT_H
#define RAYTRACER_ENVIRONMENT_H

#include "tuple.h"

class Environment {
public:
    Tuple gravity;
    Tuple wind;

    constexpr Environment(Tuple gravity, Tuple wind) : gravity(gravity), wind(wind) {}
};

#endif //RAYTRACER_ENVIRONMENT_H
