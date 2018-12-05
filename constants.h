#pragma once
// includes
#include <SDL/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

// define of the booleans values
#define TRUE 1
#define FALSE 0

// height and width of the tiles
#define WIDTH_TILE 32
#define HEIGHT_TILE 32

// total sizes of the map (in blocs)
#define MAP_BLOCKS_WIDTH 135
#define MAP_BLOCKS_HEIGHT 84

// sizes of the screen (in pixels)
#define SCREEN_WIDTH 1440
#define SCREEN_HEIGHT 896

// total sizes of the map (in pixels)
#define MAP_PIXELS_X MAP_BLOCKS_WIDTH*WIDTH_TILE
#define MAP_PIXELS_Y MAP_BLOCKS_HEIGHT*HEIGHT_TILE

// sizes of the character (in pixels)
#define CHAR_WIDTH 32
#define CHAR_HEIGHT 32

// number corresponding to the level
#define MAP_WATER 1
#define MAP_NO_WATER 2

// sizes of pannel
#define PANNEL_WIDTH 870
#define PANNEL_HEIGHT 206

// define of the max pictures/seconds
#define FPS_CAP 25

// define the volume of the sounds played on differents channels
#define VOLUME_THEME 10
#define VOLUME_EVENT 50

// define of the index of each tileset of the atlas->tileset
#define TILESET1 1
#define TILESET2 2
#define TILESET3 3

// define of the index of each picture in the atlas
#define HERO 0
#define OLD_MAN 1
#define OLD_WOMAN 2
#define WATERFALL 3
#define INNKEEPER 4
#define COUNTRY_GUARD 5
#define KIDM 6
#define KIDF 7
#define WOOD_HUNTER 8
#define VILLAGER 9
#define FISH_HUNTER 10
#define CHAT_BOX 11
#define PANNEL 12
#define FOG 13

// define of the index of each boolean in the booleanTab
#define BOOL_WATERFALL 0
#define BOOL_TP_CAVE 1
#define BOOL_FOG 2
#define BOOL_PANNEL 3
#define BOOL_PANNEL_CAVE 4
#define BOOL_PANNEL_START 5

// define of a boolean value (only 1 because only used to make it TRUE, by default FALSE)
#define NEG 1

// define of the sizes of tables
#define SIZE_ATLAS 14
#define SIZE_TAB_BOOLEAN 6

#define MAP_BUILDER 0
#define MAP_BOOLEAN 1
