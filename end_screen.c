/*
** EPITECH PROJECT, 2019
** my_runner
** File description:
** end_screen
*/

#include "runner_includes.h"

void destroy_end(end_t *end)
{
    sfTexture_destroy(end->texture);
    sfSprite_destroy(end->sprite);
    sfText_destroy(end->text);
    sfText_destroy(end->text2);
    sfText_destroy(end->score);
    sfFont_destroy(end->font);
    free (end);
}

int draw_end(sfColor color, int a, end_t *end, sfRenderWindow *window)
{
    color = sfColor_fromRGBA(a, a, a, a);
    sfText_setFillColor(end->text, color);
    color = sfColor_fromRGBA(end->cc, end->cc, end->cc, end->cc);
    sfText_setFillColor(end->text2, color);
    sfText_setFillColor(end->score, color);
    sfSprite_setTexture(end->sprite, end->texture, 1);
    sfRenderWindow_drawSprite(window, end->sprite, NULL);
    sfRenderWindow_drawText(window, end->text, NULL);
    sfRenderWindow_drawText(window, end->text2, NULL);
    sfRenderWindow_drawText(window, end->score, NULL);
    sfRenderWindow_display(window);
    if (a != 255)
        a++;
    if (a >= 125 && end->cc != 255)
        end->cc++;
    return (a);
}

end_t *create_end(end_t *end, char *str)
{
    end->texture = sfTexture_createFromFile("media/Gameover.png", NULL);
    end->sprite = sfSprite_create();
    sfSprite_setTexture(end->sprite, end->texture, 1);
    end->text = sfText_create();
    end->text2 = sfText_create();
    end->score = sfText_create();
    end->font = sfFont_createFromFile("Pixeled.ttf");
    create_text(end->text, 760, 440, end->font);
    create_text(end->text2, 650, 640, end->font);
    create_text(end->score, 850, 750, end->font);
    sfText_setString(end->text, "Game Over");
    sfText_setString(end->text2, "Your Score was:");
    sfText_setString(end->score, str);
    end->cc = 0;
    return (end);
}

void display_end_screen(sfRenderWindow *window, char *str)
{
    end_t *end = malloc(sizeof(end_t));
    sfClock *clock = sfClock_create();
    sfTime time;
    float seconds;
    sfColor color;
    int a = 0;

    end = create_end(end, str);
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    while (seconds < 7) {
        time = sfClock_getElapsedTime(clock);
        seconds = time.microseconds / 1000000.0;
        a = draw_end(color, a, end, window);
    }
    sfClock_destroy(clock);
    destroy_end(end);
    sfRenderWindow_close(window);
}

void end_condition(sfRenderWindow *window, character_t *player, score_t *score)
{
    draw_lives(window, player->lives, player->hearts);
    if (player->lives == 0) {
        display_end_screen(window, score->str);
    }
}
