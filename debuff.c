/*
** EPITECH PROJECT, 2019
** runner
** File description:
** debuff
*/

#include "runner_includes.h"

void move_debuff(sfRenderWindow *w, gameobject_t *poison, float s)
{
    sfVector2f vector;

    vector.x = -24;
    vector.y = 0;
    if (s >= 5)
        vector.x = 0;
    if (s > 10)
        vector.x = 24;
    sfSprite_move(poison->sprite, vector);
}

void animate_debuff(sfRenderWindow *w, gameobject_t *poison)
{
    sfSprite_setTexture(poison->sprite, poison->texture, 1);
    sfSprite_setTextureRect(poison->sprite, poison->rect);
    sfRenderWindow_drawSprite(w, poison->sprite, NULL);
}

void manage_debuff(sfRenderWindow *w, character_t *player, c_t *c, float s)
{
    sfTime effecttime = sfClock_getElapsedTime(c->effect);
    float tick = effecttime.microseconds / 1000000.0;
    sfTime anim_time = sfClock_getElapsedTime(c->d_anim);
    float anim_seconds = anim_time.microseconds / 1000000.0;

    if (tick > 0.1) {
        move_debuff(w, player->poison, s);
        sfClock_restart(c->effect);
    }
    if (anim_seconds > 0.3) {
        animate_debuff(w, player->poison);
        sfClock_restart(c->d_anim);
    }
    sfRenderWindow_drawSprite(w, player->poison->sprite, NULL);
}

void check_for_debuff(sfRenderWindow *w, character_t *player, c_t *c)
{
    sfTime time = sfClock_getElapsedTime(c->d_clock);
    float seconds = time.microseconds / 1000000.0;

    if (player->debuff == 0)
        sfClock_restart(c->d_clock);
    if (player->debuff == 1) {
        sfSprite_setTexture(player->poison->sprite, player->poison->texture, 1);
        sfRenderWindow_drawSprite(w, player->poison->sprite, NULL);
        if (seconds > 15)
            player->debuff = 0;
    }
    if (player->debuff == 1)
        manage_debuff(w, player, c, seconds);
}
