# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofadhel <ofadhel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 14:53:32 by ofadhel           #+#    #+#              #
#    Updated: 2024/02/08 15:28:16 by ofadhel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# colours

RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

DEFAULT = \033[0m

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c \
					ft_printf.c ft_putchars.c ft_puthex.c ft_putnbrs.c \
					ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c \
					get_next_line.c get_next_line_utils.c

OBJ_DIR			= obj

OBJS			= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC				= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -I.

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
				@echo "$(GREEN)LIBFT READY!$(DEFAULT)"

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(OBJ_DIR)
		$(CC) -c $< -o $@

clean:
				$(RM) -rf $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
