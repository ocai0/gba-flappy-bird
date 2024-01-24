#include "Entities/GetReady.hpp"

GetReady::GetReady() : map_item(this->tilemap[0], bn::size(GetReady::COLUMNS, GetReady::ROWS)) {
    bn::regular_bg_item bg_item(bn::regular_bg_tiles_items::bg_tiles, bn::bg_palette_items::palette, this->map_item);
    bn::regular_bg_ptr bg = bg_item.create_bg(0, 0);
    bn::regular_bg_map_ptr bg_map = bg.map();
}

void GetReady::copyTileIndexes() {

}