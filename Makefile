# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 13:20:28 by smakni            #+#    #+#              #
#    Updated: 2018/11/23 15:59:57 by smakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME_C	=	checker

CC		=	gcc

CFLAGS	+=	-Wall -Werror -Wextra $(HEAD)

SRC		=	./src/ft_push.c \
			./src/init_free.c \
			./src/check_init.c \
			./src/print_pile.c \
			./src/ft_check.c

SRC_P	=	./src_p/push_swap.c \
			./src_p/operations_p.c \
			./src_p/operations_ret.c

SRC_C	=	./src_c/checker.c \
			./src_c/operations_c.c

HEAD	=	-I ./include

LIB		=	make -C ./libft

OBJ		=	$(SRC:.c=.o)

OBJ_P	=	$(SRC_P:.c=.o)

OBJ_C	=	$(SRC_C:.c=.o)

RM		=	rm -rf

all: $(NAME)

$(NAME): $(OBJ_C) $(OBJ_P) $(OBJ)
		$(LIB)
		$(CC) -o $(NAME) $(OBJ) $(OBJ_P) ./libft/libftprintf.a
		$(CC) -o $(NAME_C) $(OBJ) $(OBJ_C) ./libft/libftprintf.a

clean:
		make clean -C libft
		$(RM) $(OBJ) $(OBJ_P) $(OBJ_C)

fclean: clean
		make fclean -C libft
		$(RM) $(NAME) $(NAME_C)

re:	fclean all

.PHONY: all clean fclean

