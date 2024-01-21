#include "SceneManager.hpp"

SceneManager::SceneManager(SceneType _nextScene): nextScene(_nextScene) {}

void SceneManager::loadScene() {
    switch(*nextScene) {
        case SceneType::GEARS_LOGO:
            {
                currentScene.reset(new Scenes::GearsLogo);
                break;
            }
        case SceneType::GAMEPLAY: 
            {
                currentScene.reset(new Scenes::Gameplay);
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