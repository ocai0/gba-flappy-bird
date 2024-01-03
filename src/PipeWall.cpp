#include "PipeWall.hpp"

PipeWall::PipeWall(int _x, int _y, int _gapSize, int _color) {
    this->gapSize = _gapSize;
    this->color = _color;
    this->createPipes();
    this->setX(_x);
    this->setY(_y);
    this->setScoredFlag(false);
    this->top_pipe->set_vertical_flip(true);
    this->top_pipe->set_horizontal_flip(true);
}

void PipeWall::createPipes() {
    this->top_pipe = bn::sprite_items::pipe.create_sprite(0, 0);
    this->top_pipe.value().set_visible(true);

    this->bottom_pipe = bn::sprite_items::pipe.create_sprite(0, 0);
    this->bottom_pipe.value().set_visible(true);
}
void PipeWall::setX(int _x) {
    this->x = _x;
    this->top_pipe->set_x(this->x + this->PIPE_WIDTH_HALF);
    this->bottom_pipe->set_x(this->x + this->PIPE_WIDTH_HALF);
}
void PipeWall::setY(int _y) {
    this->y = _y;
    this->top_pipe->set_y(this->y - this->PIPE_HEIGHT_HALF);
    this->bottom_pipe->set_y(this->y + this->PIPE_HEIGHT_HALF + this->gapSize);
}
int PipeWall::getX() {
    return this->x;
}
int PipeWall::getY() {
    return this->y;
}
int PipeWall::getGapSize() {
    return this->gapSize;
}
void PipeWall::setScoredFlag(bool _scored) {
    this->scored = _scored;
}
bool PipeWall::getScoredFlag() {
    return this->scored;
}