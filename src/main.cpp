#include "bn_core.h"
#include "SceneManager.hpp"
#include "Scenes/Gameplay.hpp"

int main() {
    bn::core::init();
    SceneManager sceneManager;
    MainMenuVars userOptions;
    userOptions.selectedFlappy = 0;
    userOptions.selectedBackground = 1;
    userOptions.selectedPipes = 1;

    sceneManager.next(new Scenes::Gameplay(userOptions));

    while(true) {
        bn::core::update();
        sceneManager.update();
    }
}