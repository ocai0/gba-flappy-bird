#include "Actors/Pipe.hpp"

Pipe::Pipe(bn::fixed _x, bn::fixed _y) {
    this->instanceName = "PIPE";
    this->xSpeed = .5;
    this->width = 18;
    this->setX(_x);
    this->setY(_y);
    this->height = 64;
    this->negativeMarginY = 6;
    this->showHitbox();
    this->setSprite(&bn::sprite_items::common_pipe);
}

Pipe* Pipe::setX(bn::fixed _x) {
    this->x = _x;
    if(this->sprite.has_value()) this->sprite->set_x(this->x);
    return this;
}

Pipe* Pipe::setOffsetX(bn::fixed _offsetX) {
    this->offsetX = _offsetX;
    if(this->sprite.has_value()) this->sprite->set_x(this->x + (this->offsetX));
    return this;
}

Pipe* Pipe::setY(bn::fixed _y) {
    this->y = _y;
    if(this->sprite.has_value()) {
        if(this->sprite->vertical_flip() == false) this->sprite->set_y(this->y + this->negativeMarginY);
        else this->sprite->set_y(this->y - this->negativeMarginY);
    }
    return this;
}

Pipe* Pipe::setOffsetY(bn::fixed _offsetY) {
    this->offsetY = _offsetY;
    if(this->sprite.has_value()) {
        if(this->sprite->vertical_flip() == false) this->sprite->set_y(this->y + this->offsetY);
        else this->sprite->set_y(this->y);
    }
    return this;
}

Pipe* Pipe::setXSpeed(bn::fixed _xSpeed) {
    this->xSpeed = _xSpeed;
    return this;
}

Pipe* Pipe::setSprite(const bn::sprite_item* _sprite) {
    this->sprite = _sprite->create_sprite(this->x + this->width / 2 + this->offsetX, this->y + this->height / 2);
    return this;
}

void Pipe::update() {
    this->setX(this->x - this->xSpeed);
    if(this->hitbox.has_value()) this->hitbox->setX(this->x);
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
    if (this->sprite.has_value()) this->sprite->set_vertical_flip(!this->sprite->vertical_flip());
    return this;
}