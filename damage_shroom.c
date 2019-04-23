/*
** EPITECH PROJECT, 2019
** runner
** File description:
** shroom_collision
*/

#include "runner_includes.h"

int test_shroom_upperleft(sfVector2f bad, sfVector2f you)
{
    if ((bad.x + 10) > (you.x + 124) && (bad.x + 10) < (you.x + 240)) {
        if ((bad.y + 20) > (you.y + 115) && (bad.y + 20) < (you.y + 320))
            return (1);
    }
    return (0);
}

int test_shroom_upperright(sfVector2f bad, sfVector2f you)
{
    if ((bad.x + 70) > (you.x + 124) && (bad.x + 70) < (you.x + 240)) {
        if ((bad.y + 20) > (you.y + 115) && (bad.y + 20) < (you.y +  320))
            return (1);
    }
    return (0);
}

int test_collision_shroom(sfVector2f bad, sfVector2f you)
{
    int x = 0;

    x = x + test_shroom_upperleft(bad, you);
    x = x + test_shroom_upperright(bad, you);
    if (x > 0)
        return (1);
    return (0);
}
