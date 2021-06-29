# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatias <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 12:26:37 by tmatias           #+#    #+#              #
#    Updated: 2021/03/10 11:34:11 by tmatias          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a 
CC= gcc
CFLAGS= -Wall -Werror -Wextra
SRC = $(wildcard *.c)

OBJ= $(SRC:%.c=%.o)
AR= ar -rcs

all: $(NAME)

$(NAME):$(OBJ) libft.h
	$(AR) $(NAME) $(OBJ)

$(OBS): $(SRC)
	$(CC)  $(CFLAGS) -c $< -o $@  -I.

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
re: fclean all