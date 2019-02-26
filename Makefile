# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llenotre <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/13 17:11:46 by llenotre          #+#    #+#              #
#    Updated: 2019/02/26 16:52:29 by llenotre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src/
DIRS := $(shell find src/ -type d)
SRC =	src/bresenham.c\
		src/bresenham1.c\
		src/bresenham2.c\
		src/bresenham3.c\
		src/bresenham4.c\
		src/draw.c\
		src/event.c\
		src/file.c\
		src/main.c\
		src/projection.c\
		src/wireframe.c
HDR =	src/fdf.h

OBJ_DIR = obj/
OBJ_DIRS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(DIRS))
OBJ := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

OS := $(shell uname)

ifeq ($(OS), Linux)
MINILIBX_DIR = minilibx_linux/
else
MINILIBX_DIR = minilibx_macos/
endif

LIBFT = libft/libft.a
MINILIBX = $(MINILIBX_DIR)/libmlx.a

ifeq ($(OS), Linux)
LINKS = -lGL -lX11 -lXext -lm
else
LINKS = -lmlx -framework OpenGL -framework AppKit
endif

all: $(NAME) tags

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ_DIRS) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MINILIBX) $(LINKS)

$(LIBFT):
	make -C libft/

$(MINILIBX):
	make -C $(MINILIBX_DIR)

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
	make clean -C $(MINILIBX_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f tags
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re
