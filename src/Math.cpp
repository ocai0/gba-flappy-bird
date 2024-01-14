#include "Math.hpp"

bn::fixed max(bn::fixed a, bn::fixed b) {
    return (a > b) * a + (b > a) * b;
}

bn::fixed min(bn::fixed a, bn::fixed b) {
    return (a < b) * a + (b < a) * b;
}

bn::fixed clamp(bn::fixed _value, bn::fixed _min, bn::fixed _max) {
    return max(_min, min(_value, _max));
}