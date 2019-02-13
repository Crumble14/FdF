# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llenotre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 17:11:46 by llenotre          #+#    #+#              #
#    Updated: 2019/02/13 18:50:13 by llenotre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
DIRS := $(shell find src/ -type d)
SRC =	src/draw.c\
		src/main.c\
		src/window.c\
		src/wireframe.c
HDR =	src/fdf.h

OBJ_DIR = obj/
OBJ_DIRS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(DIRS))
OBJ := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

LIBFT = libft/libft.a
MINILIBX = minilibx/libmlx.a

all: $(NAME) tags

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIRS) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX)

$(LIBFT):
	make -C libft/

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

fclean: clean
	rm -f $(NAME)
	rm -f tags
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
