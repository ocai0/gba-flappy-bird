#include "Background.hpp"

Background* Background::setImage(bn::regular_bg_ptr _sprite) {
    this->sprite = _sprite;
    return this;
}

void Background::update() {
    if(this->sprite.has_value()) this->sprite->set_x(this->sprite->x() - this->xSpeed);
}

Background* Background::setCamera(bn::optional<bn::camera_ptr> _camera) {
    this->camera = _camera;
    if(this->sprite.has_value()) this->sprite->set_camera(this->camera.value());
    return this;
}