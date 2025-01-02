#include "SceneManager.hpp"


void SceneManager::load() {
    ((Scene*) this->scene)->load();
}
void SceneManager::update() {
    Scene* newScene = ((Scene*) this->scene)->update();
    this->next((volatile Scene*) newScene);
}
void SceneManager::next(volatile Scene* newScene) {
    if(this->scene) ((Scene*) this->scene)->leave();
    ((Scene*) newScene)->load();
    scene = newScene;
}