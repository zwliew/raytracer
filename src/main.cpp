#include <fstream>
#include "tuple.h"
#include "projectile.h"
#include "canvas.h"

int main() {
    Canvas c{900, 550};

    constexpr Color red{1.0f, 0.0f, 0.0f};
    const auto draw_coord = [&](float x, float y) {
        const auto nx = static_cast<int16_t>(std::round(x));
        const auto ny = static_cast<int16_t>(std::round(y));
        if (nx >= 0 && ny >= 0 && static_cast<size_t>(nx) < c.width && static_cast<size_t>(ny) < c.height) {
            c[{static_cast<size_t>(nx), c.height - 1 - ny}] = red;
        }
    };

    constexpr auto gravity = vector(0.0f, -0.1f, 0.0f);
    constexpr auto wind = vector(-0.01f, 0.0f, 0.0f);
    constexpr Environment e{gravity, wind};
    constexpr auto start = point(0.0f, 1.0f, 0.0f);
    const auto velocity = norm(vector(1.0f, 1.8f, 0.0f)) * 11.25f;
    for (Projectile p{start, velocity}; p.position.y >= 0.0f; p = tick(e, p)) {
        draw_coord(p.position.x, p.position.y);
    }

    std::ofstream file("output.ppm");
    file << to_ppm(c);
}
