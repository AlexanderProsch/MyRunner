/*
** EPITECH PROJECT, 2019
** runner
** File description:
** lives
*/

#include "runner_includes.h"

void draw_lives(sfRenderWindow *window, int lives, gameobject_t *hearts)
{
    int hp = lives;
    sfVector2f vector;

    vector.x = 50;
    vector.y = 0;
    sfSprite_setTexture(hearts->sprite, hearts->texture, 1);
    while (hp != 0) {
        sfSprite_setPosition(hearts->sprite, vector);
        sfRenderWindow_drawSprite(window, hearts->sprite, NULL);
        vector.x = vector.x + 240;
        hp--;
    }
}
