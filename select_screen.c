/*
** EPITECH PROJECT, 2019
** runner
** File description:
** select
*/

#include "runner_includes.h"

void display_updated_select(sfKeyEvent key, sfRenderWindow *w, select_t *select)
{
    sfMusic_play(select->movesound);
    if (key.code == sfKeyW && select->second < 1)
        select->second++;
    if (key.code == sfKeyS && select->second > 0)
        select->second--;
    if (select->second == 1)
        select->texture = sfTexture_createFromFile("media/Normal.png", NULL);
    if (select->second == 0)
        select->texture = sfTexture_createFromFile("media/Back.png", NULL);
    sfSprite_setTexture(select->sprite, select->texture, 1);
    sfRenderWindow_drawSprite(w, select->sprite, NULL);
    sfRenderWindow_display(w);
}

void display_updated_start(sfKeyEvent key, sfRenderWindow *w, select_t *select)
{
    if (key.code == sfKeyW && select->first < 1)
        select->first = select->first + 1;
    if (key.code == sfKeyS && select->first > 0)
        select->first = select->first - 1;
    if (select->first == 1)
        select->texture = sfTexture_createFromFile("media/Start.png", NULL);
    if (select->first == 0)
        select->texture = sfTexture_createFromFile("media/Exit.png", NULL);
    sfSprite_setTexture(select->sprite, select->texture, 1);
    sfRenderWindow_drawSprite(w, select->sprite, NULL);
    sfRenderWindow_display(w);
}

int set_selection(sfKeyEvent key, sfRenderWindow *w, select_t *select)
{
    if (key.code == sfKeyW || key.code == sfKeyS) {
        display_updated_select(key, w, select);
        return (0);
    }
    if (key.code == sfKeySpace) {
        sfMusic_play(select->selectsound);
        if (select->second == 1)
            return (1);
        if (select->second == 0) {
            select->texture = sfTexture_createFromFile("media/Start.png", NULL);
            sfSprite_setTexture(select->sprite, select->texture, 1);
            sfRenderWindow_drawSprite(w, select->sprite, NULL);
            sfRenderWindow_display(w);
            return (-1);
        }
    }
    return (0);
}

int start_selection(sfRenderWindow *window, select_t *select)
{
    int x = 0;
    sfEvent *event = malloc(sizeof(sfEvent));

    while (x == 0) {
        sfRenderWindow_waitEvent(window, event);
        if (event->type == sfEvtKeyPressed)
            x = set_selection(event->key, window, select);
        if (x == -1) {
            free (event);
            return (0);
        }
    }
    free (event);
    return (x);
}

int analyse_selection(sfKeyEvent key, sfRenderWindow *window, select_t *select)
{
    int x = 0;

    if (key.code == sfKeyW || key.code == sfKeyS) {
        sfMusic_play(select->movesound);
        display_updated_start(key, window, select);
        return (0);
    }
    if (key.code == sfKeySpace) {
        sfMusic_play(select->selectsound);
        if (select->first == 1) {
            display_updated_select(key, window, select);
            x = start_selection(window, select);
            return (x);
        }
        if (select->first == 0)
            return (3);
    }
    return (0);
}
