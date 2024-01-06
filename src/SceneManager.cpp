#include "SceneManager.hpp"
#include "bn_log.h"


SceneManager::SceneManager(SceneType _nextScene): nextScene(_nextScene) {
    this->loadScene();
}

void SceneManager::loadScene() {
    switch(*this->nextScene) {
        // BN_LOG(int(*this->nextScene));
        case SceneType::GEARS_LOGO: 
        default:
            {
                this->currentScene.reset(new Scenes::GearsLogo());
                break;
            }
        case SceneType::GAMEPLAY: 
            {
                this->currentScene.reset(new Scenes::Gameplay());
                BN_LOG("scenemanager");
                break;
            }
    }
    this->update();
    bn::core::update();
}

void SceneManager::update() {
    BN_LOG("ala");
    this->nextScene = this->currentScene->update();
    this->loadScene();
}