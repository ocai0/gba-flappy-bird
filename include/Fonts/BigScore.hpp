#ifndef BIG_SCORE_FONT_H_
#define BIG_SCORE_FONT_H_

    #include "bn_sprite_font.h"
    #include "bn_utf8_characters_map.h"
    #include "bn_sprite_items_fixed_16x32_font.h"


    constexpr bn::utf8_character fixed_16x32_sprite_font_utf8_characters[] = { "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿" };
    constexpr int8_t variable_16x32_sprite_font_character_widths[] = {
            16,  // 32
            16,  // 33 !
            16,  // 34 "
            16,  // 35 #
            16,  // 36 $
            16,  // 37 %
            16,  // 38 &
            16,  // 39 '
            16,  // 40 (
            16,  // 41 )
            16,  // 42 *
            16,  // 43 +
            16,  // 44 ,
            16,  // 45 -
            16,  // 46 .
            16,  // 47 /
            12,  // 48 0
            6,  // 49 1
            10,  // 50 2
            12,  // 51 3
            12,  // 52 4
            12,  // 53 5
            12,  // 54 6
            12,  // 55 7
            12,  // 56 8
            12,  // 57 9
            16,  // 58 :
            16,  // 59 ;
            16,  // 60 <
            16,  // 61 =
            16,  // 62 >
            16,  // 63 ?
            16,  // 64 @
            16,  // 65 A
            16,  // 66 B
            16,  // 67 C
            16,  // 68 D
            16,  // 69 E
            16,  // 70 F
            16,  // 71 G
            16,  // 72 H
            16,  // 73 I
            16,  // 74 J
            16,  // 75 K
            16,  // 76 L
            16,  // 77 M
            16,  // 78 N
            16,  // 79 O
            16,  // 80 P
            16,  // 81 Q
            16,  // 82 R
            16,  // 83 S
            16,  // 84 T
            16,  // 85 U
            16,  // 86 V
            16,  // 87 W
            16,  // 88 X
            16,  // 89 Y
            16,  // 90 Z
            16,  // 91 [
            16,  // 92
            16,  // 93 ]
            16,  // 94 ^
            16,  // 95 _
            16,  // 96 `
            16,  // 97 a
            16,  // 98 b
            16,  // 99 c
            16,  // 100 d
            16,  // 101 e
            16,  // 102 f
            16,  // 103 g
            16,  // 104 h
            16,  // 105 i
            16,  // 106 j
            16,  // 107 k
            16,  // 108 l
            16,  // 109 m
            16,  // 110 n
            16,  // 111 o
            16,  // 112 p
            16,  // 113 q
            16,  // 114 r
            16,  // 115 s
            16,  // 116 t
            16,  // 117 u
            16,  // 118 v
            16,  // 119 w
            16,  // 120 x
            16,  // 121 y
            16,  // 122 z
            16,  // 123 {
            16,  // 124 |
            16,  // 125 }
            16,  // 126 ~
            16,  // Á
            16,  // É
            16,  // Í
            16,  // Ó
            16,  // Ú
            16,  // Ü
            16,  // Ñ
            16,  // á
            16,  // é
            16,  // í
            16,  // ó
            16,  // ú
            16,  // ü
            16,  // ñ
            16,  // ¡
            16,  // ¿
            };

    constexpr bn::span<const bn::utf8_character> fixed_16x32_sprite_font_utf8_characters_span(fixed_16x32_sprite_font_utf8_characters);

    constexpr auto fixed_16x32_sprite_font_utf8_characters_map = bn::utf8_characters_map<fixed_16x32_sprite_font_utf8_characters_span>();

    constexpr bn::sprite_font big_score_font(bn::sprite_items::fixed_16x32_font, fixed_16x32_sprite_font_utf8_characters_map.reference(), variable_16x32_sprite_font_character_widths);


#endif
