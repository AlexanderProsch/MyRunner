/*
** EPITECH PROJECT, 2019
** runner
** File description:
** enemies
*/

#include "runner_includes.h"

enemy_t *create_bat(void)
{
    sfVector2f position;
    sfVector2f speed;
    sfIntRect rect;
    enemy_t *enemy = malloc(sizeof(enemy_t));

    position.x = 1900;
    position.y = rand() % 800;
    speed.x = -8;
    speed.y = 0;
    set_rectangle(&rect, 130, 100);
    enemy->type = 1;
    enemy->visuals = create_object("media/bat_sprites.png", position, rect, 130);
    enemy->movement = speed;
    enemy->next = 0;
    return (enemy);
}

enemy_t *create_enemy(void)
{
    sfVector2f position;
    sfVector2f speed;
    sfIntRect rect;
    enemy_t *enemy = malloc(sizeof(enemy_t));

    position.x = 1900;
    position.y = 840;
    speed.x = -8;
    speed.y = 0;
    set_rectangle(&rect, 81, 120);
    enemy->type = 2;
    enemy->visuals = create_object("media/mushroom_sprites.png", position, rect, 80);
    enemy->movement = speed;
    enemy->next = 0;
    return (enemy);
}

enemy_t *animate_enemies(enemy_t *enemy)
{
    enemy_t *tmp = enemy;

    while (tmp != 0) {
        if (tmp->type == 1)
            move_rect(&tmp->visuals->rect, tmp->visuals->speed, 650);
        if (tmp->type == 2 || tmp->type == 3)
            move_rect(&tmp->visuals->rect, tmp->visuals->speed, 860);
        tmp = tmp->next;
    }
    return (enemy);
}

enemy_t *move_enemy(enemy_t *enemy, sfRenderWindow *window)
{
    enemy_t *tmp = enemy;

    while (tmp != 0) {
        sfSprite_setTexture(tmp->visuals->sprite, tmp->visuals->texture, 1);
        sfSprite_setTextureRect(tmp->visuals->sprite, tmp->visuals->rect);
        sfRenderWindow_drawSprite(window, tmp->visuals->sprite, NULL);
        sfSprite_move(tmp->visuals->sprite, tmp->movement);
        tmp = tmp->next;
    }
    return (enemy);
}

enemy_t *loadnewenemy(sfRenderWindow *window, enemy_t *list, c_t *c)
{
    enemy_t *new;
    int condition = create_condition(c->spawn);
    int type = rand() % 2;
    sfTime time = sfClock_getElapsedTime(c->enemyclock);
    float seconds = time.microseconds / 1000000.0;

    if (condition == 1) {
        if (type == 0)
            new = create_enemy();
        if (type == 1)
            new = create_bat();
        list = add_to_last(list, new);
    }
    list = move_enemy(list, window);
    if (seconds > 0.25) {
        list = animate_enemies(list);
        sfClock_restart(c->enemyclock);
    }
    list = delete_enemy(list);
    return (list);
}
