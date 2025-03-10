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

Background* Background::enableBlending() {
    if(this->sprite.has_value()) this->sprite->set_blending_enabled(true);
    return this;
}

Background* Background::disableBlending() {
    if(this->sprite.has_value()) this->sprite->set_blending_enabled(false);
    return this;
}

Background* Background::setRenderPriority(int _order) {
    this->sprite->set_priority(_order);
    return this;
}

Background::~Background() {
    this->sprite->~regular_bg_ptr();
}