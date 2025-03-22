#include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"
#include "bn_log.h"


_Gameplay::GameOver::GameOver(Scene::Gameplay* _gameplayScene) {
    this->setName("_Gameplay::GameOver");
    this->gameplayScene = _gameplayScene;
}

void _Gameplay::GameOver::load() {
    BN_LOG("GameOver load start");
    bn::blending::set_fade_alpha(0.5);
    this->gameplayScene->score->hide();
    this->gameplayScene->enableBlendingOnAllActors();
    bn::blending::set_fade_color(bn::blending::fade_color_type::WHITE);
    BN_LOG("GameOver load end");
}

void _Gameplay::GameOver::update() {
    BN_LOG("GameOver update start");
    this->gameplayScene->player->update();
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
        if(this->gameplayScene->player->getStateName() == (bn::string<32>) "DeadState") {
            if(this->scoreboard == nullptr) this->initializeScoreBoard();
            if(this->scoreboard != nullptr) this->scoreboard->update();
            if(this->gameOverText == nullptr && this->scoreboard->stateMachine->getStateName() == (bn::string<32>) "ScoreAnimation.Start") {
                this->gameOverText = new UI::Text::GameOver(-34,-42);
            }
            if(this->scoreboard->stateMachine->getStateName() == (bn::string<32>) "ScoreAnimation.End") {
                // let user control
                int posX = -50;
                int posY = 42;
                if(this->restartBtn == nullptr) {
                    this->restartBtn = new UI::Button::Restart(posX, posY);
                    this->restartBtn->select();
                    this->option = UserOptions::RESTART_GAME;
                }
                if(this->mainMenuBtn == nullptr) {
                    int paddingBtwBtns = 5;
                    int sizeofRersizeBtn = 64;
                    this->mainMenuBtn = new UI::Button::MainMenu(posX + paddingBtwBtns + sizeofRersizeBtn, posY);
                    this->mainMenuBtn->unselect();
                }
                if(bn::keypad::right_pressed()) {
                    this->restartBtn->unselect();
                    this->mainMenuBtn->select();
                    this->option = UserOptions::MAIN_MENU;
                }
                if(bn::keypad::left_pressed()) {
                    this->restartBtn->select();
                    this->mainMenuBtn->unselect();
                    this->option = UserOptions::RESTART_GAME;
                }
                if(bn::keypad::a_pressed()) {
                    switch(this->option) {
                        case UserOptions::RESTART_GAME:
                        default: {
                            this->gameplayScene->stateMachine->set(new _Gameplay::GetReady(this->gameplayScene));
                            break;
                        }
                        case UserOptions::MAIN_MENU: {
                            this->gameplayScene->stateMachine->set(new _Gameplay::GetReady(this->gameplayScene));
                            break;
                        }
                    }
                }
            }
        }
    }
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
    
    delete this->gameplayScene->background;
    this->gameplayScene->background = nullptr;
    
    delete this->gameplayScene->mainMenuVars;
    this->gameplayScene->mainMenuVars = nullptr;
    
    while(this->gameplayScene->pipeLastItemIndex >= 0) {
        PipeWall* pipe = this->gameplayScene->pipes[this->gameplayScene->pipeLastItemIndex--];
        delete pipe->topPipe;
        pipe->topPipe = nullptr;
        delete pipe->bottomPipe;
        pipe->bottomPipe = nullptr;
        // this->gameplayScene->pipes[this->gameplayScene->pipeLastItemIndex] = nullptr;
    }
    
    this->gameplayScene->obstacleLastItemIndex = -1;
    // while(this->gameplayScene->obstacleLastItemIndex >= 0) {
        // this->gameplayScene->obstacles[this->gameplayScene->obstacleLastItemIndex--] = nullptr;
    // }

    this->gameplayScene->pipes.fill(nullptr);
    this->gameplayScene->obstacles.fill(nullptr);
    this->gameplayScene->getReadyBg.reset();
    
    bn::core::update();
    this->gameplayScene->stateMachine->log = true;
}