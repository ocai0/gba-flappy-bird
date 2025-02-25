#include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"
#include "bn_log.h"

_Gameplay::GameOver::GameOver(Scene::Gameplay* _parentState) {
    this->parentState = _parentState;
    this->sram = &SramData::getInstance();
}

void _Gameplay::GameOver::load() {
    bn::blending::set_fade_alpha(0.5);
    this->parentState->score->hide();
    this->parentState->enableBlendingOnAllActors();
    bn::blending::set_fade_color(bn::blending::fade_color_type::WHITE);
    int currentScore = this->parentState->score->getValue();
    int highScore = this->sram->getHighScore();
    if(currentScore > highScore) {
        this->sram->setHighScore(currentScore);
        this->sram->write();
        this->newHighSocre = true;
    }
}

void _Gameplay::GameOver::update() {
    this->parentState->player->update();
    // fade effect update
    if(!this->fadeComplete) {
        if(this->fadeIntensity == 0) this->fadeComplete = true;
        else {
            if(this->fadeIntensity == 1) this->fadeMultiplierSign = -1;
            this->fadeIntensity = bn::clamp(this->fadeIntensity + (this->step * this->fadeMultiplierSign), bn::fixed(0), bn::fixed(1));
            bn::blending::set_fade_alpha(this->fadeIntensity);
        }
    }
    else {
    if(this->parentState->player->getStateName() == (bn::string<32>) "DeadState") {
        // show scoreboard
        // this->scoreboard = new ScoreBoard();
        // let user control
    }
    }
}

void _Gameplay::GameOver::render() {
    this->parentState->player->render();
}

void _Gameplay::GameOver::leave() {}
