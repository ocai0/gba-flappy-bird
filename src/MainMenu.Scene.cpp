#include "Scenes/MainMenu.Scene.hpp"

Scene::MainMenu::MainMenu(StateMachine* _sceneManager) {
    this->sceneManager = _sceneManager;
    this->floor.reset(new Floor());
    this->floor
        ->setImage(bn::regular_bg_items::bg_floor.create_bg(0, 36))
        ->setRenderPriority(1);
    this->player.reset(new FlappyBird(-5, 0));
    this->background = Background();
    this->background
        ->setImage(bn::regular_bg_items::bg_day.create_bg(0, -10))
        ->setRenderPriority(3);

    this->gameLogo = UI::Text::GameLogo(-30, -48);
}

void Scene::MainMenu::load() {}

void Scene::MainMenu::update() {
    this->player->update();
    this->floor->update();
    this->background->update();
    if(bn::keypad::a_pressed()) this->sceneManager->set(new Scene::Gameplay(this->sceneManager));
}

void Scene::MainMenu::render() {
    this->player->render();
}

void Scene::MainMenu::leave() {
    this->floor.reset();
    this->background.reset();
    this->player.reset();
    this->gameLogo.reset();
}
