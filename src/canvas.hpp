#ifndef RAYTRACER_CANVAS_H
#define RAYTRACER_CANVAS_H

#include "color.hpp"

#include <array>
#include <vector>

class Canvas {
public:
  const size_t width;
  const size_t height;

  Canvas(size_t width, size_t height)
      : width{width}, height{height}, pixels(width * height) {}

  [[nodiscard]] constexpr Color &
  operator[](const std::array<size_t, 2> &coords) {
    return pixels[index(coords[0], coords[1])];
  }

  [[nodiscard]] constexpr const Color &
  operator[](const std::array<size_t, 2> &coords) const {
    return pixels[index(coords[0], coords[1])];
  }

private:
  std::vector<Color> pixels;

  [[nodiscard]] constexpr size_t index(size_t x, size_t y) const {
    return y * width + x;
  }
};

[[nodiscard]] std::string to_ppm(const Canvas &canvas) {
  constexpr size_t MAX_LINE_LEN = 70;

  std::string result = "P3\n";
  result += std::to_string(canvas.width);
  result += " ";
  result += std::to_string(canvas.height);
  result += "\n255\n";

  size_t curLineLen = 0;
  const auto append = [&](const std::string &s) {
    bool prefixSpace = curLineLen != 0;
    if (curLineLen + std::size(s) + prefixSpace > MAX_LINE_LEN) {
      curLineLen = 0;
      result += '\n';
      prefixSpace = false;
    }
    if (prefixSpace) {
      result += " ";
    }
    curLineLen += std::size(s) + prefixSpace;
    result += s;
  };

  for (size_t y = 0; y < canvas.height; ++y) {
    for (size_t x = 0; x < canvas.width; ++x) {
      const auto &color = canvas[{x, y}];
      append(std::to_string(to_byte(color.r())));
      append(std::to_string(to_byte(color.g())));
      append(std::to_string(to_byte(color.b())));
    }
    curLineLen = 0;
    result += "\n";
  }
  return result;
}

#endif // RAYTRACER_CANVAS_H
