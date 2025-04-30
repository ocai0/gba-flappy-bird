#include "Scenes/Gameplay/GameOver/GameOver.Scene.RenderButtons.hpp"

_GameOver::RenderButtons::RenderButtons(_Gameplay::GameOver* _gameoverScene) {
    this->gameoverScene = _gameoverScene;
}

void _GameOver::RenderButtons::load() {
    this->gameoverScene->restartBtn = new UI::Button::Restart(RESTART_BTN_X_POS, BTN_Y_POS);
    this->gameoverScene->restartBtn->select();
    this->option = UserOptions::RESTART_GAME;

    this->gameoverScene->mainMenuBtn = new UI::Button::MainMenu(RESTART_BTN_X_POS + RESTART_BTN_WIDTH + PADDING_BTW_BTNS, BTN_Y_POS);
    this->gameoverScene->mainMenuBtn->unselect();
}

void _GameOver::RenderButtons::update() {
    if(bn::keypad::right_pressed()) {
        this->gameoverScene->restartBtn->unselect();
        this->gameoverScene->mainMenuBtn->select();
        this->option = UserOptions::MAIN_MENU;
    }
    if(bn::keypad::left_pressed()) {
        this->gameoverScene->restartBtn->select();
        this->gameoverScene->mainMenuBtn->unselect();
        this->option = UserOptions::RESTART_GAME;
    }
    if(bn::keypad::a_pressed()) {
        switch(this->option) {
            case UserOptions::RESTART_GAME:
            default: {
                this->gameoverScene->gameplayScene->stateMachine->set(new _Gameplay::GetReady(this->gameoverScene->gameplayScene));
                break;
            }
            case UserOptions::MAIN_MENU: {
                this->gameoverScene->gameplayScene->sceneManager->set(new Scene::MainMenu(this->gameoverScene->gameplayScene->sceneManager));
                break;
            }
        }
    }
}

void _GameOver::RenderButtons::render() {}

void _GameOver::RenderButtons::leave() {
    this->gameoverScene = nullptr;
}
