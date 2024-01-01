#include "Score.hpp"

Score::Score(int _x, int _y) : text_generator(big_score_font) {
    this->text_generator.set_center_alignment();
    this->setValue(value);
    this->setX(_x);
    this->setY(_y);
}

Score::Score(int _x, int _y, int _score) : text_generator(big_score_font) {
    this->setValue(value);
    this->setX(_x);
    this->setY(_y);
}

void Score::setValue(int _newScore) {
    this->value = _newScore;
    this->text_sprites.clear();
    this->text = bn::to_string<4>(this->value);
    this->text_generator.generate(this->x, this->y, text, this->text_sprites);
}

int Score::getValue() {
    return this->value;
}

void Score::setX(int _x) {
    this->x = _x;
}

int Score::getX() {
    return this->x;
}

void Score::setY(int _y) {
    this->y = _y;
}

int Score::getY() {
    return this->y;
}