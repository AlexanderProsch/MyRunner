/*
** EPITECH PROJECT, 2018
** background
** File description:
** level
*/

#include "runner_includes.h"

void destroy_level_background(background_t *bg)
{
    sfMusic_destroy(bg->music);
    destroy_object(bg->ground);
    destroy_object(bg->horizon);
    destroy_object(bg->back);
    destroy_object(bg->middle);
    destroy_object(bg->near);
    destroy_object(bg->front);
    free(bg);
}

void create_level_background(background_t *bg)
{
    sfVector2f vector;
    sfIntRect rect;

    vector.x = 0;
    vector.y = 950;
    set_rectangle(&rect, 3840, 96);
    bg->ground = create_object("media/Ground.png", vector, rect, 8);
    set_rectangle(&rect, 3840, 1080);
    vector.y = 0;
    bg->horizon = create_object("media/plx-1.png", vector, rect, 0);
    bg->back = create_object("media/plx-2.png", vector, rect, 2);
    bg->middle = create_object("media/plx-3.png", vector, rect, 3);
    bg->near = create_object("media/plx-4.png", vector, rect, 5);
    bg->front = create_object("media/plx-5.png", vector, rect, 7);
    bg->music = sfMusic_createFromFile("media/game.ogg");
    sfMusic_setVolume(bg->music, 20);
    sfMusic_play(bg->music);
    sfMusic_setLoop(bg->music, sfTrue);
}

void change_background(gameobject_t *x, sfRenderWindow *w)
{
    sfSprite_setTexture(x->sprite, x->texture, 1);
    sfSprite_setTextureRect(x->sprite, x->rect);
    sfRenderWindow_drawSprite(w, x->sprite, NULL);
    move_rect(&x->rect, x->speed, 1920);
}

void manage_background(background_t *bg, sfRenderWindow *w, sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.01) {
        change_background(bg->horizon, w);
        change_background(bg->back, w);
        change_background(bg->middle, w);
        change_background(bg->near, w);
        change_background(bg->front, w);
        change_background(bg->ground, w);
        sfClock_restart(clock);
    }
}
