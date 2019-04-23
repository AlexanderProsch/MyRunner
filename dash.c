/*
** EPITECH PROJECT, 2019
** runner
** File description:
** dash
*/

#include "runner_includes.h"

void create_dash(character_t *p)
{
    sfVector2f start = sfSprite_getPosition(p->visuals->sprite);
    p->anim = p->anim + 2;
    p->anim_counter = 0;
    if (p->anim == 3) {
        p->visuals->texture = sfTexture_createFromFile("media/dash.png", NULL);
        sfSprite_setTexture(p->visuals->sprite, p->visuals->texture, 1);
        p->startinghight = 640 - start.y;
    }
}

void dash_move_walk(character_t *player)
{
    sfVector2f vector;

    vector.x = 60;
    vector.y = 0;
    if (player->anim_counter >= 5)
        vector.x = -24;
    if (player->anim_counter == 15) {
        player->anim = 0;
        player->anim_counter = 0;
        vector.x = 0;
    }
    sfSprite_move(player->visuals->sprite, vector);
}

void dash_move(character_t *player)
{
    sfVector2f vector;

    vector.x = 40;
    vector.y = 0;
    if (player->anim_counter >= 5){
        vector.x = 20;
        vector.y = player->startinghight / 8;
    }
    if (player->anim_counter >= 13) {
        vector.x = -20;
        vector.y = 0;
        player->anim = 4;
    }
    if (player->anim_counter == 30) {
        vector.y = 0;
        vector.y = 0;
        player->anim = 0;
        player->anim_counter = 0;
    }
    sfSprite_move(player->visuals->sprite, vector);
}

void dash(character_t *player, sfRenderWindow *w, sfClock *clock)
{
    sfRenderWindow_drawSprite(w, player->visuals->sprite, NULL);
    player->anim_counter++;
    if (player->anim == 3 || player->anim == 4)
        dash_move(player);
    if (player->anim == 2)
        dash_move_walk(player);
    if (player->anim_counter == 13 && player->anim == 4)
        player->visuals->texture = sfTexture_createFromFile("media/player.png", NULL);
    if (player->anim == 0) {
        bring_character_down(player, 0);
        player->anim_counter = 0;
        player->startinghight = 0;
        player->doublejump = 0;
    }
    sfClock_restart(clock);
}
