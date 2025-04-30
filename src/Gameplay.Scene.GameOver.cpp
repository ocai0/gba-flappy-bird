#include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"
#include "bn_log.h"


_Gameplay::GameOver::GameOver(Scene::Gameplay* _gameplayScene) {
    this->setName("_Gameplay::GameOver");
    this->gameplayScene = _gameplayScene;
    this->stateMachine = new StateMachine();
}

void _Gameplay::GameOver::load() {
    this->stateMachine->set(new _GameOver::WaitForPlayerDeath(this));
}

void _Gameplay::GameOver::update() {
    this->stateMachine->update();
}

void _Gameplay::GameOver::initializeScoreBoard() {
    this->scoreboard = new UI::ScoreBoard();
    this->scoreboard->load();
    int currentScore = this->gameplayScene->score->getValue();
    this->scoreboard->currentScore->setValue(currentScore);
}

void _Gameplay::GameOver::render() {
    this->gameplayScene->player->render();
    if(this->scoreboard != nullptr) {
        this->scoreboard->render();
    }
}

void _Gameplay::GameOver::leave() {
    this->clearResources();
}

void _Gameplay::GameOver::clearResources() {
    delete this->scoreboard;
    this->scoreboard = nullptr;

    delete this->gameOverText;
    this->gameOverText = nullptr;

    delete this->mainMenuBtn;
    this->mainMenuBtn = nullptr;

    delete this->restartBtn;
    this->restartBtn = nullptr;

    this->clearOutsideResources();
}

void _Gameplay::GameOver::clearOutsideResources() {
    this->gameplayScene->floor.reset();
    this->gameplayScene->score.reset();
    this->gameplayScene->player.reset();
    this->gameplayScene->background.reset();
    this->gameplayScene->mainMenuVars.reset();
    this->gameplayScene->obstacles.clear();
    this->gameplayScene->getReadyBg.reset();
    this->gameplayScene = nullptr;
    bn::core::update();
}