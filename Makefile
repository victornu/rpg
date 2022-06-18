##
## EPITECH PROJECT, 2021
## B-CPE-100-LIL-1-1-myrunner-victor.braun
## File description:
## Makefile
##

SRC =	src/main.c	\
		src/initialize.c \
		src/events.c \
		src/draw.c \
		src/menu.c \
		src/break_menu.c \
		src/how_to_play.c \
		src/movement_particuls.c \
		src/movement_charactere.c \
		src/initialize_charactere.c \
		src/initialize_particuls.c \
		src/initialize_map.c \

OBJ	=	$(SRC:.c=.o)

NAME = my_rpg

LDFLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -g

all: $(NAME)

$(NAME):	$(OBJ)
		make -C lib/my -s
		gcc -o $(NAME) $(SRC) -I./include -L./lib/my -lmy $(LDFLAGS)

clean:
		make clean -C lib/my
		rm -f $(OBJ)
fclean:	clean
		rm -f $(NAME)
		make fclean -C lib/my -s

re: fclean all
