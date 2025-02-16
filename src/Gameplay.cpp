#include "Scenes/Gameplay.hpp"
#include "bn_log.h"

Scenes::Gameplay::Gameplay() {
    MainMenuVars userOptions;
    userOptions.selectedFlappy = -1;
    this->init(userOptions);
}

Scenes::Gameplay::Gameplay(MainMenuVars& userOptions) {
    this->init(userOptions);
}

void Scenes::Gameplay::init(MainMenuVars& options) {
    this->camera = bn::camera_ptr::create(0, 0);
    this->player = new FlappyBird(-80, 0);
    this->player
        ->showHitbox()
        ->setCamera(this->camera)
        ->setWeight(1);

    this->currentState = GameplayScene::GET_READY_STATE;
    this->background = new Background();
    this->background
        ->setImage(bn::regular_bg_items::bg_day.create_bg(0, -10))
        ->setCamera(this->camera);

    this->floor = new Floor();
    this->floor->setImage(bn::regular_bg_items::bg_floor.create_bg(0, 36));
    this->floor->setCamera(this->camera);
    this->obstacles[0] = (Obstacle*) this->floor;


    GameplayScene::PipeWall* pipeWall = new GameplayScene::PipeWall;
    this->pipes[0] = pipeWall;
    
    pipeWall->topPipe = new PunchPipe(0, -40);
    pipeWall->topPipe->setPalette(bn::sprite_palette_items::blue_pipe.create_palette());
    pipeWall->topPipe->setCamera(this->camera);
    pipeWall->topPipe->flipVertically();
    this->obstacles[1] = pipeWall->topPipe;
    
    pipeWall->bottomPipe = new CactusPipe(64, -40);
    pipeWall->bottomPipe->setCamera(this->camera);
    this->obstacles[2] = pipeWall->bottomPipe;    

    GameplayScene::PipeWall* pipeWall2 = new GameplayScene::PipeWall;
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

void Scenes::Gameplay::load() {}

Scene* Scenes::Gameplay::update() {
    while(this->nextScene == NULL) {
        switch(this->currentState) {
            default:
            case GameplayScene::GET_READY_STATE:
                this->setGetReadyState();
                break;
            case GameplayScene::IN_GAME_STATE:
                this->setGameState();
                break;
            case GameplayScene::PAUSED_STATE:
                this->setPauseState();
                break;
            case GameplayScene::BONUS_STATE:
                this->setBonusState();
                break;
            case GameplayScene::GAME_OVER_STATE:
                this->setGameOverState();
                break;
            case GameplayScene::YOU_WIN_STATE:
                this->setYouWinState();
                break;
        }
        bn::core::update();
    }
    return this->nextScene;
}

void Scenes::Gameplay::leave() {}

void Scenes::Gameplay::setGetReadyState() {
    this->getReadyBg = bn::regular_bg_items::bg_get_ready.create_bg(0, -10);
    this->getReadyBg->set_blending_enabled(true);
    while(!bn::keypad::a_pressed()) {
        this->player->update();
        this->floor->update();
        this->background->update();
        bn::core::update();
    }
    this->currentState = GameplayScene::IN_GAME_STATE;
}

void Scenes::Gameplay::setGameState() {
    this->score->update();
    bn::fixed getReadyTransparencyValue = 1;
    while(this->currentState == GameplayScene::IN_GAME_STATE) {
        if(this->getReadyBg.has_value()) {
            getReadyTransparencyValue -= .05;
            if(getReadyTransparencyValue < 0) getReadyTransparencyValue = 0;
            bn::blending::set_transparency_alpha(getReadyTransparencyValue);
            if(getReadyTransparencyValue == 0) this->getReadyBg.reset();
        }
        this->player->update();
        // if(this->player->getCurrentState() == Bird::IS_DEAD) {
        //     this->currentState == GameplayScene::GAME_OVER_STATE;
        // }
        if(bn::keypad::start_pressed()) {
            this->currentState = GameplayScene::PAUSED_STATE;
        }
        if(bn::keypad::l_held()) {
            this->camera->set_y(this->camera->y() - 1);
        }
        if(bn::keypad::r_held()) {
            this->camera->set_y(this->camera->y() + 1);
        }
        this->floor->update();
        this->background->update();
        bn::core::update();
    }
}

void Scenes::Gameplay::setBonusState() {}

Scene* Scenes::Gameplay::setPauseState() {
    while(!bn::keypad::start_pressed()) {
        bn::core::update();
    }
    this->currentState = GameplayScene::IN_GAME_STATE;
    return this->nextScene;
}

Scene* Scenes::Gameplay::setGameOverState() {
    return this->nextScene;
}

Scene* Scenes::Gameplay::setYouWinState() {
    return this->nextScene;
}