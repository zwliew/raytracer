//
// Created by Zhao Wei Liew on 26/11/21.
//

#include "tuple.h"
#include "numeric.h"

bool Tuple::is_point() const {
    return equal(w, 1.0f);
}

bool Tuple::is_vector() const {
    return equal(w, 0.0f);
}

bool Tuple::operator==(const Tuple rhs) const {
    return equal(x, rhs.x) && equal(y, rhs.y) && equal(z, rhs.z) && equal(w, rhs.w);
}

Tuple point(float x, float y, float z) {
    return Tuple{x, y, z, 1.0f};
}

Tuple vector(float x, float y, float z) {
    return Tuple{x, y, z, 0.0f};
}