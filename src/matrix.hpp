#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H

#include <algorithm>
#include <array>
#include <cstddef>

#include "tuple.hpp"

template <class T, size_t N> class Matrix {
public:
  constexpr Matrix() { std::fill(begin(data), end(data), 0); }

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

  [[nodiscard]] bool operator==(const Matrix<T, N> &rhs) const {
    for (size_t i = 0; i < N * N; ++i) {
      if (data[i] != rhs.data[i]) {
        return false;
      }
    }
    return true;
  }

private:
  std::array<T, N * N> data;

  [[nodiscard]] constexpr size_t index(size_t r, size_t c) const {
    return r * N + c;
  }
};

template <class T, size_t N>
[[nodiscard]] constexpr Matrix<T, N> operator*(const Matrix<T, N> &lhs,
                                               const Matrix<T, N> &rhs) {
  Matrix<T, N> res;
  for (size_t r = 0; r < N; ++r) {
    for (size_t c = 0; c < N; ++c) {
      for (size_t k = 0; k < N; ++k) {
        res[{r, c}] += lhs[{r, k}] * rhs[{k, c}];
      }
    }
  }
  return res;
}

template <class T, size_t N>
[[nodiscard]] constexpr Tuple<T> operator*(const Matrix<T, N> &lhs,
                                           const Tuple<T> &rhs) {
  Tuple<T> res;
  for (size_t r = 0; r < N; ++r) {
    for (size_t k = 0; k < N; ++k) {
      res[r] += lhs[{r, k}] * rhs[k];
    }
  }
  return res;
}

template <class T, size_t N> constexpr Matrix<T, N> identity() {
  Matrix<T, N> res;
  for (size_t i = 0; i < N; ++i) {
    res[{i, i}] = 1;
  }
  return res;
}

#endif // RAYTRACER_MATRIX_H
