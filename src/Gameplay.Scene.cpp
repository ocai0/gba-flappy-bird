#include "Scenes/Gameplay.Scene.hpp"
#include "bn_log.h"

bn::random random;

Scene::Gameplay::Gameplay() {
    MainMenuVars userOptions;
    userOptions.birdType = Enum::BirdType::FLAPPY_BIRD;
    userOptions.pipeType = Enum::PipeType::CITY;
    this->init(userOptions);
}

Scene::Gameplay::Gameplay(MainMenuVars& userOptions) {
    this->init(userOptions);
}

void Scene::Gameplay::init(MainMenuVars& options) {
    this->stateMachine = new StateMachine();
    this->stateMachine->set(new _Gameplay::GetReady(this));
    this->camera = bn::camera_ptr::create(0, 0);

    this->initializeFloor(options.backgroundType);
    this->initializePlayer(options.birdType);
    this->initializePipes(options.backgroundType);
    this->initializeBackground(options.backgroundType);

    this->player->watchObstacles(this->obstacles);
    this->score = new Score(-7, -60);
    this->score->useBigFont();
    this->score->setValue(0);
    this->randomGenerator = &random;
}

void Scene::Gameplay::load() {}

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

void Scene::Gameplay::initializeBackground(Enum::BackgroundType _selectedType) {
    this->background = new Background();
    this->background
        ->setImage(bn::regular_bg_items::bg_day.create_bg(0, -10))
        ->setCamera(this->camera)
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

int Scene::Gameplay::addToObstacleList(Obstacle* _obstacle) {
    if(this->obstacleLastItemIndex > this->obstacles.max_size()) {
        BN_LOG("obstacle list is full");
        return -1;
    }
    this->obstacles[++this->obstacleLastItemIndex] = _obstacle;
    return this->obstacleLastItemIndex;
}

int Scene::Gameplay::addToPipeList(PipeWall* _pipe) {
    if(this->pipeLastItemIndex > this->pipes.max_size()) {
        BN_LOG("pipe list is full");
        return -1;
    }
    this->pipes[++this->pipeLastItemIndex] = _pipe;
    return this->pipeLastItemIndex;
}

void Scene::Gameplay::initializePipes(Enum::PipeType _selectedType) {
    constexpr int PIPE_WALLS_ON_SCRREN = 4;

    bn::fixed pipeX = 160;
    bn::fixed pipeY;
    for(int index=0; index < PIPE_WALLS_ON_SCRREN; index++) {
        pipeY = random.get_int(-124, -48);
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
            ->setCamera(this->camera)
            ->setRenderPriority(2)
            ;
        pipeWall->bottomPipe
            ->setX(pipeX)
            ->setY(pipeY + pipeWall->topPipe->getHeight() + this->GAP_SIZE)
            ->setCamera(this->camera)
            ->setRenderPriority(2)
            ;
        if(index % 2 == 0) {
            pipeWall->topPipe->setPalette(bn::sprite_palette_items::blue_pipe.create_palette());
            pipeWall->bottomPipe->setPalette(bn::sprite_palette_items::blue_pipe.create_palette());
        }
        pipeWall->x = pipeX;
        pipeWall->y = pipeY;

        // this->addToObstacleList(pipeWall->topPipe);
        // this->addToObstacleList(pipeWall->bottomPipe);

        pipeX += pipeWall->topPipe->getWidth() + this->GAP_SIZE_BTW_PIPES;
    }
}

void Scene::Gameplay::initializeFloor(Enum::FloorType _selectedType) {
    this->floor = new Floor();
    this->floor->setImage(bn::regular_bg_items::bg_floor.create_bg(0, 36));
    this->floor->setCamera(this->camera);
    this->floor->setRenderPriority(1); 
    this->addToObstacleList((Obstacle*) this->floor);
}

void Scene::Gameplay::initializePlayer(Enum::BirdType _selectedType) {
    switch(_selectedType) {
        case Enum::BirdType::FLAPPY_BIRD:
        default:
            this->player = new FlappyBird(-80, 0);
            break;
        case Enum::BirdType::ROBOT_BIRD:
            this->player = new FlappyBird(-80, 0);
            break;
    }
    
    this->player
        // ->showHitbox()
        ->setCamera(this->camera)
        ->setWeight(.5)
        ->setRenderPriority(2)
        ;
}