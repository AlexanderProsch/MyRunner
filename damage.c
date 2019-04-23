/*
** EPITECH PROJECT, 2019
** runner
** File description:
** damage
*/

#include "runner_includes.h"

int test_rock_upperleft(sfVector2f bad, sfVector2f you)
{
    if ((bad.x + 55) > (you.x + 124) && (bad.x + 55) < (you.x + 240)) {
        if ((bad.y + 23) > (you.y + 115) && (bad.y + 23) < (you.y + 320))
            return (1);
    }
    return (0);
}

int test_rock_upperright(sfVector2f bad, sfVector2f you)
{
    if ((bad.x + 200) > (you.x + 124) && (bad.x + 200) < (you.x + 240)) {
        if ((bad.y + 23) > (you.y + 115) && (bad.y + 23) < (you.y +  320))
            return (1);
    }
    return (0);

}

int test_collision_rock(sfVector2f bad, sfVector2f you)
{
    int x = 0;

    x = x + test_rock_upperleft(bad, you);
    x = x+ test_rock_upperright(bad, you);
    if (x >0)
        return (1);
    return (0);
}

int manage_type(sfVector2f bad, sfVector2f you, int type, character_t *p)
{
    int x = 0;

    if (type == 4)
        x = test_collision_rock(bad, you);
    if (type == 3) {
        x = test_collision_shroom(bad, you);
        if (x == 1) {
            p->debuff = 1;
            x = 0;
        }
    }
    if (type == 2)
        x = test_collision_shroom(bad, you);
    if (type == 1)
        x = test_collision_bat(bad, you);
    return (x);
}

enemy_t *check_damage(character_t *player, enemy_t *enemy, sfClock *clock)
{
    enemy_t *tmp = enemy;
    sfVector2f bad;
    sfVector2f you;
    int x = 0;
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    while (seconds > 2 && tmp != 0 && player->anim < 2) {
        bad = sfSprite_getPosition(tmp->visuals->sprite);
        you = sfSprite_getPosition(player->visuals->sprite);
        x = manage_type(bad, you, tmp->type, player);
        if (x == 1) {
            player->lives--;
            sfClock_restart(clock);
            return (enemy);
        }
        tmp = tmp->next;
    }
    return (enemy);
}
