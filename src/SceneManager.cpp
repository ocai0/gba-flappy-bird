#include "SceneManager.hpp"
#include "bn_log.h"

SceneManager::SceneManager(SceneType _nextScene): nextScene(_nextScene) {
    BN_LOG("SceneManager::SceneManager");
}

void SceneManager::loadScene() {
    // BN_LOG(int(*this->nextScene));
    BN_LOG("SceneManager::LoadScene");
    switch(*nextScene) {
        case SceneType::GEARS_LOGO:
            {
                BN_LOG("SceneType::GEARS_LOGO before"); 
                currentScene.reset(new Scenes::GearsLogo());
                BN_LOG("SceneType::GEARS_LOGO after");
                break;
            }
        case SceneType::GAMEPLAY: 
            {
                // BN_LOG("SceneType::GAMEPLAY before");
                // currentScene.reset(new Scenes::Gameplay);
                // BN_LOG("SceneType::GAMEPLAY after");
                break;
            }
    }
}

void SceneManager::update() {
    int waitFrames = 30;

    while(1) {
            
        
        if(currentScene) {
            nextScene = currentScene->update();
        }

        if(nextScene) {
            if(currentScene) {
                currentScene.reset();
                waitFrames = 30;
            }
            bn::core::update();
            --waitFrames;

            if(!waitFrames) {
                this->loadScene();

            }

        }
    }
}