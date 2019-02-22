# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llenotre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 17:11:46 by llenotre          #+#    #+#              #
#    Updated: 2019/02/14 14:03:27 by llenotre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
DIRS := $(shell find src/ -type d)
SRC =	src/draw.c\
		src/event.c\
		src/file.c\
		src/main.c\
		src/projection.c\
		src/wireframe.c
HDR =	src/fdf.h

OBJ_DIR = obj/
OBJ_DIRS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(DIRS))
OBJ := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

LIBFT = libft/libft.a
MINILIBX = minilibx_linux/libmlx.a

LINKS = -lGL -lX11 -lXext -lm # -lmlx -framework OpenGL -framework AppKit

all: $(NAME) tags

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIRS) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX) $(LINKS)

$(LIBFT):
	make -C libft/

$(MINILIBX):
	make -C minilibx_linux/

$(OBJ_DIRS):
	mkdir -p $(OBJ_DIRS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HDR)
	$(CC) $(CFLAGS) -o $@ -c $<

tags: $(SRC) $(HDR)
	ctags $(SRC) libft/*

count:
	find $(SRC_DIR) -type f -name "*.[ch]" | xargs wc -l

clean:
	rm -rf $(OBJ_DIR)
	make clean -C libft/
	make clean -C minilibx_linux/

fclean: clean
	rm -f $(NAME)
	rm -f tags
	make fclean -C libft/
	make clean -C minilibx_linux/

re: fclean all
	make re -C minilibx_linux/

.PHONY: all clean fclean re
