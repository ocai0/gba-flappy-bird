#include "bn_core.h"
#include "Commons/StateMachine.hpp"
#include "Scenes/GearsLogo.Scene.hpp"

int main() {
    bn::core::init();
    StateMachine* sceneManager = new StateMachine();
    AbstractState* scene = new Scene::GearsLogo(sceneManager);

    sceneManager->set(scene);

    while(true) {
        sceneManager->update();
        sceneManager->render();
        bn::core::update();
    }
}