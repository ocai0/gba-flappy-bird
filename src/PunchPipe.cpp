#include "Actors/PunchPipe.hpp"

PunchPipe::PunchPipe(bn::fixed _x, bn::fixed _y): Pipe(_x, _y) {
    this->spacerHeight = 9;
    this->height = 63 - this->spacerHeight;
    this->offsetY = this->spacerHeight / 2.0;
    this->showHitbox();
    this->setSprite(&bn::sprite_items::punch_pipe);
}