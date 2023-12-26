#include "bn_core.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_tiles_ptr.h"
#include "bn_keypad.h"
#include "bn_sprite_animate_actions.h"

#include "bn_sprite_items_flappy.h"

int main()
{
    bn::core::init();
    bn::sprite_ptr flappy_sprite = bn::sprite_items::flappy.create_sprite(0, 0);
    int animating = 0; //[0 => not animating, 1 => animating]
    int setup_flappy_animation = 0;
    bn::sprite_animate_action<4> action = bn::create_sprite_animate_action_forever(flappy_sprite, 16, bn::sprite_items::flappy.tiles_item(), 0, 0, 0, 0);

    while(true)
    {
        if(bn::keypad::a_pressed()) animating = 1;
        if(animating == 1 && setup_flappy_animation == 0) {
            setup_flappy_animation = 1;
            action = bn::create_sprite_animate_action_forever(flappy_sprite, 6, bn::sprite_items::flappy.tiles_item(), 0, 1, 2, 1);
        }
        action.update();
        bn::core::update();
    }
}
