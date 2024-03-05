# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 21:01:17 by ofadhel           #+#    #+#              #
#    Updated: 2024/03/03 22:50:04 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colours

RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

# name

NAME		= cub3d

# libft

LIBFT_PATH 	= ./libft

LIBFT 		= $(LIBFT_PATH)/libft.a

# mlx

#MLX_PATH	= ./mlx-linux

#MLX_LINUX	= $(MLX_PATH)/libmlx_Linux.a


# src

SRC 		=	main.c init/init.c init/init_pos.c \
				movement/key.c movement/line_algo.c \
				parser/read_map.c parser/read_file.c parser/checks.c parser/set_rgb.c \
				parser/image_convert.c \
				raycasting/raycasting.c raycasting/draw_window.c \
				exit.c \

OBJ			= $(SRC:.c=.o)


# compiler

CC = gcc

CFLAGS		=	-Wall -Wextra -Werror -g -lmlx -framework OpenGL -framework AppKit

# rules

%.o: %.c
		$(CC) -I/usr/includesude -Imlx_linux-c -c $< -o $@
		@echo "$(GREEN)OBJECTS READY!$(DEFAULT)"

all:	 $(NAME)

$(NAME): $(OBJ)
		@echo "$(YELLOW)LIBFT...$(DEFAULT)"
		make -C $(LIBFT_PATH)
		@echo "$(YELLOW)COMPILING...$(DEFAULT)"
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
		@echo "$(GREEN)READY TO GO!$(DEFAULT)"
		@echo "\033[0;31m___  ____       _        _   _      _ _\033[0m"
			@echo "\033[0;31m|  \/  (_)     (_)      | | | |    | | |\033[0m"
			@echo "\033[0;31m| .  . |_ _ __  _ ______| |_| | ___| | |\033[0m"
			@echo "\033[0;31m| |\/| | | '_ \| |______|  _  |/ _ \ | |\033[0m"
			@echo "\033[0;31m| |  | | | | | | |      | | | |  __/ | |\033[0m"
			@echo "\033[0;31m\_|  |_/_|_| |_|_|      \_| |_/\___|_|_|\033[0m"
			@echo "                                        "
			@echo "                                        "
			@echo "\033[0;32mLinked into executable \033[0m\033[0;32mcub3d\033[0m."
		


clean:
		rm -rf $(OBJ)
		make fclean -C $(LIBFT_PATH)

fclean:	clean
		rm -rf $(NAME)

re:				fclean all

.PHONY: all clean fclean re
