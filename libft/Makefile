# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 16:41:04 by eviscont          #+#    #+#              #
#    Updated: 2024/02/02 16:49:08 by eviscont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CFLAGS		= -c -Wall -Wextra -Werror

SRCS		= ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_isalnum.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_split.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_printf/ft_print_char.c ft_printf/ft_print_number.c ft_printf/ft_print_pointer.c \
			ft_printf/ft_print_str.c ft_printf/ft_print_to_base.c ft_printf/ft_print_unsign.c \
			ft_printf/ft_printf.c \
			get_next_line/get_next_line.c \
			
HDRS = libft.h
OBJS		= $(patsubst %.c,%.o,$(notdir $(SRCS)))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(HDRS)
	gcc $(CFLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re