#ifndef RAYTRACER_PROJECTILE_H
#define RAYTRACER_PROJECTILE_H

#include "tuple.h"
#include "environment.h"

class Projectile {
public:
    Tuple position;
    Tuple velocity;

    constexpr Projectile(Tuple position, Tuple velocity) : position(position), velocity(velocity) {}
};

[[nodiscard]] constexpr Projectile tick(const Environment &env, const Projectile &proj) {
    return Projectile{
            proj.position + proj.velocity,
            proj.velocity + env.gravity + env.wind
    };
}

#endif //RAYTRACER_PROJECTILE_H
