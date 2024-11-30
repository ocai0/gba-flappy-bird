#include "Actors/UI/Score.hpp"

Score::Score(int _x, int _y, FontType _font) {
    if(_font == FontType::BIG) this->ptr_text_generator.reset(new bn::sprite_text_generator(big_score_font));
    if(_font == FontType::SMALL) this->ptr_text_generator.reset(new bn::sprite_text_generator(small_score_font));
    

    this->ptr_text_generator.get()->set_center_alignment();
    this->setValue(0);
    this->ptr_text_generator.get()->set_one_sprite_per_character(true);
    this->ptr_text_generator.get()->set_bg_priority(1);
    this->setX(_x);
    this->setY(_y);
    this->update();
}

Score::Score(int _x, int _y, int _score, FontType _font) {
    this->setValue(_score);
    this->ptr_text_generator.get()->set_bg_priority(1);
    this->ptr_text_generator.get()->set_one_sprite_per_character(true);
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
    this->ptr_text_generator.get()->generate(this->x, this->y, this->text, this->text_sprites);
}

void Score::setVisible(bool visible) {
    for(bn::sprite_ptr& sprite : this->text_sprites) {
        sprite.set_visible(visible);
    }
}

void Score::setPriority(int priority) {
    for(bn::sprite_ptr& sprite : this->text_sprites) {
        sprite.set_bg_priority(priority);
    }
}

void Score::setAlignment(bn::sprite_text_generator::alignment_type _align) {
    this->ptr_text_generator.get()->set_alignment(_align);
}