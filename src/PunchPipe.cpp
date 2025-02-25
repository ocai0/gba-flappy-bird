#include "Actors/PunchPipe.hpp"

PunchPipe::PunchPipe(bn::fixed _x, bn::fixed _y): Pipe(_x, _y) {
    this->width = 18;
    this->height = 54;
    this->setOffsetX(7);
    this->setOffsetY(10);
    this->setSprite(&bn::sprite_items::punch_pipe);
}