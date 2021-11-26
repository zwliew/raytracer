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