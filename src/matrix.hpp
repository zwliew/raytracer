#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H

#include <array>
#include <cstddef>

template <class T, size_t N> class Matrix {
public:
  constexpr Matrix(const std::initializer_list<T> &data_) {
    std::copy_n(begin(data_), std::min(std::size(data), std::size(data_)),
                begin(data));
  }

  [[nodiscard]] constexpr T &operator[](const std::array<size_t, 2> &idx) {
    return data[index(idx[0], idx[1])];
  }

  [[nodiscard]] constexpr const T &
  operator[](const std::array<size_t, 2> &idx) const {
    return data[index(idx[0], idx[1])];
  }

private:
  std::array<T, N * N> data;

  [[nodiscard]] constexpr size_t index(size_t r, size_t c) const {
    return r * N + c;
  }
};

#endif // RAYTRACER_MATRIX_H
