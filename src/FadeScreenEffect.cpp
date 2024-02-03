#include "Effects/FadeScreenEffect.hpp"
#include "bn_log.h"

FadeScreenEffect::FadeScreenEffect(bn::blending::fade_color_type _fadeColor, bn::fixed step) {
    this->fadeColor = _fadeColor;
    this->_stepValue = step;
    bn::blending::set_fade_color(_fadeColor);
}

void FadeScreenEffect::fadeInOut() {
    this->effectType = FadeScreenEffectType::FADE_IN_OUT;
    this->effectCount = 2;
}

bn::fixed FadeScreenEffect::calculateStepValue(int durationInMiliseconds) {
    return (durationInMiliseconds / (bn::fixed) 6000);
}

bool FadeScreenEffect::isAlive() {
    return this->_active;
}

void FadeScreenEffect::start() {
    this->_active = true;
}

void FadeScreenEffect::update() {
    if(!this->_active) return;

    if(this->effectCount > 0) {
        switch(this->effectType) {
            case FadeScreenEffectType::FADE_IN_OUT: 
                {
                    if(this->effectCount == 2) this->currentValue = clamp(this->currentValue + this->_stepValue, 0, 1);
                    else this->currentValue = clamp(this->currentValue - this->_stepValue, 0, 1);
                }
            break;
        }
        bn::blending::set_fade_alpha(this->currentValue);
        if(this->currentValue == 1 || this->currentValue == 0) this->effectCount--;
    }
    else this->_active = false;

}

void FadeScreenEffect::stop() {
    this->_active = false;
}