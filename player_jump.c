/*
** EPITECH PROJECT, 2019
** runner
** File description:
** jump
*/

#include "runner_includes.h"

void bring_character_down(character_t *p, int type)
{
    sfVector2f pv;

    if (type == 0)
        sfSprite_setPosition(p->visuals->sprite, p->visuals->vector);
    if (type == 1) {
        pv = sfSprite_getPosition(p->visuals->sprite);
        if (pv.y > 640) {
            sfSprite_setPosition(p->visuals->sprite, p->visuals->vector);
            p->anim_counter = 6;
        }
    }
}

void move_jump(character_t *player)
{
    sfVector2f jump;

    if (player->anim == 1 && player->anim_counter >= 1) {
        jump.x = 0;
        jump.y = -30;
        bring_character_down(player, 1);
        if (player->anim_counter == 3)
            jump.y = 0;
        if (player->anim_counter > 3)
            jump.y = 30 + player->startinghight;
        if (player->anim_counter >= 1 && player->anim_counter < 6)
            sfSprite_move(player->visuals->sprite, jump);
    }
}

void animate_playerjump(character_t *player)
{
    move_jump(player);
    if (player->anim_counter == 6) {
        player->visuals->rect.left = 0;
        bring_character_down(player, 0);
        player->visuals->texture = sfTexture_createFromFile("media/player.png", NULL);
        player->anim_counter = 0;
        player->anim = 0;
        player->doublejump = 0;
        player->startinghight = 0;
    }
}

void manage_jump(sfRenderWindow *w, character_t *character, c_t *c)
{
    sfTime time = sfClock_getElapsedTime(c->animclock);
    float seconds = time.microseconds / 1000000.0;
    sfTime jumptime = sfClock_getElapsedTime(c->jumpclock);
    float jumpseconds = jumptime.microseconds / 1000000.0;

    if (character->anim == 1 && jumpseconds > 0.05) {
        animate_playerjump(character);
        sfClock_restart(c->jumpclock);
    }
    if (character->anim == 1 && seconds > 0.2) {
        change_character(character->visuals, w);
        character->anim_counter++;
        sfClock_restart(c->animclock);
    }
}
