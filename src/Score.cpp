#include "Entities/Score.hpp"

Score::Score(int _x, int _y) : text_generator(big_score_font) {
    this->text_generator.set_center_alignment();
    this->setValue(0);
    this->text_generator.set_bg_priority(1);
    this->setX(_x);
    this->setY(_y);
    this->update();
}

Score::Score(int _x, int _y, int _score) : text_generator(big_score_font) {
    this->setValue(_score);
    this->text_generator.set_bg_priority(1);
    this->setX(_x);
    this->setY(_y);
}

void Score::setValue(int _newScore) {
    this->value = _newScore;
    this->text = bn::to_string<4>(this->value);
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
void Score::update() {
    this->text_sprites.clear();
    this->text_generator.generate(this->x, this->y, this->text, this->text_sprites);
}

void Score::setVisible(bool visible) {
    for(bn::sprite_ptr& sprite : this->text_sprites) {
        sprite.set_visible(visible);
    }
}