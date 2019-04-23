/*
** EPITECH PROJECT, 2019
** runner
** File description:
** clocks
*/

#include "runner_includes.h"

void destroy_clock(c_t *c)
{
    sfClock_destroy(c->damage);
    sfClock_destroy(c->jumpclock);
    sfClock_destroy(c->animclock);
    sfClock_destroy(c->bkclock);
    sfClock_destroy(c->enemyclock);
    sfClock_destroy(c->spawn);
    sfClock_destroy(c->effect);
    sfClock_destroy(c->d_clock);
    sfClock_destroy(c->d_anim);
    free (c);
}

void create_clock(c_t *c)
{
    c->spawn = sfClock_create();
    c->damage = sfClock_create();
    c->enemyclock = sfClock_create();
    c->animclock = sfClock_create();
    c->jumpclock = sfClock_create();
    c->bkclock = sfClock_create();
    c->effect = sfClock_create();
    c->d_clock = sfClock_create();
    c->d_anim = sfClock_create();
}
