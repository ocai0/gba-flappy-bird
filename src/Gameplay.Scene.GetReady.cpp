#include "Scenes/Gameplay/Gameplay.Scene.GetReady.hpp"
#include "bn_log.h"


_Gameplay::GetReady::GetReady(Scene::Gameplay* _gameplayScene) {
    this->setName("_Gameplay::GetReady");
    this->gameplayScene = _gameplayScene;
}

void _Gameplay::GetReady::load() {
    MainMenuVars userOptions;
    userOptions.birdType = Enum::BirdType::FLAPPY_BIRD;
    userOptions.backgroundType = Enum::PipeType::CITY;
    this->gameplayScene->score = new Score(-7, -60);
    this->gameplayScene->score
        ->useBigFont()
        ->hide()
        ->setValue(0)
        ;
    this->initializeFloor(userOptions.backgroundType);
    this->initializePlayer(userOptions.birdType);
    this->initializePipes(userOptions.backgroundType);
    this->initializeBackground(userOptions.backgroundType);
    this->gameplayScene->player->watchObstacles(this->gameplayScene->obstacles);

    this->gameplayScene->getReadyBg = bn::regular_bg_items::bg_get_ready.create_bg(0, -10);
    this->gameplayScene->getReadyBg->set_priority(1);
    this->gameplayScene->getReadyBg->set_blending_enabled(true);
}

void _Gameplay::GetReady::update() {
    if(bn::keypad::a_pressed()) this->gameplayScene->stateMachine->set(new _Gameplay::InGame(this->gameplayScene));
    else {
        this->gameplayScene->player->update();
        this->gameplayScene->floor->update();
        this->gameplayScene->background->update();
    }
}

void _Gameplay::GetReady::render() {
    this->gameplayScene->player->render();
    this->gameplayScene->score->hide();
}

void _Gameplay::GetReady::leave() {
    this->gameplayScene = nullptr;
}


void _Gameplay::GetReady::initializeBackground(Enum::BackgroundType _selectedType) {
    this->gameplayScene->background = Background();
    this->gameplayScene->background
        ->setImage(bn::regular_bg_items::bg_day.create_bg(0, -10))
        ->setCamera(this->gameplayScene->camera)
        ->setRenderPriority(3)
        ;
    switch(_selectedType) {
        case Enum::BackgroundType::CITY:
        default:
            break;
        case Enum::BackgroundType::ANCIENT:
            break;
        case Enum::BackgroundType::ARENA:
            break;
        case Enum::BackgroundType::DESERT:
            break;
    }
}

int _Gameplay::GetReady::addToObstacleList(Obstacle* _obstacle) {
    if(this->gameplayScene->obstacles.size() + 1 > this->gameplayScene->obstacles.max_size()) return -1;
    this->gameplayScene->obstacles.push_back(_obstacle);
    return this->gameplayScene->obstacles.size();
}

int _Gameplay::GetReady::addToPipeList(PipeWall* _pipe) {
    if(this->gameplayScene->pipes.size() + 1 >= this->gameplayScene->pipes.max_size()) return -1;
    this->gameplayScene->pipes.push_back(_pipe);
    return this->gameplayScene->pipes.size();
}

void _Gameplay::GetReady::initializePipes(Enum::PipeType _selectedType) {
    constexpr int PIPE_WALLS_ON_SCRREN = 4;

    bn::fixed pipeX = 160;
    bn::fixed pipeY;
    for(int index=0; index < PIPE_WALLS_ON_SCRREN; index++) {
        pipeY = this->gameplayScene->randomGenerator->get_int(-124, -48);
        PipeWall* pipeWall = new PipeWall;
        this->addToPipeList(pipeWall);
        switch(_selectedType) {
            case Enum::PipeType::CITY:
            default:        
                pipeWall->topPipe = new Pipe(0, 0);
                pipeWall->bottomPipe = new Pipe(0, 0);
                break;
            case Enum::PipeType::ANCIENT:
                pipeWall->topPipe = new AncientPipe(0, 0);
                pipeWall->bottomPipe = new AncientPipe(0, 0);
                break;
            case Enum::PipeType::ARENA:
                pipeWall->topPipe = new PunchPipe(0, 0);
                pipeWall->bottomPipe = new PunchPipe(0, 0);
                break;
            case Enum::PipeType::DESERT:
                pipeWall->topPipe = new CactusPipe(0, 0);
                pipeWall->bottomPipe = new CactusPipe(0, 0);
                break;
        }
        pipeWall->topPipe
            ->setX(pipeX)
            ->setY(pipeY)
            ->flipVertically()
            ->addBody()
            ->setCamera(&this->gameplayScene->camera)
            ->setRenderPriority(2)
            ;
        pipeWall->bottomPipe
            ->setX(pipeX)
            ->setY(pipeY + pipeWall->topPipe->getHeight() + this->gameplayScene->GAP_SIZE)
            ->setCamera(&this->gameplayScene->camera)
            ->setRenderPriority(2)
            ;
        if(index % 2 == 0) {
            pipeWall->topPipe->setPalette(bn::sprite_palette_items::blue_pipe.create_palette());
            pipeWall->bottomPipe->setPalette(bn::sprite_palette_items::blue_pipe.create_palette());
        }
        pipeWall->x = pipeX;
        pipeWall->y = pipeY;

        this->addToObstacleList(pipeWall->topPipe);
        this->addToObstacleList(pipeWall->bottomPipe);

        pipeX += pipeWall->topPipe->getWidth() + this->gameplayScene->GAP_SIZE_BTW_PIPES;
    }
}

void _Gameplay::GetReady::initializeFloor(Enum::FloorType _selectedType) {
    this->gameplayScene->floor = new Floor();
    this->gameplayScene->floor->setImage(bn::regular_bg_items::bg_floor.create_bg(0, 36));
    this->gameplayScene->floor->setCamera(&this->gameplayScene->camera);
    this->gameplayScene->floor->setRenderPriority(1); 
    this->addToObstacleList((Obstacle*) this->gameplayScene->floor);
}

void _Gameplay::GetReady::initializePlayer(Enum::BirdType _selectedType) {
    switch(_selectedType) {
        case Enum::BirdType::FLAPPY_BIRD:
        default:
            this->gameplayScene->player = new FlappyBird(-80, 0);
            break;
        case Enum::BirdType::ROBOT_BIRD:
            this->gameplayScene->player = new FlappyBird(-80, 0);
            break;
    }
    
    this->gameplayScene->player
        // ->showHitbox()
        ->setCamera(&this->gameplayScene->camera)
        ->setWeight(.5)
        ->setRenderPriority(2)
        ;
}