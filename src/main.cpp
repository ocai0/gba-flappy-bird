#include "bn_core.h"
#include "bn_assert.h"
#include "bn_log.h"
#include "Commons/StateMachine.hpp"
#include "Scenes/GearsLogo.Scene.hpp"

int main() {
    bn::core::init();
    StateMachine sceneManager = StateMachine();
    sceneManager.set(new Scene::GearsLogo(&sceneManager));
    while(true) {
        sceneManager.update();
        sceneManager.render();
        bn::core::update();
    }
}