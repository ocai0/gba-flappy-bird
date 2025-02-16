#include "Scenes/Gameplay.Scene.hpp"
#include "bn_log.h"

Scene::Gameplay::Gameplay() {
    MainMenuVars userOptions;
    userOptions.selectedFlappy = -1;
    this->init(userOptions);
}

Scene::Gameplay::Gameplay(MainMenuVars& userOptions) {
    this->init(userOptions);
}

void Scene::Gameplay::init(MainMenuVars& options) {
    this->stateMachine = new StateMachine();
    this->stateMachine->set(new _Gameplay::GetReady(this));
    this->camera = bn::camera_ptr::create(0, 0);
    this->player = new FlappyBird(-80, 0);
    this->player
        ->showHitbox()
        ->setCamera(this->camera)
        ->setWeight(.5);

    this->background = new Background();
    this->background
        ->setImage(bn::regular_bg_items::bg_day.create_bg(0, -10))
        ->setCamera(this->camera);

    this->floor = new Floor();
    this->floor->setImage(bn::regular_bg_items::bg_floor.create_bg(0, 36));
    this->floor->setCamera(this->camera);
    this->obstacles[0] = (Obstacle*) this->floor;


    PipeWall* pipeWall = new PipeWall;
    this->pipes[0] = pipeWall;
    
    pipeWall->topPipe = new PunchPipe(0, -40);
    pipeWall->topPipe->setPalette(bn::sprite_palette_items::blue_pipe.create_palette());
    pipeWall->topPipe->setCamera(this->camera);
    pipeWall->topPipe->flipVertically();
    this->obstacles[1] = pipeWall->topPipe;
    
    pipeWall->bottomPipe = new CactusPipe(64, -40);
    pipeWall->bottomPipe->setCamera(this->camera);
    this->obstacles[2] = pipeWall->bottomPipe;    

    PipeWall* pipeWall2 = new PipeWall;
    this->pipes[1] = pipeWall2;

    pipeWall2->topPipe = new Pipe(32, -40);
    pipeWall2->topPipe->setCamera(this->camera);
    this->obstacles[3] = pipeWall2->topPipe;

    pipeWall2->bottomPipe = new AncientPipe(-32, -40);
    pipeWall2->bottomPipe->flipVertically();
    pipeWall2->bottomPipe->setCamera(this->camera);
    this->obstacles[4] = pipeWall2->bottomPipe;


    this->player->watchObstacles(this->obstacles);
    this->score = new Score(-7, -60);
    this->score->useBigFont();
    this->score->setValue(1001);
}

void Scene::Gameplay::load() {}

void Scene::Gameplay::update() {
    this->stateMachine->update();
}

void Scene::Gameplay::render() {
    this->stateMachine->render();
}

void Scene::Gameplay::leave() {}