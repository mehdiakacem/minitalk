# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makacem <makacem@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 18:44:09 by makacem           #+#    #+#              #
#    Updated: 2022/05/30 11:38:54 by makacem          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client

SERVER = server

NAME = client server

FLAGS = -Wall -Werror -Wextra

SRC = client.c server.c

OBJ = $(SRC:.c=.o)

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(OBJ)
	make -C ./libft
	gcc -o $(CLIENT) client.o libft/libft.a
	
$(SERVER) : $(OBJ)
	make -C ./printf
	gcc -o $(SERVER) server.o printf/libftprintf.a

%.o : %.c
	gcc $(FLAGS) -c $<

clean :
	@rm -f $(OBJ)
	@make clean -C ./libft
	@make clean -C ./printf
	
fclean : clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@make fclean -C ./printf
	
re : fclean all