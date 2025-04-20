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
    delete this->gameplayScene->floor;
    this->gameplayScene->floor = nullptr;

    delete this->gameplayScene->score;
    this->gameplayScene->score = nullptr;
    
    delete this->gameplayScene->player;
    this->gameplayScene->player = nullptr;
    
    this->gameplayScene->background.reset();
    
    delete this->gameplayScene->mainMenuVars;
    this->gameplayScene->mainMenuVars = nullptr;

    for(int index = this->gameplayScene->pipes.size() - 1; index > 0; index--) {
        PipeWall* pipe = this->gameplayScene->pipes.at(index);
        delete pipe->topPipe;
        pipe->topPipe = nullptr;
        delete pipe->bottomPipe;
        pipe->bottomPipe = nullptr;
        this->gameplayScene->pipes.pop_back();
    }

    this->gameplayScene->pipes.clear();
    this->gameplayScene->obstacles.clear();
    // bn::memory::clear(this->gameplayScene->pipes.size(), this->gameplayScene->pipes.at(0));
    // this->gameplayScene->pipes.clear();
    // bn::memory::clear(this->gameplayScene->obstacles.size(), this->gameplayScene->obstacles.at(0));
    // BN_LOG(this->gameplayScene->pipes.size());
    this->gameplayScene->getReadyBg.reset();
    this->gameplayScene = nullptr;
    bn::core::update();
}