#include "bn_core.h"
#include "bn_log.h"
#include "SceneManager.hpp"
#include "Scenes/GearsLogo.hpp"

int main() {
    bn::core::init();
    SceneManager sceneManager;
    sceneManager.next(new Scenes::GearsLogo);

    while(true) {
        bn::core::update();
        sceneManager.update();
    }
}