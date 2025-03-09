#include "Scenes/Gameplay.Scene.hpp"


Scene::Gameplay::Gameplay(StateMachine* _sceneManager) {
    this->sceneManager = _sceneManager;
}

void Scene::Gameplay::load() {
    this->stateMachine = new StateMachine();
    this->stateMachine->set(new _Gameplay::GetReady(this));
    this->camera = bn::camera_ptr::create(0, 0);

    this->player->watchObstacles(this->obstacles);
    this->score = new Score(-7, -60);
    this->score
        ->useBigFont()
        ->hide()
        ->setValue(0)
        ;
    bn::random random;
    this->randomGenerator = &random;
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