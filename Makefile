








##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make
##

NAME	=	my_world

SRC	=	sources/main.c	\
		sources/rotate_matrix.c	\
		sources/my_getnbr.c	\
		sources/window_init.c	\
		sources/launch_game.c	\
		sources/analyse_events.c	\
		sources/init_board.c	\
		sources/init_button.c	\
		sources/render.c	\
		sources/game_object.c	\
		sources/draw_map.c	\
		sources/init_map.c	\
		sources/update.c	\
		sources/transformation.c	\
		sources/default_gen.c	\
		sources/advance_events.c	\
		sources/my_strcmp.c	\
		sources/help.c	\
		sources/color_index.c

CPPFLAGS	=	-I./includes

LDFLAGS	=	-L./ -lmy -lcsfml-window -lcsfml-graphics

CSFMLFLAGS	=	-lcsfml-system -lcsfml-audio

CC	=	gcc -Wall -Wextra -lm

all: $(NAME)

.PHONY: clean my_clean fclean re all

$(NAME):
	make -C lib/my
	$(CC) -o $(NAME) $(SRC) $(CPPFLAGS) $(LDFLAGS) $(CSFMLFLAGS)

clean:
	make clean -C lib/my

my_clean:
	make my_clean -C lib/my
	rm -f *~
	rm -f includes/*~
	rm -f sources/*~
	rm -f sources/*#
	rm -f sources/*.#
	rm -f *#
	rm -f *.#

fclean: clean
	make fclean -C lib/my
	rm -f $(NAME)

re: fclean all
