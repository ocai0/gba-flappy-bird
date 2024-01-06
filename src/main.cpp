#include "bn_core.h"
#include "bn_log.h"
#include "SceneManager.hpp"

int main() {

    SceneManager sceneManager(SceneType::GEARS_LOGO);
    sceneManager.loadScene();
    sceneManager.update();
    BN_LOG("End main()");
}