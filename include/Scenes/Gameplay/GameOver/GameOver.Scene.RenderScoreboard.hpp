#ifndef GAME_OVER_RENDER_SCOREBOARD_H_
#define GAME_OVER_RENDER_SCOREBOARD_H_

    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"
    #include "Scenes/Gameplay/GameOver/GameOver.Scene.RenderButtons.hpp"

    namespace _Gameplay { class GameOver; }
    namespace _GameOver {
        const bn::string<32> STR_SCORE_ANIMATION_START("ScoreAnimation.Start");
        const bn::string<32> STR_SCORE_ANIMATION_END("ScoreAnimation.End");

        class RenderScoreboard : public AbstractState {
            public:
                _Gameplay::GameOver* gameoverScene;
                RenderScoreboard(_Gameplay::GameOver*);
                void load();
                void update();
                void render();
                void leave();
        };
    }

#endif