#ifndef GAME_OVER_RENDER_BUTTONS_H_
#define GAME_OVER_RENDER_BUTTONS_H_

    #include "Commons/AbstractState.hpp"
    #include "Scenes/Gameplay/Gameplay.Scene.GameOver.hpp"
    #include "Scenes/MainMenu.Scene.hpp"

    namespace _Gameplay { class GameOver; }
    namespace _GameOver {
        enum UserOptions { RESTART_GAME, MAIN_MENU };
        constexpr int RESTART_BTN_X_POS = -50;
        constexpr int BTN_Y_POS = 42;
        constexpr int PADDING_BTW_BTNS = 5;
        constexpr int RESTART_BTN_WIDTH = 64;

        class RenderButtons : public AbstractState {

            public:
                UserOptions option;
                _Gameplay::GameOver* gameoverScene;
                RenderButtons(_Gameplay::GameOver*);
                void load();
                void update();
                void render();
                void leave();
        };
    }
#endif