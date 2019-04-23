##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	main.c \
		manuel.c \
		my_create_window.c \
		game_object.c \
		create_destroy_manage.c \
		event_handling.c \
		select_screen.c \
		select_create_destroy_manage.c \
		pause_screen.c \
		end_screen.c \
		level_background.c \
		enemies.c \
		enemy_list_handling.c \
		debuff.c \
		player.c \
		score.c \
		clock.c \
		highscore.c \
		damage.c \
		damage_shroom.c \
		damage_bat.c \
		dash.c \
		player_jump.c \
		lives.c \
		map_loading.c \
		my_strcpy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) -Wall -Wextra -Werror $(OBJ) -l csfml-graphics -l csfml-system -l csfml-audio
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
