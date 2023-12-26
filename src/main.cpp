#include "bn_core.h"
#include "bn_sprite_ptr.h"

#include "bn_sprite_items_flappy.h"

int main()
{
    bn::core::init();
    bn::sprite_ptr sprite = bn::sprite_items::flappy.create_sprite(0, 0);

    while(true)
    {
        bn::core::update();
    }
}
