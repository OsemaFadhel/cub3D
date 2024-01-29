# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/09 21:01:17 by ofadhel           #+#    #+#              #
#    Updated: 2024/01/29 12:08:20 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

LIBFT_PATH 	= ./libft

LIBFT 	= $(LIBFT_PATH)

SRC = main.c

OBJ		= 	$(SRC:.c=.o)

CC = gcc

CFLAGS = -Werror -Wall -Wextra

MLX				=	./libmlx.dylib

CFLAGS			=	-Wall -Wextra -Werror -g

%.o: %.c
	$(CC) -Imlx -c $< -o $@

all:			$(NAME)

$(NAME): $(OBJ)
	@echo "$(COLOUR_YELLOW)COMPILING...$(COLOUR_END)"
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT)/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(COLOUR_GREEN)READY TO GO!$(COLOUR_END)"

clean:
	make fclean -C ${LIBFT_PATH}
	rm -rf ${OBJ}

fclean:			clean

	rm -rf ${NAME}

re:				fclean all

.PHONY: all clean fclean re
