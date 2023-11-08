# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwisniew <bwisniew@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 17:41:39 by bwisniew          #+#    #+#              #
#    Updated: 2023/11/07 16:37:27 by bwisniew         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror -g3
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
INCLUDE=libft.h
NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ) 

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
