//
// Created by Zhao Wei Liew on 26/11/21.
//

#include "tuple.h"

Tuple::Tuple(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {
}

bool Tuple::is_point() const {
    return w == 1.0;
}

bool Tuple::is_vector() const {
    return w == 0;
}

bool Tuple::operator==(const Tuple rhs) const {
    return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

Tuple point(float x, float y, float z) {
    return Tuple{x, y, z, 1};
}

Tuple vector(float x, float y, float z) {
    return Tuple{x, y, z, 0};
}