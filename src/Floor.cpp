#include "Actors/Asset/Floor.hpp"

Floor::Floor(bn::fixed _x, bn::fixed _y): x(_x), y(_y), bg(bn::regular_bg_items::bg_floor.create_bg(_x, _y)) {
    this->bg.set_priority(0);
}

void Floor::setX(bn::fixed _x) {
    this->x = _x;
}

bn::fixed Floor::getX() {
    return this->x;
}

void Floor::setY(bn::fixed _y) {
    this->y = _y;
}

bn::fixed Floor::getY() {
    return this->y;
}

void Floor::update() {
    this->bg.set_x(this->x);
    this->bg.set_y(this->y);
}

void Floor::setBlendingEnabled(bool _enabled) {
    this->bg.set_blending_enabled(_enabled);
}