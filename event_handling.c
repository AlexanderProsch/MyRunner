/*
** EPITECH PROJECT, 2019
** runner
** File description:
** event_handling
*/

#include "runner_includes.h"

void controls(sfKeyEvent key, character_t *p, sfRenderWindow *w)
{
    sfVector2f vector = sfSprite_getPosition(p->visuals->sprite);

    if (key.code == sfKeySpace && p->anim == 1 && p->doublejump == 0) {
        p->doublejump = 1;
        p->visuals->rect.left = 0;
        p->anim_counter = 0;
        p->startinghight = ((640 - vector.y) / 8);
    }
    if (key.code == sfKeySpace && p->anim == 0) {
        p->visuals->texture = sfTexture_createFromFile("media/Jump_sprite.png", NULL);
        p->visuals->rect.left = 0;
        p->anim = 1;
        p->anim_counter = 0;
    }
    if (key.code == sfKeyLShift && p->anim < 2)
        create_dash(p);
    if (key.code == sfKeyEscape)
        pause_screen(w);
}

void analyse_events(sfRenderWindow *w, sfEvent *e, character_t *player)
{
    if (e->type == sfEvtKeyPressed)
        controls(e->key, player, w);
    if (e->type == sfEvtClosed)
        sfRenderWindow_close(w);
}
