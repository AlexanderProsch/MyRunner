/*
** EPITECH PROJECT, 2018
** structures
** File description:
** structs
*/

#include "../runner_includes.h"
struct gameobject
{
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f vector;
    sfIntRect rect;
    int speed;
};
typedef struct gameobject gameobject_t;
struct score
{
    sfText *text;
    sfText *hightext;
    sfFont *font;
    sfClock *clock;
    int score;
    int meterpersec;
    int distance;
    char *str;
    char *highscore;
};
typedef struct score score_t;
struct select
{
    sfTexture *texture;
    sfSprite *sprite;
    int first;
    int second;
    sfMusic *music;
    sfMusic *selectsound;
    sfMusic *movesound;
};
typedef struct select select_t;
struct pause_menu
{
    gameobject_t *visuals;
    sfText *text;
    sfFont *font;
    sfColor color;
};
typedef struct pause_menu pause_t;
struct background
{
    gameobject_t *ground;
    gameobject_t *front;
    gameobject_t *near;
    gameobject_t *middle;
    gameobject_t *back;
    gameobject_t *horizon;
    sfMusic *music;
};
typedef struct background background_t;
struct character
{
    int debuff;
    gameobject_t *hearts;
    gameobject_t *visuals;
    gameobject_t *poison;
    int lives;
    int anim;
    int anim_counter;
    int anim_cnt_save;
    int doublejump;
    int startinghight;
};
typedef struct character character_t;
typedef struct enemy enemy_t;
struct enemy
{
    int type;
    gameobject_t *visuals;
    sfVector2f movement;
    enemy_t *next;
};
struct gameover
{
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfText *text2;
    sfText *score;
    int cc;
};
typedef struct gameover end_t;
struct map
{
    int x;
    char *str;
    sfClock *clock;
};
typedef struct map map_t;
struct clocks
{
    sfClock *spawn;
    sfClock *damage;
    sfClock *enemyclock;
    sfClock *animclock;
    sfClock *jumpclock;
    sfClock *bkclock;
    sfClock *effect;
    sfClock *d_clock;
    sfClock *d_anim;
};
typedef struct clocks c_t;
