#include "Entities/PipeWall.hpp"

constexpr int SPR_WIDTH = bn::sprite_items::pipe_body.shape_size().width();
constexpr int SPR_WIDTH_HALF = bn::sprite_items::pipe_body.shape_size().width() >> 1;
constexpr int SPR_HEIGHT = bn::sprite_items::pipe_body.shape_size().height();
constexpr int SPR_HEIGHT_HALF = bn::sprite_items::pipe_body.shape_size().height() >> 1;

PipeWall::PipeWall(bn::fixed _x, bn::fixed _y, int _width, int _gapSize, int _color): debugBox(_x, _y, _width, _gapSize) {
    this->gapSize = _gapSize;
    this->offsetX = 0;
    this->width = _width;
    this->color = _color;
    this->createPipes();
    this->setX(_x);
    this->setY(_y);
    this->setScoredFlag(false);
    this->top_pipe->set_vertical_flip(true);
    this->top_pipe->set_horizontal_flip(true);
    this->top_pipe_body->set_horizontal_flip(true);
    this->showDebugBox(false);
}

PipeWall::PipeWall(bn::fixed _x, bn::fixed _y, int _width, int _gapSize, int _color, int _offsetX): debugBox(_x, _y, _width, _gapSize) {
    this->gapSize = _gapSize;
    this->offsetX = _offsetX;
    this->width = _width;
    this->color = _color;
    this->createPipes();
    this->setX(_x);
    this->setY(_y);
    this->setScoredFlag(false);
    this->top_pipe->set_vertical_flip(true);
    this->top_pipe->set_horizontal_flip(true);
    this->top_pipe_body->set_horizontal_flip(true);
    this->showDebugBox(false);
}

void PipeWall::createPipes() {
    this->top_pipe = bn::sprite_items::pipe.create_sprite(0, 0);
    this->top_pipe.value().set_visible(true);
    this->top_pipe_body = bn::sprite_items::pipe_body.create_sprite(0, -SPR_HEIGHT);
    this->top_pipe_body.value().set_visible(true);

    this->bottom_pipe = bn::sprite_items::pipe.create_sprite(0, 0);
    this->bottom_pipe.value().set_visible(true);
    this->bottom_pipe_body = bn::sprite_items::pipe_body.create_sprite(0, SPR_HEIGHT);
    this->bottom_pipe_body.value().set_visible(true);
}
void PipeWall::setX(bn::fixed _x) {
    this->x = _x;
    this->top_pipe->set_x(this->x + SPR_WIDTH_HALF + this->offsetX);
    this->top_pipe_body->set_x(this->x + SPR_WIDTH_HALF + this->offsetX);
    this->bottom_pipe->set_x(this->x + SPR_WIDTH_HALF + this->offsetX);
    this->bottom_pipe_body->set_x(this->x + SPR_WIDTH_HALF + this->offsetX);
    this->debugBox.setX(_x);
    this->debugBox.update();
}
void PipeWall::setY(bn::fixed _y) {
    this->y = _y;
    this->top_pipe->set_y(this->y - SPR_HEIGHT_HALF);
    this->top_pipe_body->set_y(this->y - SPR_HEIGHT_HALF - SPR_HEIGHT);
    this->bottom_pipe->set_y(this->y + SPR_HEIGHT_HALF + this->gapSize);
    this->bottom_pipe_body->set_y(this->y + SPR_HEIGHT_HALF + this->gapSize + SPR_HEIGHT);
    this->debugBox.setY(_y);
    this->debugBox.update();
}
bn::fixed PipeWall::getX() {
    return this->x;
}
bn::fixed PipeWall::getY() {
    return this->y;
}
int PipeWall::getGapSize() {
    return this->gapSize;
}
void PipeWall::setGapSize(int _gapSize) {
    this->gapSize = _gapSize;
}
void PipeWall::setScoredFlag(bool _scored) {
    this->scored = _scored;
}
bool PipeWall::getScoredFlag() {
    return this->scored;
}
void PipeWall::showSprite(bool _show) {
    this->top_pipe->set_visible(_show);
    this->bottom_pipe->set_visible(_show);
}

void PipeWall::showDebugBox(bool _show) {
    this->debugBox.setVisible(_show);
}

int PipeWall::getWidth() {
    return this->width;
}