#include "Actors/PunchPipe.hpp"

PunchPipe::PunchPipe(bn::fixed _x, bn::fixed _y): Pipe(_x, _y) {
    this->setSprite(&bn::sprite_items::punch_pipe);
}