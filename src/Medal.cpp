#include "UI/Medal.hpp"

UI::Medal::Medal(bn::fixed _x, bn::fixed _y) {
    this->sprite = bn::sprite_items::ui_medal.create_sprite(_x, _y);
    this->setX(_x);
    this->setY(_y);
}

UI::Medal* UI::Medal::setX(bn::fixed _x) {
    this->x = _x;
    if(this->sprite.has_value()) this->sprite->set_x(this->x);
    if(this->bottomLeftParticle.has_value()) this->bottomLeftParticle->set_x(this->x - 8);
    if(this->centerParticle.has_value()) this->centerParticle->set_x(this->x + 6);
    if(this->topRightParticle.has_value()) this->topRightParticle->set_x(this->x + 6);
    return this;
}

UI::Medal* UI::Medal::setY(bn::fixed _y) {
    this->y = _y;
    if(this->sprite.has_value()) this->sprite->set_y(this->y);
    if(this->bottomLeftParticle.has_value()) this->bottomLeftParticle->set_y(this->y + 8);
    if(this->centerParticle.has_value()) this->centerParticle->set_y(this->y + 6);
    if(this->topRightParticle.has_value()) this->topRightParticle->set_y(this->y - 8);
    return this;
}

UI::Medal* UI::Medal::useBronzeSprite() {
    this->sprite->set_tiles(bn::sprite_items::ui_medal.tiles_item().create_tiles(0));
    return this;
}

UI::Medal* UI::Medal::useSilverSprite() {
    this->sprite->set_tiles(bn::sprite_items::ui_medal.tiles_item().create_tiles(1));
    this->showShinyParticles();
    return this;
}

UI::Medal* UI::Medal::useGoldSprite() {
    this->sprite->set_tiles(bn::sprite_items::ui_medal.tiles_item().create_tiles(2));
    this->showShinyParticles(1);
    return this;
}

UI::Medal* UI::Medal::usePlatinumSprite() {
    this->sprite->set_tiles(bn::sprite_items::ui_medal.tiles_item().create_tiles(3));
    this->showShinyParticles(2);
    return this;
}

UI::Medal* UI::Medal::showShinyParticles() {
    return this->showShinyParticles(0);
}

UI::Medal* UI::Medal::showShinyParticles(int howMany) {
    this->bottomLeftParticle = bn::sprite_items::ui_particle.create_sprite(this->x, this->y);
    this->bottomLeftParticleAnimation = bn::create_sprite_animate_action_forever(*this->bottomLeftParticle, 8, bn::sprite_items::ui_particle.tiles_item(), 0, 1, 0, 1, 0, 1, 2, 1);
    if(--howMany != 0) {
        this->centerParticle = bn::sprite_items::ui_particle.create_sprite(this->x, this->y);
        this->centerParticleAnimation = bn::create_sprite_animate_action_forever(*this->centerParticle, 8, bn::sprite_items::ui_particle.tiles_item(), 1, 2, 1, 1, 2, 1, 2, 0);
    }
    if(--howMany == 0) {
        this->topRightParticle = bn::sprite_items::ui_particle.create_sprite(this->x, this->y);
        this->topRightParticleAnimation = bn::create_sprite_animate_action_forever(*this->topRightParticle, 8, bn::sprite_items::ui_particle.tiles_item(), 2, 2, 2, 2, 1, 0, 1);
    }
    this->setX(this->x);
    this->setY(this->y);
    return this;
}

UI::Medal* UI::Medal::hideShinyParticles() {
    if(this->bottomLeftParticle.has_value()) {
        this->bottomLeftParticleAnimation.reset();
        this->bottomLeftParticle.reset();
    }
    if(this->centerParticle.has_value()) {
        this->centerParticleAnimation.reset();
        this->centerParticle.reset();
    }
    if(this->topRightParticle.has_value()) {
        this->topRightParticleAnimation.reset();
        this->topRightParticle.reset();
    }
    bn::core::update();
    return this;
}

UI::Medal* UI::Medal::setPriority(int priority) {
    if(this->sprite.has_value()) {
        this->sprite->set_bg_priority(priority);
        this->sprite->set_z_order(priority);
    }
    if(this->bottomLeftParticle.has_value()) {
        this->bottomLeftParticle->set_bg_priority(priority);
        this->bottomLeftParticle->set_z_order(priority);
    }
    if(this->centerParticle.has_value()) {
        this->centerParticle->set_bg_priority(priority);
        this->centerParticle->set_z_order(priority);
    }
    if(this->topRightParticle.has_value()) {
        this->topRightParticle->set_bg_priority(priority);
        this->topRightParticle->set_z_order(priority);
    }
    return this;
}

void UI::Medal::render() {
    if(this->bottomLeftParticleAnimation.has_value()) this->bottomLeftParticleAnimation->update();
    if(this->centerParticleAnimation.has_value()) this->centerParticleAnimation->update();
    if(this->topRightParticleAnimation.has_value()) this->topRightParticleAnimation->update();
}