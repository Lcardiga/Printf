# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcardiga <lcardiga@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 18:08:49 by lcardiga          #+#    #+#              #
#    Updated: 2021/12/15 18:09:10 by lcardiga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRC =		ft_printf.c \
			ft_printf_utils_1.c \
			ft_printf_utils_2.c \

OBJ =		$(patsubst %.c,%.o,$(SRC))

D_FILES =	$(patsubst %.c,%.d,$(SRC))

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

all: 		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $?

%.o :		%.c
			$(CC) $(GFLAGS) -c $< -o $@ -MD

include		$(wildcard $(D_FILES))

clean:
			@rm -f $(OBJ) $(D_FILES)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY :	all clean fclean re