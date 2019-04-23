/*
** EPITECH PROJECT, 2019
** runner
** File description:
** bat_collision
*/

#include "runner_includes.h"

int test_bat_upperleft(sfVector2f bad, sfVector2f you)
{
    if (bad.x > (you.x + 124) && bad.x < (you.x + 240)) {
        if (bad.y > (you.y + 115) && bad.y < (you.y + 320))
            return (1);
    }
    return (0);
}

int test_bat_upperright(sfVector2f bad, sfVector2f you)
{
    if ((bad.x + 130) > (you.x +  124) && (bad.x + 130) < (you.x + 240)) {
        if (bad.y > (you.y + 115) && bad.y < (you.y + 320))
            return (1);
    }
    return (0);
}

int test_bat_lowerleft(sfVector2f bad, sfVector2f you)
{
    if (bad.x > (you.x + 124) && bad.x < (you.x + 240)) {
        if ((bad.y + 70) > (you.y + 115) && (bad.y + 70) < (you.y  + 240))
            return (1);
    }
    return (0);
}

int test_bat_lowerright(sfVector2f bad, sfVector2f you)
{
    if ((bad.x + 130) > (you.x + 124) && (bad.x + 130) < (you.x + 240)) {
        if ((bad.y + 70) > (you.y + 115) && (bad.y + 70) < (you.y + 320))
            return (1);
    }
    return (0);
}

int test_collision_bat(sfVector2f bad, sfVector2f you)
{
    int x = 0;

    x = x + test_bat_upperleft(bad, you);
    x = x + test_bat_upperright(bad, you);
    x = x + test_bat_lowerleft(bad, you);
    x = x + test_bat_lowerright(bad, you);
    if (x > 0)
        return (1);
    return (0);
}
