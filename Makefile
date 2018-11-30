# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smakni <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/23 13:20:28 by smakni            #+#    #+#              #
#    Updated: 2018/11/30 17:03:54 by smakni           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_C		=	checker

CC			=	gcc

CFLAGS		+=	-Wall -Werror -Wextra

CPPFLAGS	=	-I include
				
SRC_PATH	=	src

SRC_P_PATH	=	src_p

SRC_C_PATH	=	src_c

OBJ_PATH	=	obj

OBJ_P_PATH	=	obj_p

OBJ_C_PATH	=	obj_c

LDFLAGS		=	-L libft

LDLIBS		=	-lft

SRC_NAME	=	init_free.c \
				check_init.c \
				print_pile.c \
				ft_check.c \
				operations.c \
				check_op.c \
				frames.c \
				ft_atoi_p.c

SRC_P_NAME	=	push_swap.c 

SRC_C_NAME	=	checker.c 

OBJ_NAME	=	$(SRC_NAME:.c=.o)

OBJ_P_NAME	=	$(SRC_P_NAME:.c=.o)

OBJ_C_NAME	=	$(SRC_C_NAME:.c=.o)

SRC 		= 	$(addprefix $(SRC_PATH)/,$(SRC_NAME))

SRC_P 		= 	$(addprefix $(SRC_P_PATH)/,$(SRC_P_NAME))

SRC_C 		= 	$(addprefix $(SRC_C_PATH)/,$(SRC_C_NAME))

OBJ 		= 	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_P 		= 	$(addprefix $(OBJ_P_PATH)/,$(OBJ_P_NAME))

OBJ_C 		= 	$(addprefix $(OBJ_C_PATH)/,$(OBJ_C_NAME))

all: $(NAME)

$(NAME): LIB $(OBJ) $(OBJ_C) $(OBJ_P) 
		$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) $(OBJ_P) -o $@
		$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) $(OBJ_C) -o $(NAME_C)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_P_PATH)/%.o: $(SRC_P_PATH)/%.c
	@mkdir $(OBJ_P_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(OBJ_C_PATH)/%.o: $(SRC_C_PATH)/%.c
	@mkdir $(OBJ_C_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

LIB:
	make -C libft

clean:
	rm -fv $(OBJ) $(OBJ_P) $(OBJ_C)
	rmdir $(OBJ_PATH) 2> /dev/null || true
	rmdir $(OBJ_P_PATH) 2> /dev/null || true
	rmdir $(OBJ_C_PATH) 2> /dev/null || true	
	make clean -C libft

fclean: clean
	rm -fv $(NAME) $(NAME_C)
	make fclean -C libft

re:	fclean all

.PHONY: all, clean, fclean, re

norme:
	norminette $(SRC)
	norminette $(SRC_P)
	norminette $(SRC_C)
	norminette ./include
