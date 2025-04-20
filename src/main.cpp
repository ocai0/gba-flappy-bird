#include "bn_core.h"
#include "bn_assert.h"
#include "bn_log.h"
#include "Commons/StateMachine.hpp"
#include "Scenes/GearsLogo.Scene.hpp"

int main() {
    bn::core::init();
    bn::optional<StateMachine> sceneManager = StateMachine();
    AbstractState* scene = new Scene::GearsLogo(sceneManager);

    sceneManager->set(scene);
    while(true) {
        sceneManager->update();
        sceneManager->render();
        BN_ASSERT(sceneManager.has_value(), "SceneManager do main deixou de existir");
        bn::core::update();
    }
}