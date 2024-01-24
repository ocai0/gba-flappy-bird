#ifndef GET_READY_H_
#define GET_READY_H_

    #include "bn_regular_bg_map_cell.h"
    #include "bn_regular_bg_item.h"
    #include "bn_regular_bg_ptr.h"
    #include "bn_regular_bg_map_ptr.h"
    #include "bn_unique_ptr.h"
    #include "bn_regular_bg_tiles_items_bg_tiles.h"
    #include "bn_bg_palette_items_palette.h"



    class GetReady {
        static constexpr int COLUMNS = 32;
        static constexpr int ROWS = 32;
        static constexpr int cells_count = COLUMNS * ROWS;
        alignas(int) bn::regular_bg_map_cell tilemap[cells_count];
        bn::regular_bg_map_item map_item;
        void copyTileIndexes();

        public:
            GetReady();
            void setOpacity(int opacity);
            void destroy();
    };

#endif