#include "Actors/Floor.hpp"

Floor::Floor() {
    this->instanceName = "FLOOR";
    this->x = -120;
    this->y = 64;
    this->width = 240;
    this->height = 16;
    this->xSpeed = .5;
    this->hitbox = new DebugBox(this->x, this->y, this->width.integer(), this->height.integer());
}

void Floor::setImage(bn::regular_bg_ptr _sprite) {
    this->sprite = _sprite;
}

void Floor::update() {
    if(this->sprite.has_value()) this->sprite->set_x(this->sprite->x() - this->xSpeed);
}