/*
** EPITECH PROJECT, 2019
** runner
** File description:
** select create destroy manage
*/

#include "runner_includes.h"

void create_select(select_t *select)
{
    select->texture = sfTexture_createFromFile("media/Start.png", NULL);
    select->sprite = sfSprite_create();
    sfSprite_setTexture(select->sprite, select->texture, 1);
    select->first = 1;
    select->second = 0;
    select->movesound = sfMusic_createFromFile("media/move.ogg");
    sfMusic_setVolume(select->movesound, 20);
    select->selectsound = sfMusic_createFromFile("media/select.ogg");
    sfMusic_setVolume(select->selectsound, 20);
    select->music = sfMusic_createFromFile("media/waiting.ogg");
    sfMusic_setVolume(select->music, 20);
    sfMusic_play(select->music);
    sfMusic_setLoop(select->music, sfTrue);
}

void destroy_select(select_t *select)
{
    sfMusic_destroy(select->music);
    sfMusic_destroy(select->selectsound);
    sfMusic_destroy(select->movesound);
    sfTexture_destroy(select->texture);
    sfSprite_destroy(select->sprite);
    free (select);
}

int manage_selectscreen(sfRenderWindow *w, sfEvent *eve)
{
    int x = 0;
    select_t *select = malloc(sizeof(select_t));

    create_select(select);
    sfRenderWindow_drawSprite(w, select->sprite, NULL);
    sfRenderWindow_display(w);
    while (x == 0) {
        sfRenderWindow_waitEvent(w, eve);
        if (eve->type == sfEvtKeyPressed)
            x = analyse_selection(eve->key, w, select);
    }
    destroy_select(select);
    if (x == 3)
        return (1);
    return (0);
}
