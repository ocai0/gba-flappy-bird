#include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"
#include "bn_log.h"

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
            if(!this->scoreboard.has_value()) this->initializeScoreBoard();
            if(this->scoreboard.has_value()) this->scoreboard->update();
            if(this->gameOverText == nullptr && this->scoreboard->stateMachine->getStateName() == (bn::string<32>) "ScoreAnimation.Start") {
                this->gameOverText = new UI::Text::GameOver(-34,-42);
            }

            // let user control
        }
    }
}

void _Gameplay::GameOver::initializeScoreBoard() {
    this->scoreboard = UI::ScoreBoard();
    this->scoreboard->load();
    int currentScore = this->parentState->score->getValue();
    this->scoreboard->currentScore->setValue(currentScore);
}

void _Gameplay::GameOver::render() {
    this->parentState->player->render();
    if(this->scoreboard.has_value()) {
        this->scoreboard->render();
    }
}

void _Gameplay::GameOver::leave() {
    this->scoreboard.reset();
    // this->gameOverText.~gameOverText();
    this->gameOverText = nullptr;
}
