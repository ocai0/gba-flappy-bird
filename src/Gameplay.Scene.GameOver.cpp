#include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"

_Gameplay::GameOver::GameOver(Scene::Gameplay* _parentState) {
    this->parentState = _parentState;
}

void _Gameplay::GameOver::load() {
    bn::blending::set_fade_alpha(0.5);
    this->parentState->score->hide();
    this->parentState->enableBlendingOnAllActors();
    bn::blending::set_fade_color(bn::blending::fade_color_type::WHITE);
}

void _Gameplay::GameOver::update() {
    // fade effect update
    if(!this->fadeComplete) {
        if(this->fadeIntensity == 0) this->fadeComplete = true;
        else {
            if(this->fadeIntensity == 1) this->fadeMultiplierSign = -1;
            this->fadeIntensity = bn::clamp(this->fadeIntensity + (this->fadeDeltaValue * this->fadeMultiplierSign), bn::fixed(0), bn::fixed(1));
            bn::blending::set_fade_alpha(this->fadeIntensity);
        }
    }
    else {
    // if player is dead
        // show scoreboard
        // let user control
    }
}

void _Gameplay::GameOver::render() {
    BN_LOG(this->fadeIntensity);
    this->parentState->player->render();
}

void _Gameplay::GameOver::leave() {}
