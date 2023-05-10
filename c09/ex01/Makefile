NAME = libft.a

GCC = gcc -Wall -Wextra -Werror

SRC_DIR = ./srcs
INCLUDE_DIR = ./includes

SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(SRCS:.c=.o)

OBJS_WITH_DIR = $(patsubst %.o, $(SRC_DIR)/%.o, $(OBJS))

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(GCC) -I$(INCLUDE_DIR) -c $< -o $@

$(NAME) : $(OBJS_WITH_DIR)
	ar -crs $(NAME) $(OBJS_WITH_DIR)

.PHONY: all clean fclean re

all : $(NAME)

clean : 
	rm -f $(OBJS_WITH_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
