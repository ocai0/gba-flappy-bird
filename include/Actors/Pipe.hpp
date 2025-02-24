#ifndef PIPE_H_
#define PIPE_H_

    #include "bn_optional.h"
    #include "bn_sprite_ptr.h"
    #include "bn_camera_ptr.h"
    #include "bn_sprite_palette_ptr.h"

    #include "Actors/Obstacle.hpp"
    #include "Actors/DebugBox.hpp"

    #include "bn_sprite_items_common_pipe.h"

    class Pipe : public Obstacle {
        bn::fixed xSpeed;
        bn::optional<bn::sprite_ptr> sprite;
        bn::optional<DebugBox> hitbox;
        bn::optional<bn::camera_ptr> camera;
        bn::fixed offsetX;
        bn::fixed offsetY;
        public:
            Pipe(bn::fixed, bn::fixed);
            Pipe* setX(bn::fixed);
            Pipe* setOffsetX(bn::fixed);
            Pipe* setOffsetY(bn::fixed);
            Pipe* setY(bn::fixed);
            Pipe* setXSpeed(bn::fixed);
            Pipe* setSprite(const bn::sprite_item*);
            bn::fixed getHeight();
            void update();
            Pipe* showHitbox();
            Pipe* hideHitbox();
            Pipe* setPalette(bn::sprite_palette_ptr);
            Pipe* flipVertically();
            Pipe* setCamera(bn::optional<bn::camera_ptr>);
            Pipe* addBody();
            Pipe* removeBody();

            void enableBlending();
            void disableBlending();
            Pipe* setRenderPriority(int);
    };
#endif