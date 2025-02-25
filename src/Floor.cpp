#include "Actors/Floor.hpp"

Floor::Floor() {
    this->instanceName = "FLOOR";
    this->x = -120;
    this->y = 64;
    this->width = 240;
    this->height = 16;
    this->xSpeed = .5;
}

void Floor::setImage(bn::regular_bg_ptr _sprite) {
    this->sprite = _sprite;
}

void Floor::update() {
    if(this->sprite.has_value()) this->sprite->set_x(this->sprite->x() - this->xSpeed);
}

void Floor::setCamera(bn::optional<bn::camera_ptr> _camera) {
    if(this->sprite.has_value()) this->sprite->set_camera(_camera.value());
    if(this->hitbox.has_value()) this->hitbox->setCamera(_camera.value());
}

void Floor::enableBlending() {
    if(this->sprite.has_value()) this->sprite->set_blending_enabled(true);
}

void Floor::disableBlending() {
    if(this->sprite.has_value()) this->sprite->set_blending_enabled(false);
}

void Floor::setRenderPriority(int _order) {
    this->sprite->set_priority(_order);
}

void Floor::showHitbox() {
    this->hitbox = DebugBox(this->x, this->y, this->width.integer(), this->height.integer());
}
void Floor::hideHitbox() {
    this->hitbox.reset();
}