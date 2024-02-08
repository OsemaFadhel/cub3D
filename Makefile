# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 21:01:17 by ofadhel           #+#    #+#              #
#    Updated: 2024/02/08 16:43:07 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colours

RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

# name

NAME		= cub3D

# libft

LIBFT_PATH 	= ./libft

LIBFT 		= $(LIBFT_PATH)/libft.a

# mlx

#MLX_PATH	= ./mlx-linux

#MLX_LINUX	= $(MLX_PATH)/libmlx_Linux.a


# src

SRC 		= main.c movement/key.c parser/read_map.c

SRC_DIR		= src

OBJ			= $(SRC:.c=.o)


# compiler

CC = gcc

CFLAGS		=	-Wall -Wextra -Werror -g -lmlx -framework OpenGL -framework AppKit

# rules

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}


all:	 $(NAME)

$(NAME): $(OBJ)
		@echo "$(YELLOW)LIBFT...$(DEFAULT)"
		make -C $(LIBFT_PATH)
		@echo "$(YELLOW)COMPILING...$(DEFAULT)"
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
		@echo "$(GREEN)READY TO GO!$(DEFAULT)"

%.o: %.c
		$(CC) -I/usr/includesude -Imlx_linux-c -c $< -o $@
		@echo "$(GREEN)OBJECTS READY!$(DEFAULT)"

clean:
		rm -rf $(OBJ)
		make fclean -C $(LIBFT_PATH)

fclean:	clean
		rm -rf $(NAME)

re:				fclean all

.PHONY: all clean fclean re
