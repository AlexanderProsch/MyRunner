/*
** EPITECH PROJECT, 2018
** function
** File description:
** proto
*/

#include "../runner_includes.h"

int test_for_instructions(int argc, char **argv);
sfRenderWindow *create_my_window(int width, int height);

void control(sfEvent *e, score_t *s, character_t *p, sfRenderWindow *w);
void manage(c_t *c, character_t *p, background_t *b, sfRenderWindow *w);
void create(c_t *c, score_t *s, background_t *b, character_t *p);
void destroy(c_t *c, score_t *s, background_t *b, character_t *p);

void analyse_events(sfRenderWindow *w, sfEvent *e, character_t *player);

gameobject_t *create_object(char const *p, sfVector2f pos, sfIntRect r, int sp);
void destroy_object(gameobject_t *ob);

void move_rect(sfIntRect *rect, int offset, int max_value);
void set_rectangle(sfIntRect *rectangle, int width, int height);

void destroy_level_background(background_t *bg);
void create_level_background(background_t *bg);
void manage_background(background_t *bg, sfRenderWindow *w, sfClock *clock);

enemy_t *loadnewenemy(sfRenderWindow *window, enemy_t *list, c_t *c);
enemy_t *create_enemy(void);
enemy_t *add_to_last(enemy_t *first, enemy_t *second);
enemy_t *delete_enemy(enemy_t *enemy);
int create_condition(sfClock *clock);

void destroy_character(character_t *character);
void change_character(gameobject_t *x, sfRenderWindow *w);
void manage_player(character_t *character, sfRenderWindow *w, c_t *c);
void create_player(character_t *player);

void manage_score(score_t *score, sfRenderWindow *window);
void create_score(score_t *score);
void create_text(sfText *text, int x, int y, sfFont *font);
void destroy_score(score_t *score);

int manage_selectscreen(sfRenderWindow *w, sfEvent *eve);
void pause_screen(sfRenderWindow *window);
void end_condition(sfRenderWindow *window, character_t *player, score_t *score);
int analyse_selection(sfKeyEvent key, sfRenderWindow *window, select_t *select);

enemy_t *check_damage(character_t *player, enemy_t *enemy, sfClock *clock);

void dash(character_t *player, sfRenderWindow *w, sfClock *clock);
void create_dash(character_t *player);
void bring_character_down(character_t *player, int type);
void manage_jump(sfRenderWindow *w, character_t *character, c_t *c);

void draw_lives(sfRenderWindow *window, int lives, gameobject_t *heart);

void create_highscore(score_t *score);
void overwrite_highscore(char *str);

int test_map(char *map);
void create_map(map_t *map, char *str);
enemy_t *load_map(enemy_t *list, map_t *map);
char *my_strcpy(char *dest, char const *src);

void destroy_clock(c_t *clocks);
void create_clock(c_t *clocks);

void check_for_debuff(sfRenderWindow *w, character_t *player, c_t *c);
int test_collision_bat(sfVector2f bad, sfVector2f you);
int test_collision_shroom(sfVector2f bad, sfVector2f you);
