#include "Scenes/Gameplay/GameOver/GameOver.Scene.WaitForPlayerDeath.hpp"

_GameOver::WaitForPlayerDeath::WaitForPlayerDeath(_Gameplay::GameOver* _gameoverScene) {
    this->gameoverScene = _gameoverScene;
}

void _GameOver::WaitForPlayerDeath::load() {
    bn::blending::set_fade_alpha(0.5);
    this->gameoverScene->gameplayScene->score->hide();
    this->gameoverScene->gameplayScene->enableBlendingOnAllActors();
    bn::blending::set_fade_color(bn::blending::fade_color_type::WHITE);
}

void _GameOver::WaitForPlayerDeath::update() {
    this->gameoverScene->gameplayScene->player->update();

    if(!this->fadeComplete) {
        if(this->fadeIntensity == 0) this->fadeComplete = true;
        else {
            if(this->fadeIntensity == 1) this->fadeMultiplierSign = -1;
            this->fadeIntensity = bn::clamp(this->fadeIntensity + (this->step * this->fadeMultiplierSign), bn::fixed(0), bn::fixed(1));
            bn::blending::set_fade_alpha(this->fadeIntensity);
        }
    }
    else {
        if(this->gameoverScene->gameplayScene->player->getStateName() == _GameOver::STR_DEAD_STATE) {
            this->gameoverScene->stateMachine->set(new _GameOver::RenderScoreboard(this->gameoverScene));
        }
    }
}

void _GameOver::WaitForPlayerDeath::render() {}

void _GameOver::WaitForPlayerDeath::leave() {
    this->gameoverScene = nullptr;
}
