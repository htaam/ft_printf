LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS = $(wildcard *.c)


CC = gcc
AR = ar -rcs
FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
		@$(MAKE) -C ./libft -s
		@cp libft/libft.a $(NAME)
		@echo "Libft made"
		$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
		$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean :
		@$(MAKE) clean -C ./libft -s
		@echo "Libft clean: done"
		rm -rf $(OBJS)

fclean: clean
		@$(MAKE) fclean -C ./libft -s
		@echo "Libft fclean: done"
		rm -rf $(NAME)

re: fclean all