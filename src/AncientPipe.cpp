#include "Actors/AncientPipe.hpp"

AncientPipe::AncientPipe(bn::fixed _x, bn::fixed _y): Pipe(_x, _y) {
    this->width = 18;
    this->height = 57;
    this->setOffsetX(7);
    this->setOffsetY(7);
    this->setSprite(&bn::sprite_items::ancient_pipe);
}