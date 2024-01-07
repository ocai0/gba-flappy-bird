int max(int a, int b) {
    return (a > b) * a + (b > a) * b;
}

int min(int a, int b) {
    return (a < b) * a + (b < a) * b;
}

int clamp(int _value, int _min, int _max) {
    return max(_min, min(_value, _max));
}