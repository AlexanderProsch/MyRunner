/*
** EPITECH PROJECT, 2019
** runner
** File description:
** create_destroy_manage
*/

#include "runner_includes.h"

void control(sfEvent *e, score_t *s, character_t *p, sfRenderWindow *w)
{
    if (sfRenderWindow_pollEvent(w, e) == sfTrue)
        analyse_events(w, e, p);
    end_condition(w, p, s);
}

void manage(c_t *c, character_t *p, background_t *b, sfRenderWindow *w)
{
    sfRenderWindow_display(w);
    manage_background(b, w, c->bkclock);
    manage_player(p, w, c);
}

void create(c_t *c, score_t *s, background_t *b, character_t *p)
{
    create_clock(c);
    create_level_background(b);
    create_player(p);
    create_score(s);
}

void destroy(c_t *c, score_t *s, background_t *b, character_t *p)
{
    destroy_clock(c);
    destroy_score(s);
    destroy_level_background(b);
    destroy_character(p);
}
