#ifndef SRAM_DATA_H_
#define SRAM_DATA_H_

    #include "bn_sram.h"

    namespace _SramData {
        typedef struct {
            int highScore = 0;
        } data;
    }

    class SramData {
        SramData() {}
        ~SramData() {}
        _SramData::data _data;
        int highScore;
        bool _loaded = false;
        public:
            SramData(const SramData&) = delete;
            SramData& operator=(const SramData&) = delete;
            static SramData& getInstance();
            void load();
            void write();
            void clear();

            int getHighScore();
            SramData* setHighScore(int);
    };
#endif