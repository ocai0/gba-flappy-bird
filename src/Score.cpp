#include "Score.hpp"

Score::Score(bn::fixed _x, bn::fixed _y) {
    this->setX(_x);
    this->setY(_y);
    this->setValue(0);
}

Score* Score::useBigFont() {
    this->textGenerator = bn::sprite_text_generator(big_score_font);
    this->textGenerator->set_one_sprite_per_character(true);
    return this;
}

int Score::getValue() {
    return this->value;
}

Score* Score::setValue(int _value) {
    this->value = _value;
    this->text = bn::to_string<4>(this->value);
    return this;
}

Score* Score::setX(bn::fixed _x) {
    this->x = _x;
    return this;
}

Score* Score::setY(bn::fixed _y) {
    this->y = _y;
    return this;
}

Score* Score::fadeIn() {
    return this;
}

Score* Score::fadeOut() {
    return this;
}

void Score::update() {
    this->sprites.clear();
    this->textGenerator->generate(this->x, this->y, this->text, this->sprites);
}

void Score::setPriority(int priority) {
    for(bn::sprite_ptr& letter : this->sprites) {
        letter.set_bg_priority(priority);
    }
}