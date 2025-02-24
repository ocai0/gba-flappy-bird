#include "bn_core.h"
#include "Commons/StateMachine.hpp"
#include "Scenes/Gameplay.Scene.hpp"

int main() {
    bn::core::init();
    StateMachine* sceneManager = new StateMachine();
    MainMenuVars userOptions;
    userOptions.birdType = Enum::BirdType::ROBOT_BIRD;
    userOptions.backgroundType = Enum::BackgroundType::CITY;
    userOptions.pipeType = Enum::BackgroundType::CITY;

    sceneManager->set(new Scene::Gameplay(userOptions));

    while(true) {
        sceneManager->update();
        sceneManager->render();
        bn::core::update();
    }
}