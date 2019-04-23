/*
** EPITECH PROJECT, 2019
** runner
** File description:
** load_map
*/

#include "runner_includes.h"

enemy_t *create_rock(void)
{
    sfVector2f position;
    sfVector2f speed;
    sfIntRect rect;
    enemy_t *enemy = malloc(sizeof(enemy_t));

    position.x = 1900;
    position.y = 780;
    speed.x = -8;
    speed.y = 0;
    set_rectangle(&rect, 224, 224);
    enemy->type = 4;
    enemy->visuals = create_object("media/Rock.png", position, rect, 0);
    enemy->movement = speed;
    enemy->next = 0;
    return (enemy);
}

enemy_t *create_toxic(void)
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
    enemy->type = 3;
    enemy->visuals = create_object("media/toxic.png", position, rect, 80);
    enemy->movement = speed;
    enemy->next = 0;
    return (enemy);
}

void create_map(map_t *map, char *str)
{
    char *stuff = malloc(sizeof(char) * 51);
    size_t bufsize = 32;
    size_t characters;
    FILE *fp = fopen(str, "r");

    map->x = 0;
    characters = getline(&stuff, &bufsize, fp);
    map->str = malloc(sizeof(char) * 51);
    map->str = my_strcpy(map->str, stuff);
    map->clock = sfClock_create();
    fclose(fp);
}

enemy_t *load_map(enemy_t *list, map_t *map)
{
    enemy_t *new;
    sfTime time = sfClock_getElapsedTime(map->clock);
    float seconds = time.microseconds / 1000000.0;
    if (map->str[map->x] == '\n' || map->str[map->x] == '\0')
        map->x = 0;
    if (seconds > 1 && map->str[map->x] != '\n') {
        if (map->str[map->x] == 'R')
            new = create_rock();
        if (map->str[map->x] == 'T')
            new = create_toxic();
        if (map->str[map->x] == 'R' || map->str[map->x] == 'T')
            list = add_to_last(list, new);
        map->x = map->x + 1;
        sfClock_restart(map->clock);
    }
    return (list);
}

int test_map(char *map)
{
    int x = 0;
    char *str = malloc(sizeof(char) * 51);
    size_t bufsize = 32;
    size_t characters;
    FILE *fp = fopen(map, "r");

    if (fp == NULL)
        return (2);
    characters = getline(&str, &bufsize, fp);
    while (str[x] != '\n') {
        if (str[x] != '.' && str[x] != 'R' && str[x] != 'T' && str[x] != '\n')
            return (2);
        if (x == 50)
            return (2);
        x++;
    }
    fclose(fp);
    return (0);
}
