#include "Actors/UI/GetReady.hpp"

#define TRANSPARENT 0 
#define OPAQUE 1 

GetReady::GetReady() : bg(bn::regular_bg_items::bg_get_ready.create_bg(0, 10)) {
    this->bg.set_blending_enabled(true);
    this->bg.set_priority(1);
    this->value = TRANSPARENT;
}
GetReady::~GetReady() {
    bn::blending::set_transparency_alpha(OPAQUE);
    this->bg.set_blending_enabled(false);
}

void GetReady::fadeIn() {
    bn::blending::set_transparency_alpha(TRANSPARENT);
    this->value = TRANSPARENT;
    this->fadeInEnabled = true;
    this->done = false;
}

void GetReady::fadeOut() {
    bn::blending::set_transparency_alpha(OPAQUE);
    this->value = OPAQUE;
    this->fadeOutEnabled = true;
    this->done = false;
}

void GetReady::update() {
    if(!this->done) {
        bn::fixed _value(this->value);
        if(this->fadeInEnabled) {
            _value = this->value + .1;
            if(_value >= OPAQUE) {
                _value = OPAQUE;
                this->done = true;
                this->fadeInEnabled = false;
            }
        }
        if(this->fadeOutEnabled) {
            _value = this->value - .1;
            if(_value <= TRANSPARENT) {
                _value = TRANSPARENT;
                this->done = true;
                this->fadeOutEnabled = false;
            }
        }
        this->value = _value;
        bn::blending::set_transparency_alpha(this->value);
    }
}

bool GetReady::isDone() {
    return this->done;
}