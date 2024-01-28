#include "Entities/ScoreBoard.hpp"

ScoreBoard::ScoreBoard(int _x, int _y): bg(bn::regular_bg_items::bg_score_board.create_bg(_x, _y)) {
    this->bg.set_priority(0);
}

void ScoreBoard::setX(int _x) {
    this->x = _x;
}

void ScoreBoard::setY(int _y) {
    this->y = _y;
}

int ScoreBoard::getX() {
    return this->x;
}

int ScoreBoard::getY() {
    return this->y;
}

void ScoreBoard::update() {
    this->bg.set_x(this->x);
    this->bg.set_y(this->y);
}
