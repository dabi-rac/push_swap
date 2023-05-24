# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dabi-rac <dabi-rac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/24 21:59:13 by dabi-rac          #+#    #+#              #
#    Updated: 2023/05/24 21:59:15 by dabi-rac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = utils.c main.c moves.c quicksort.c sort.c \

OBJ = $(SRC:.c=.o)

CC = gcc
FLAG = -Wall -Werror -Wextra -g

all :
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all clean