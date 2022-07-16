#ifndef RAYTRACER_PROJECTILE_H
#define RAYTRACER_PROJECTILE_H

#include "environment.hpp"
#include "tuple.hpp"

class Projectile {
public:
  Tuple<float> position;
  Tuple<float> velocity;

  constexpr Projectile(Tuple<float> position, Tuple<float> velocity)
      : position(position), velocity(velocity) {}
};

[[nodiscard]] constexpr Projectile tick(const Environment &env,
                                        const Projectile &proj) {
  return Projectile{proj.position + proj.velocity,
                    proj.velocity + env.gravity + env.wind};
}

#endif // RAYTRACER_PROJECTILE_H
