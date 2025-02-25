#include "Actors/Pipe.hpp"

const int SPRITE_WIDTH = 32;
const int SPRITE_HEIGHT = 64;

Pipe::Pipe(bn::fixed _x, bn::fixed _y) {
    this->instanceName = "PIPE";
    this->xSpeed = .5;
    this->setX(_x);
    this->setY(_y);
    this->width = 18;
    this->height = 56;
    this->setOffsetX(7);
    this->setOffsetY(8);
    this->setSprite(&bn::sprite_items::common_pipe);
}

Pipe* Pipe::setX(bn::fixed _x) {
    this->x = _x;
    if(this->sprite.has_value()) {
        bn::fixed _renderX = this->x + SPRITE_WIDTH / 2;
        this->sprite->set_x(_renderX - this->offsetX);
    }
    if(this->hitbox.has_value()) this->hitbox->setX(this->x);
    return this;
}

Pipe* Pipe::setOffsetX(bn::fixed _offsetX) {
    this->offsetX = _offsetX;
    this->setX(this->x);
    return this;
}

Pipe* Pipe::setY(bn::fixed _y) {
    this->y = _y;
    if(this->sprite.has_value()) {
        bn::fixed _renderY = this->y + SPRITE_HEIGHT / 2;
        if(this->sprite->vertical_flip()) this->sprite->set_y(_renderY);
        else this->sprite->set_y(_renderY - this->offsetY);
    }
    if(this->hitbox.has_value()) this->hitbox->setY(this->y);
    return this;
}

Pipe* Pipe::setOffsetY(bn::fixed _offsetY) {
    this->offsetY = _offsetY;
    this->setY(this->y);
    return this;
}

Pipe* Pipe::setXSpeed(bn::fixed _xSpeed) {
    this->xSpeed = _xSpeed;
    return this;
}

Pipe* Pipe::setSprite(const bn::sprite_item* _sprite) {
    this->sprite = _sprite->create_sprite(0, 0);
    this->setX(this->x);
    this->setY(this->y);
    return this;
}

Pipe* Pipe::showHitbox() {
    this->hitbox = DebugBox(this->x, this->y, this->width.integer(), this->height.integer());
    return this;
}

Pipe* Pipe::hideHitbox() {
    this->hitbox.reset();
    return this;
}

Pipe* Pipe::setPalette(bn::sprite_palette_ptr _palette) {
    if (this->sprite.has_value()) this->sprite->set_palette(_palette);
    return this;
}

Pipe* Pipe::flipVertically() {
    if (this->sprite.has_value()) {
        this->sprite->set_vertical_flip(!this->sprite->vertical_flip());
        this->setY(this->y);
    }
    return this;
}

Pipe* Pipe::setCamera(bn::optional<bn::camera_ptr> _camera) {
    this->camera = _camera;
    if(this->sprite.has_value()) this->sprite->set_camera(this->camera.value());
    if(this->hitbox.has_value()) this->hitbox->setCamera(this->camera);
    return this;
}

void Pipe::enableBlending() {
    if(this->sprite.has_value()) this->sprite->set_blending_enabled(true);
}

void Pipe::disableBlending() {
    if(this->sprite.has_value()) this->sprite->set_blending_enabled(false);
}

bn::fixed Pipe::getHeight() {
    return this->height;
}

bn::fixed Pipe::getWidth() {
    return this->width;
}

Pipe* Pipe::addBody() {
    // add pipeBody w/ pipe palette
    // update height
    return this;
}

Pipe* Pipe::removeBody() {
    // remove pipeBody w/ pipe palette
    // update height
    return this;
}

Pipe* Pipe::setRenderPriority(int _order) {
    this->sprite->set_z_order(_order);
    return this;
}