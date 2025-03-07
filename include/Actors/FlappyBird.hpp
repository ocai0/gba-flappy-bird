#ifndef FLAPPY_BIRD_H_
#define FLAPPY_BIRD_H_
    #include "bn_core.h"
    #include "bn_optional.h"
    #include "bn_keypad.h"
    #include "bn_array.h"
    #include "bn_sprite_ptr.h"
    #include "bn_camera_ptr.h"
    #include "bn_sprite_animate_actions.h"
    #include "bn_sound_items.h"
    #include "bn_sound_handle.h"
    #include "Actors/Actor.hpp"
    #include "Actors/Obstacle.hpp"
    #include "Actors/DebugBox.hpp"
    #include "Actors/Obstacle.hpp"
    #include "Commons/StateMachine.hpp"
    #include "Actors/FlappyBird/FlappyBird.State.Idle.hpp"

    #include "bn_sprite_items_common_bird.h"

    class FlappyBird : public Actor {
        public:
            int offsetY = 4;
            int offsetX = 4;
            int width = 10;
            int height = 8;
            bn::fixed x;
            bn::fixed y;
            bn::fixed deltaX;
            bn::fixed deltaY;
            int deltaYSign = -1;
            bn::fixed weight;
            bn::fixed rotationAngle;
            bn::optional<DebugBox> hitbox;
            bn::optional<bn::sprite_ptr> sprite;
            bn::optional<bn::sprite_animate_action<4>> animation;
            bn::array<Obstacle*, 15> obstacleList;
            StateMachine* stateMachine;
            FlappyBird(bn::fixed, bn::fixed);
            FlappyBird* setSprite(bn::sprite_ptr);
            FlappyBird* setWeight(bn::fixed);
            void setX(bn::fixed);
            void setY(bn::fixed);
            void update();
            void render();
            void calculateRotation();
            void watchObstacles(bn::array<Obstacle*, 15>);
            bool collidesWith(Obstacle*);
            bool collidesWith(bn::fixed, bn::fixed, int, int, Obstacle*);
            FlappyBird* showHitbox();
            FlappyBird* hideHitbox();
            FlappyBird* setCamera(bn::optional<bn::camera_ptr>);
            void enableBlending();
            void disableBlending();
            bn::string<32> getStateName();
            FlappyBird* setRenderPriority(int);
            FlappyBird* show();
            FlappyBird* hide();
    };
#endif