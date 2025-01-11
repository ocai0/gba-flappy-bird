#include "Scenes/Gameplay.hpp"
#include "bn_log.h"

Scenes::Gameplay::Gameplay() {
    MainMenuVars userOptions;
    userOptions.selectedFlappy = -1;
    this->init(userOptions);
}

Scenes::Gameplay::Gameplay(MainMenuVars& userOptions) {
    this->init(userOptions);
}

void Scenes::Gameplay::init(MainMenuVars& options) {
    this->player = new FlappyBird(0, 0);
    this->player
        ->setWeight(2)
        ->showHitbox();
    this->currentState = GET_READY_STATE;
    this->floor = new Floor();
    this->floor->setImage(bn::regular_bg_items::bg_floor.create_bg(0, 36));
}

void Scenes::Gameplay::load() {}

Scene* Scenes::Gameplay::update() {
    while(this->nextScene == NULL) {
        switch(this->currentState) {
            default:
            case GET_READY_STATE:
                this->setGetReadyState();
                break;
            case IN_GAME_STATE:
                this->setGameState();
                break;
            case PAUSED_STATE:
                this->setPauseState();
                break;
            case BONUS_STATE:
                this->setBonusState();
                break;
            case GAME_OVER_STATE:
                this->setGameOverState();
                break;
            case YOU_WIN_STATE:
                this->setYouWinState();
                break;
        }
        bn::core::update();
    }
    return this->nextScene;
}

void Scenes::Gameplay::leave() {}

void Scenes::Gameplay::setGetReadyState() {
    while(!bn::keypad::a_pressed()) {
        this->player->idle();
        this->floor->update();
        bn::core::update();
    }
    this->currentState = IN_GAME_STATE;
}

void Scenes::Gameplay::setGameState() {
    while(this->currentState == IN_GAME_STATE) {
        this->player->update();
        if(bn::keypad::start_pressed()) {
            this->currentState = PAUSED_STATE;
        }
        bn::core::update();
    }
}

void Scenes::Gameplay::setBonusState() {}

Scene* Scenes::Gameplay::setPauseState() {
    while(!bn::keypad::start_pressed()) {
        bn::core::update();
    }
    this->currentState = IN_GAME_STATE;
    return this->nextScene;
}

Scene* Scenes::Gameplay::setGameOverState() {
    return this->nextScene;
}

Scene* Scenes::Gameplay::setYouWinState() {
    return this->nextScene;
}