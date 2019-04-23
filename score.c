/*
** EPITECH PROJECT, 2018
** score
** File description:
** score
*/

#include "runner_includes.h"

void destroy_score(score_t *score)
{
    overwrite_highscore(score->str);
    free (score->str);
    free (score->highscore);
    sfText_destroy(score->hightext);
    sfText_destroy(score->text);
    sfClock_destroy(score->clock);
    sfFont_destroy(score->font);
    free (score);
}

void create_score(score_t *score)
{
    score->str = malloc(sizeof(char) * 7);
    score->str[0] = '0';
    score->str[1] = '0';
    score->str[2] = '0';
    score->str[3] = '0';
    score->str[4] = '0';
    score->str[5] = '0';
    score->str[6] = '\0';
    score->clock = sfClock_create();
    score->score = 0;
    score->meterpersec = 1;
    score->distance = 0;
    score->text = sfText_create();
    score->font = sfFont_createFromFile("Pixeled.ttf");
    sfText_setString(score->text, score->str);
    create_text(score->text, 1620, 30, score->font);
    create_highscore(score);
}

void change_score_text(score_t *score)
{
    int amount = score->score;
    int divide = 100000;
    int nb = 0;
    int x = 0;

    while (x != 6) {
        nb = amount / divide;
        amount = amount % divide;
        score->str[x] = (nb + '0');
        divide = divide / 10;
        x++;
    }
}

void manage_score_core(score_t *score, sfRenderWindow *window)
{
    if (score->score >= 999999)
        return;
    score->score = score->score + score->meterpersec;
    score->distance = score->distance + 1;
    if (score->distance == 500) {
        score->distance = 0;
        score->meterpersec = score->meterpersec + 1;
    }
}

void manage_score(score_t *score, sfRenderWindow *window)
{
    sfTime time = sfClock_getElapsedTime(score->clock);
    float seconds = time.microseconds / 1000000.0;

    sfRenderWindow_drawText(window, score->text, NULL);
    sfRenderWindow_drawText(window, score->hightext, NULL);
    if (seconds > 0.15) {
        manage_score_core(score, window);
        change_score_text(score);
        sfText_setString(score->text, score->str);
        sfClock_restart(score->clock);
    }
}
