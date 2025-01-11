#include "Background.hpp"

void Background::setImage(bn::regular_bg_ptr _sprite) {
    this->sprite = _sprite;
}

void Background::update() {
    if(this->sprite.has_value()) this->sprite->set_x(this->sprite->x() - this->xSpeed);
}