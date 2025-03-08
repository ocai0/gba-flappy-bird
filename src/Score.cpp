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

Score* Score::useSmallFont() {
    this->textGenerator = bn::sprite_text_generator(small_score_font);
    this->textGenerator->set_one_sprite_per_character(true);
    return this;
}

int Score::getValue() {
    return this->value;
}

Score* Score::setValue(int _value) {
    this->value = _value;
    this->text = bn::to_string<4>(this->value);
    this->render();
    return this;
}

Score* Score::setX(bn::fixed _x) {
    this->x = _x;
    this->render();
    return this;
}

Score* Score::setY(bn::fixed _y) {
    this->y = _y;
    this->render();
    return this;
}

Score* Score::fadeIn() {
    return this;
}

Score* Score::fadeOut() {
    return this;
}

Score* Score::show() {
    for(bn::sprite_ptr& letter : this->sprites) letter.set_visible(true);
    return this;
}

Score* Score::hide() {
    for(bn::sprite_ptr& letter : this->sprites) letter.set_visible(false);
    return this;
}

void Score::render() {
    this->sprites.clear();
    if(!this->textGenerator.has_value()) return;
    this->textGenerator->generate(this->x, this->y, this->text, this->sprites);
}

Score* Score::setPriority(int priority) {
    this->textGenerator->set_bg_priority(priority);
    this->textGenerator->set_z_order(priority);
    return this;
}

Score* Score::alignToTheRight() {
    if(this->textGenerator.has_value()) this->textGenerator->set_right_alignment();
    return this;
}

int Score::getSpriteCount() {
    return this->text.size();
}