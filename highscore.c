/*
** EPITECH PROJECT, 2019
** runner
** File description:
** highscore
*/

#include "runner_includes.h"

int test_for_highscore(char *old, char *str)
{
    int x = 0;

    while (str[x] != '\0') {
        if (str[x] == old[x])
            x++;
        if (str[x] > old[x])
            return (1);
        if (str[x] < old[x])
            return (0);
    }
}

void overwrite_highscore(char *str)
{
    int fd = 0;
    char *old = malloc(sizeof(char) * 7);
    int test = 0;

    fd = open("highscore.txt", O_RDONLY);
    read(fd, old, 6);
    old[6] = '\0';
    test = test_for_highscore(old, str);
    if (test == 1) {
        fd = open("highscore.txt", O_WRONLY);
        write(fd, str, 6);
    }
}

void create_highscore(score_t *score)
{
    int fd = 0;

    score->highscore = malloc(sizeof(char) * 7);
    fd = open("highscore.txt", O_RDONLY);
    read(fd, score->highscore, 6);
    score->highscore[6] = '\0';
    score->hightext = sfText_create();
    sfText_setString(score->hightext, score->highscore);
    create_text(score->hightext, 1720, 100, score->font);
    sfText_setCharacterSize(score->hightext, 33);
}
