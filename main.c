/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "runner_includes.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left <= max_value)
        rect->left = rect->left + offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

void set_rectangle(sfIntRect *rectangle, int width, int height)
{
    rectangle->top = 0;
    rectangle->left = 0;
    rectangle->width = width;
    rectangle->height = height;
}

void organize_all(sfRenderWindow *w, sfEvent *event, char *av)
{
    background_t *bg = malloc(sizeof(background_t));
    character_t *player = malloc(sizeof(character_t));
    enemy_t *list;
    map_t *map = malloc(sizeof(map_t));
    c_t *clock = malloc(sizeof(c_t));
    score_t *score = malloc(sizeof(score_t));

    create_map(map, av);
    create(clock, score, bg, player);
    list = create_enemy();
    while (sfRenderWindow_isOpen(w)) {
        manage(clock, player, bg, w);
        manage_score(score, w);
        list = loadnewenemy(w, list, clock);
        list = load_map(list, map);
        list = check_damage(player, list, clock->damage);
        check_for_debuff(w, player, clock);
        control(event, score, player, w);
    }
    destroy(clock, score, bg, player);
}

int main(int argc, char **argv)
{
    sfRenderWindow *window;
    sfEvent *event;
    int x = 0;
    int y = 0;

    srand(time(0));
    y = test_for_instructions(argc, argv);
    if (y == 1)
        return (0);
    if (y == 2)
        return (84);
    event = malloc(sizeof(sfEvent));
    window = create_my_window(1920, 1080);
    sfRenderWindow_setFramerateLimit(window, 60);
    x = manage_selectscreen(window, event);
    if (x == 0)
        organize_all(window, event, argv[1]);
    sfRenderWindow_destroy(window);
    free(event);
    return (0);
}
