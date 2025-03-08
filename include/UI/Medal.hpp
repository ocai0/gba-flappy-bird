#ifndef UI_MEDAL_H_
#define UI_MEDAL_H_

    #include "bn_core.h"
    #include "bn_sprite_ptr.h"
    #include "bn_optional.h"
    #include "bn_sprite_animate_actions.h"

    #include "bn_sprite_items_ui_medal.h"
    #include "bn_sprite_items_ui_particle.h"

    namespace UI {
        class Medal {
            public:
                bn::fixed x;
                bn::fixed y;
                bn::optional<bn::sprite_ptr> sprite;
                bn::optional<bn::sprite_ptr> bottomLeftParticle;
                bn::optional<bn::sprite_animate_action<8>> bottomLeftParticleAnimation;
                bn::optional<bn::sprite_ptr> centerParticle;
                bn::optional<bn::sprite_animate_action<8>> centerParticleAnimation;
                bn::optional<bn::sprite_ptr> topRightParticle;
                bn::optional<bn::sprite_animate_action<8>> topRightParticleAnimation;
                Medal(bn::fixed, bn::fixed);
                Medal* setX(bn::fixed);
                Medal* setY(bn::fixed);
                Medal* useBronzeSprite();
                Medal* useSilverSprite();
                Medal* useGoldSprite();
                Medal* usePlatinumSprite();
                Medal* showShinyParticles();
                Medal* showShinyParticles(int);
                Medal* hideShinyParticles();
                Medal* setPriority(int);
                void render();
        };
    }

#endif