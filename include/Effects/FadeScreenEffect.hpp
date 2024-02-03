#ifndef FADE_SCREEN_EFFECT_H_
#define FADE_SCREEN_EFFECT_H_

    #include "bn_blending.h"
    #include "Math.hpp"

    enum class FadeScreenEffectType { FADE_IN, FADE_OUT, FADE_IN_OUT };

    class FadeScreenEffect {
        bool _active;
        FadeScreenEffectType effectType;
        bn::fixed _stepValue;
        int effectCount;
        bn::fixed currentValue;
        bn::blending::fade_color_type fadeColor;
        
        bn::fixed calculateStepValue(int);

        public:
            FadeScreenEffect(bn::blending::fade_color_type, bn::fixed);
            void fadeInOut();
            void start();
            bool isAlive();
            void update();
            void stop();
    };

#endif