#include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"
#include "bn_log.h"

_Gameplay::GameOver::GameOver(Scene::Gameplay* _gameplayScene) {
    this->gameplayScene = _gameplayScene;
}

void _Gameplay::GameOver::load() {
    bn::blending::set_fade_alpha(0.5);
    this->gameplayScene->score->hide();
    this->gameplayScene->enableBlendingOnAllActors();
    bn::blending::set_fade_color(bn::blending::fade_color_type::WHITE);
}

void _Gameplay::GameOver::update() {
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
                        default:
                            this->gameplayScene->stateMachine->set(new _Gameplay::GetReady(this->gameplayScene));
                            break;
                        case UserOptions::MAIN_MENU:
                            break;
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
    delete this->scoreboard;
    delete this->gameOverText;
    delete this->mainMenuBtn;
    delete this->restartBtn;
}
