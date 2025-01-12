#include "Actors/Pipe.hpp"

Pipe::Pipe(bn::fixed _x, bn::fixed _y) {
    this->instanceName = "PIPE";
    this->xSpeed = .5;
    this->setX(_x);
    this->setY(_y);
    this->offsetX = 0;
    this->offsetY = 3;
    this->width = 18;
    this->height = 57;// - 7;
    this->spacerHeight = 6;// - 2;
    this->showHitbox();
    this->setSprite(&bn::sprite_items::common_pipe);
}

Pipe* Pipe::setX(bn::fixed _x) {
    this->x = _x;
    if(this->sprite.has_value()) {
        bn::fixed _renderX = this->x + this->width / 2;
        this->sprite->set_x(_renderX + this->offsetX);
    }
    return this;
}

Pipe* Pipe::setY(bn::fixed _y) {
    this->y = _y;
    if(this->sprite.has_value()) {
        bn::fixed _renderY = this->y + this->height / 2;
        if(this->sprite->vertical_flip()) this->sprite->set_y(_renderY + this->spacerHeight - this->offsetY);
        else this->sprite->set_y(_renderY - this->spacerHeight + this->offsetY);
    }
    return this;
}

Pipe* Pipe::setSpacerHeight(bn::fixed _spacerHeight) {
    this->spacerHeight = _spacerHeight;
    if(this->sprite.has_value()) {
        bn::fixed _renderY = this->y + this->height / 2;
        if(this->sprite->vertical_flip()) this->sprite->set_y(_renderY + this->spacerHeight);
        else this->sprite->set_y(_renderY - this->spacerHeight);
    }
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
    if (this->sprite.has_value()) {
        this->sprite->set_vertical_flip(!this->sprite->vertical_flip());
        this->setY(this->y);
    }
    return this;
}