#include "bn_core.h"
#include "bn_log.h"
#include "SceneManager.hpp"

int main() {
    bn::core::init();
    SceneManager sceneManager(SceneType::GEARS_LOGO);
    sceneManager.loadScene();
    while(true) {
        sceneManager.update();
        bn::core::update();
    }
    BN_LOG("End main()");
}