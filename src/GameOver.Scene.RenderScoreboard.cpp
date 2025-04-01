#include "Scenes/Gameplay/GameOver/GameOver.Scene.RenderScoreboard.hpp"

_GameOver::RenderScoreboard::RenderScoreboard(_Gameplay::GameOver* _gameoverScene) {
    this->gameoverScene = _gameoverScene;
}

void _GameOver::RenderScoreboard::load() {
    this->gameoverScene->initializeScoreBoard();
}

void _GameOver::RenderScoreboard::update() {
    this->gameoverScene->scoreboard->update();
    if(this->gameoverScene->gameOverText == nullptr && this->gameoverScene->scoreboard->stateMachine->getStateName() == _GameOver::STR_SCORE_ANIMATION_START) {
        this->gameoverScene->gameOverText = new UI::Text::GameOver(-34,-42);
    }
    if(this->gameoverScene->scoreboard->stateMachine->getStateName() == _GameOver::STR_SCORE_ANIMATION_END) {
        this->gameoverScene->stateMachine->set(new _GameOver::RenderButtons(this->gameoverScene));
    }
}

void _GameOver::RenderScoreboard::render() {}

void _GameOver::RenderScoreboard::leave() {
    this->gameoverScene = nullptr;
}
