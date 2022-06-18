# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 15:07:06 by makacem           #+#    #+#              #
#    Updated: 2022/01/06 15:50:38 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h

SRC = ft_printf.c ft_putnbrhexa.c ft_putnbrhexaup.c ft_putchar.c ft_putnbr.c \
	ft_putstr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o : %.c $(HEADER)
	gcc $(FLAGS) -c $<

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all