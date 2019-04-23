/*
** EPITECH PROJECT, 2018
** player
** File description:
** player
*/

#include "runner_includes.h"

void destroy_character(character_t *character)
{
    destroy_object(character->visuals);
    destroy_object(character->hearts);
    free (character);
}

void change_character(gameobject_t *x, sfRenderWindow *w)
{
    sfSprite_setTexture(x->sprite, x->texture, 1);
    sfSprite_setTextureRect(x->sprite, x->rect);
    sfRenderWindow_drawSprite(w, x->sprite, NULL);
    move_rect(&x->rect, x->speed, 2000);
}

void manage_player(character_t *p, sfRenderWindow *w, c_t *c)
{
    sfTime time = sfClock_getElapsedTime(c->animclock);
    float seconds = time.microseconds / 1000000.0;
    sfTime jumptime = sfClock_getElapsedTime(c->jumpclock);
    float jumpseconds = jumptime.microseconds / 1000000.0;
    if (p->anim >= 2 && jumpseconds > 0.05)
        dash(p, w, c->jumpclock);
    if (p->anim == 1)
        manage_jump(w, p, c);
    if ((p->anim == 0 || p->anim == 2 || p->anim == 4) && seconds > 0.12) {
        change_character(p->visuals, w);
        sfClock_restart(c->animclock);
    }
    sfRenderWindow_drawSprite(w, p->visuals->sprite, NULL);
}

void create_player(character_t *player)
{
    sfVector2f vector;
    sfIntRect rect;

    vector.x = 50;
    vector.y = 640;
    set_rectangle(&rect, 400, 400);
    player->visuals = create_object("media/player.png", vector, rect, 400);
    player->hearts = create_object("media/heart.png", vector, rect, 192);
    vector.x = 1980;
    vector.y = 0;
    set_rectangle(&rect, 1200, 1080);
    player->poison = create_object("media/debuff.png", vector, rect, 1200);
    player->lives = 3;
    player->anim = 0;
    player->anim_counter = 0;
    player->anim_cnt_save = 0;
    player->doublejump = 0;
    player->startinghight = 0;
    player->debuff = 0;
}
