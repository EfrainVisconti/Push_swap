# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 13:59:06 by eviscont          #+#    #+#              #
#    Updated: 2024/05/09 20:32:57 by eviscont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comandos
# -g para debugear con lldb
CFLAGS = -Wall -Wextra -Werror -g

# Nombre ejecutable
NAME = push_swap
NAME_BONUS = checker

# Ficheros
SRCS1 = main.c
SRCS2 = lst_utils.c check_args.c utils.c swap.c push.c rotate.c reverse_rotate.c algo_utils.c algo_utils2.c algo_utils3.c algorithm.c
OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
HEADER = push_swap.h

# Ficheros Bonus
SRCS_BONUS = checker.c checker2.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
HEADER_BONUS = push_swap.h

LIBS = libft/libft.a

# Reglas
all: libs $(NAME)

bonus: libs $(NAME_BONUS)

# Compilar
libs:
	@make -C libft

$(NAME): $(OBJS1) $(OBJS2)
	gcc $(CFLAGS) $(OBJS1) $(OBJS2) $(LIBS) -o $(NAME)

$(NAME_BONUS): $(OBJS2) $(OBJS_BONUS)
	gcc $(CFLAGS) $(OBJS_BONUS) $(OBJS2) $(LIBS) -o $(NAME_BONUS)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

# Eliminar temporales
clean:
	@make clean -C libft
	rm -f $(OBJS1) $(OBJS2) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(LIBS)

re: fclean all