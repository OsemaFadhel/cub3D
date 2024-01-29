# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 21:01:17 by ofadhel           #+#    #+#              #
#    Updated: 2024/01/29 15:55:06 by ofadhel          ###   ########.fr        #
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

MLX_PATH	= ./mlx-linux/

MLX_LINUX	= $(MLX_PATH)/libmlx_Linux.a

MLX			= $(MLX_PATH)/libmlx.a

# src

SRC 		= main.c key.c

SRC_DIR		= src

OBJ_DIR		= obj

OBJ			= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))


# compiler

CC = gcc

CFLAGS		=	-Wall -Wextra -Werror -g

# rules

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}


all:	 $(NAME)

$(NAME): $(OBJ)
		@echo "$(YELLOW)LIBFT...$(DEFAULT)"
		make -C $(LIBFT_PATH)
		@echo "$(YELLOW)COMPILING...$(DEFAULT)"
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -L $(MLX_PATH) -lm -lbsd -lX11 -lXext -o $(NAME)
		@echo "$(GREEN)READY TO GO!$(DEFAULT)"

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(OBJ_DIR)
		$(CC) -I/usr/includesude -Imlx_linux-c -c $< -o $@
		@echo "$(GREEN)OBJECTS READY!$(DEFAULT)"

clean:
		make fclean -C ${LIBFT_PATH}
		make clean -C ${MLX_PATH}
		rm -rf obj

fclean:	clean
		rm -rf ${NAME}

re:				fclean all

.PHONY: all clean fclean re
