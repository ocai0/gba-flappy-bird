#include "Scenes/Gameplay.Scene.hpp"
#include "bn_log.h"

Scene::Gameplay::Gameplay(StateMachine* _sceneManager): camera(bn::camera_ptr::create(0, 0)) {
    this->setName("Scene::Gameplay");
    this->sceneManager = _sceneManager;
    this->stateMachine = new StateMachine();
}

void Scene::Gameplay::load() {
    this->randomGenerator = new bn::random();
    this->stateMachine->set(new _Gameplay::GetReady(this));
}

void Scene::Gameplay::update() {
    this->stateMachine->update();
}

void Scene::Gameplay::render() {
    this->stateMachine->render();
}

void Scene::Gameplay::leave() {}

void Scene::Gameplay::enableBlendingOnAllActors() {
    this->player->enableBlending();
    this->background->enableBlending();
    for (Obstacle* obstacle : this->obstacles) {
        if(obstacle == nullptr) continue;
        obstacle->enableBlending();
    }
}

void Scene::Gameplay::disableBlendingOnAllActors() {
    this->player->disableBlending();
    this->background->disableBlending();
    for (Obstacle* obstacle : this->obstacles) {
        if(obstacle == nullptr) continue;
        obstacle->disableBlending();
    }
}