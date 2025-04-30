#include "Scenes/Gameplay.Scene.hpp"
#include "bn_log.h"


Scene::Gameplay::Gameplay(StateMachine* _sceneManager) {
    this->camera = bn::camera_ptr::create(0, 0);
    this->setName("Scene::Gameplay");
    this->sceneManager = _sceneManager;
    this->stateMachine.reset(new StateMachine());
}

void Scene::Gameplay::load() {
    this->randomGenerator.reset(new bn::random());
    this->stateMachine->set(new _Gameplay::GetReady(this));
}

void Scene::Gameplay::update() {
    this->stateMachine->update();
}

void Scene::Gameplay::render() {
    this->stateMachine->render();
}

void Scene::Gameplay::leave() {
    this->floor.reset();
    this->score.reset();
    this->player.reset();
    this->player.reset();
    this->background.reset();
    this->mainMenuVars.reset();
    this->randomGenerator.reset();
    this->pipes.clear();
    this->obstacles.clear();
    this->getReadyBg.reset();
    this->camera.reset();
}

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