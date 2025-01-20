#ifndef SMALL_SCORE_FONT_H_
#define SMALL_SCORE_FONT_H_

    #include "bn_sprite_font.h"
    #include "bn_utf8_characters_map.h"
    #include "bn_sprite_items_fixed_8x16_font.h"


    constexpr bn::utf8_character fixed_8x16_sprite_font_utf8_characters[] = { "Á", "É", "Í", "Ó", "Ú", "Ü", "Ñ", "á", "é", "í", "ó", "ú", "ü", "ñ", "¡", "¿" };
    constexpr int8_t variable_8x16_sprite_font_character_widths[] = {
            8,  // 32
            8,  // 33 !
            8,  // 34 "
            8,  // 35 #
            8,  // 36 $
            8,  // 37 %
            8,  // 38 &
            8,  // 39 '
            8,  // 40 (
            8,  // 41 )
            8,  // 42 *
            8,  // 43 +
            8,  // 44 ,
            8,  // 45 -
            8,  // 46 .
            8,  // 47 /
            6,  // 48 0
            4,  // 49 1
            6,  // 50 2
            6,  // 51 3
            6,  // 52 4
            6,  // 53 5
            6,  // 54 6
            6,  // 55 7
            6,  // 56 8
            6,  // 57 9
            8,  // 58 :
            8,  // 59 ;
            8,  // 60 <
            8,  // 61 =
            8,  // 62 >
            8,  // 63 ?
            8,  // 64 @
            8,  // 65 A
            8,  // 66 B
            8,  // 67 C
            8,  // 68 D
            8,  // 69 E
            8,  // 70 F
            8,  // 71 G
            8,  // 72 H
            8,  // 73 I
            8,  // 74 J
            8,  // 75 K
            8,  // 76 L
            8,  // 77 M
            8,  // 78 N
            8,  // 79 O
            8,  // 80 P
            8,  // 81 Q
            8,  // 82 R
            8,  // 83 S
            8,  // 84 T
            8,  // 85 U
            8,  // 86 V
            8,  // 87 W
            8,  // 88 X
            8,  // 89 Y
            8,  // 90 Z
            8,  // 91 [
            8,  // 92
            8,  // 93 ]
            8,  // 94 ^
            8,  // 95 _
            8,  // 96 `
            8,  // 97 a
            8,  // 98 b
            8,  // 99 c
            8,  // 100 d
            8,  // 101 e
            8,  // 102 f
            8,  // 103 g
            8,  // 104 h
            8,  // 105 i
            8,  // 106 j
            8,  // 107 k
            8,  // 108 l
            8,  // 109 m
            8,  // 110 n
            8,  // 111 o
            8,  // 112 p
            8,  // 113 q
            8,  // 114 r
            8,  // 115 s
            8,  // 116 t
            8,  // 117 u
            8,  // 118 v
            8,  // 119 w
            8,  // 120 x
            8,  // 121 y
            8,  // 122 z
            8,  // 123 {
            8,  // 124 |
            8,  // 125 }
            8,  // 126 ~
            8,  // Á
            8,  // É
            8,  // Í
            8,  // Ó
            8,  // Ú
            8,  // Ü
            8,  // Ñ
            8,  // á
            8,  // é
            8,  // í
            8,  // ó
            8,  // ú
            8,  // ü
            8,  // ñ
            8,  // ¡
            8,  // ¿
            };

    constexpr bn::span<const bn::utf8_character> fixed_8x16_sprite_font_utf8_characters_span(fixed_8x16_sprite_font_utf8_characters);

    constexpr auto fixed_8x16_sprite_font_utf8_characters_map = bn::utf8_characters_map<fixed_8x16_sprite_font_utf8_characters_span>();

    constexpr bn::sprite_font small_score_font(bn::sprite_items::fixed_8x16_font, fixed_8x16_sprite_font_utf8_characters_map.reference(), variable_8x16_sprite_font_character_widths);

#endif