#include "bn_core.h"
#include "Commons/StateMachine.hpp"
#include "Scenes/Gameplay.Scene.hpp"

int main() {
    bn::core::init();
    StateMachine* sceneManager = new StateMachine();
    MainMenuVars userOptions;
    userOptions.selectedFlappy = 0;
    userOptions.selectedBackground = 1;
    userOptions.selectedPipes = 1;

    sceneManager->set(new Scene::Gameplay(userOptions));

    while(true) {
        sceneManager->update();
        sceneManager->render();
        bn::core::update();
    }
}