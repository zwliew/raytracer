#ifndef RAYTRACER_CANVAS_H
#define RAYTRACER_CANVAS_H

#include "color.h"

#include <array>
#include <vector>

class Canvas {
public:
    const size_t width;
    const size_t height;

    Canvas(size_t width, size_t height) : width{width}, height{height}, pixels(width * height) {}

    [[nodiscard]] constexpr Color &operator[](const std::array<size_t, 2> &coords) {
        return pixels[index(coords[0], coords[1])];
    }

    [[nodiscard]] constexpr const Color &operator[](const std::array<size_t, 2> &coords) const {
        return pixels[index(coords[0], coords[1])];
    }

private:
    std::vector<Color> pixels;

    [[nodiscard]] constexpr size_t index(size_t x, size_t y) const {
        return x * width + y;
    }
};

[[nodiscard]] std::string to_ppm(const Canvas &canvas) {
    return "P3\n" + std::to_string(canvas.width) + " " + std::to_string(canvas.height) + "\n255\n";
}

#endif //RAYTRACER_CANVAS_H
