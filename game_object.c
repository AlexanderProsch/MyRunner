/*
** EPITECH PROJECT, 2018
** gameobject
** File description:
** gameobject
*/

#include "runner_includes.h"

void create_text(sfText *text, int x, int y, sfFont *font)
{
    sfVector2f position;

    position.x = x;
    position.y = y;
    font = sfFont_createFromFile("Pixeled.ttf");
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 50);
    sfText_setPosition(text, position);
}

gameobject_t *create_object(char const *p, sfVector2f pos, sfIntRect r, int sp)
{
    gameobject_t *a = malloc(sizeof(gameobject_t));

    a->rect = r;
    a->texture = sfTexture_createFromFile(p, NULL);
    a->sprite = sfSprite_create();
    a->vector = pos;
    a->speed = sp;
    sfSprite_setPosition(a->sprite, a->vector);
    return (a);
}

void destroy_object(gameobject_t *ob)
{
    sfTexture_destroy(ob->texture);
    sfSprite_destroy(ob->sprite);
    free(ob);
}
