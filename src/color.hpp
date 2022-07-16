#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include "tuple.hpp"

class Color : public Tuple<float> {
public:
  constexpr Color() : Tuple(0, 0, 0, 0) {}

  constexpr Color(float r, float g, float b) : Tuple(r, g, b, 0) {}

  [[nodiscard]] constexpr float r() const { return x; }

  [[nodiscard]] constexpr float g() const { return y; }

  [[nodiscard]] constexpr float b() const { return z; }
};

[[nodiscard]] constexpr uint8_t to_byte(float colorFloat) {
  return static_cast<uint8_t>(
      std::clamp(std::round(colorFloat * 255.0f), 0.0f, 255.0f));
}

#endif // RAYTRACER_COLOR_H
