/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** pause
*/

#include "runner_includes.h"

int analyse_button(sfKeyEvent key, sfRenderWindow *w)
{
    if (key.code == sfKeyEscape)
        return (1);
    if (key.code == sfKeySpace) {
        sfRenderWindow_close(w);
        return (3);
    }
    return (0);
}

void create_pause(pause_t *pause)
{
    sfVector2f vector;
    sfIntRect rect;
    char *str = "PAUSE\npress spacebar to exit\npress escape to continue";

    set_rectangle(&rect, 1, 1);
    vector.x = 690;
    vector.y = 240;
    pause->visuals = create_object("media/Box.png", vector, rect, 0);
    pause->text = sfText_create();
    pause->font = sfFont_createFromFile("Pixeled.ttf");
    create_text(pause->text, 740, 340, pause->font);
    sfText_setCharacterSize(pause->text, 50);
    pause->color = sfColor_fromRGBA(255, 255, 255, 255);
    sfText_setString(pause->text, str);
    sfText_setFillColor(pause->text, pause->color);
}

void destroy_pause(pause_t *pause, sfEvent *event)
{
    destroy_object(pause->visuals);
    sfFont_destroy(pause->font);
    sfText_destroy(pause->text);
    free(event);
    free(pause);
}

void pause_screen(sfRenderWindow *window)
{
    sfEvent *event = malloc(sizeof(sfEvent));
    int x = 0;
    pause_t *pause = malloc(sizeof(pause_t));

    create_pause(pause);
    sfSprite_setTexture(pause->visuals->sprite, pause->visuals->texture, 1);
    sfRenderWindow_drawSprite(window, pause->visuals->sprite, NULL);
    sfRenderWindow_drawText(window, pause->text, NULL);
    sfRenderWindow_display(window);
    while (x == 0) {
        sfRenderWindow_waitEvent(window, event);
        if (event->type == sfEvtKeyPressed)
            x = analyse_button(event->key, window);
    }
    destroy_pause(pause, event);
}
