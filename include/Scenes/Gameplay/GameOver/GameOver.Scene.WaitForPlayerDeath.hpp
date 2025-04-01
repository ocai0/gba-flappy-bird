#ifndef GAME_OVER_WAIT_FOR_PLAYER_DEATH_H_
#define GAME_OVER_WAIT_FOR_PLAYER_DEATH_H_

    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"
    #include "Scenes/Gameplay/GameOver/GameOver.Scene.RenderScoreboard.hpp"

    namespace _Gameplay { class GameOver; }
    namespace _GameOver {
        const bn::string<32> STR_DEAD_STATE("DeadState");

        class WaitForPlayerDeath : public AbstractState {
            bool fadeComplete = false;
            bn::fixed fadeIntensity = .1;
            const bn::fixed step = .08;
            int fadeMultiplierSign = 1;
            public:
                _Gameplay::GameOver* gameoverScene;
                WaitForPlayerDeath(_Gameplay::GameOver*);
                void load();
                void update();
                void render();
                void leave();
        };
    }

#endif