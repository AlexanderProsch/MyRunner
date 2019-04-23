/*
** EPITECH PROJECT, 2019
** runner
** File description:
** enemy_list_handling
*/

#include "runner_includes.h"

enemy_t *add_to_last(enemy_t *first, enemy_t *second)
{
    enemy_t *tmp = first;

    while (tmp->next != 0) {
        tmp = tmp->next;
    }
    tmp->next = second;
    return (first);
}

enemy_t *delete_enemy(enemy_t *enemy)
{
    sfVector2f vector;

    if (enemy->next == 0)
        return (enemy);
    vector = sfSprite_getPosition(enemy->visuals->sprite);
    if (vector.x < 0)
        enemy = enemy->next;
    return (enemy);
}

int create_condition(sfClock *clock)
{
    int con = rand() % 1000;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.5) {
        if (con < 10) {
            sfClock_restart(clock);
            return (1);
        }
    }
    return (0);
}
