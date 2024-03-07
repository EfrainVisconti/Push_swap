# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/07 13:59:06 by eviscont          #+#    #+#              #
#    Updated: 2024/03/07 14:01:33 by eviscont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Comandos
CFLAGS = -Wall -Wextra -Werror

# Nombre ejecutable
NAME = push_swap

# Ficheros
SRCS = 
OBJS = $(SRCS:.c=.o)
HEADER = push_swap.h

LIBS = libft/libft.a

# Reglas
all: libs $(NAME)

# Compilar
libs:
	@make -C libft

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

# Eliminar temporales
clean:
	@make clean -C libft
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBS)

re: fclean all