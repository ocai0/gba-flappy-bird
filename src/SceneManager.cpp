#include "SceneManager.hpp"

SceneManager::SceneManager(SceneType _nextScene): nextScene(_nextScene) {}

void SceneManager::loadScene() {
    switch(*nextScene) {
        case SceneType::GEARS_LOGO:
            {
                currentScene.reset(new Scenes::GearsLogo);
                break;
            }
        case SceneType::MAIN_MENU: 
            {
                currentScene.reset(new Scenes::MainMenu);
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

    while(1) {
        if(currentScene) {
            nextScene = currentScene->update();
        }
        if(nextScene) {
            if(currentScene) {
                currentScene.reset();
            }
            bn::core::update();
            this->loadScene();
        }
    }
}