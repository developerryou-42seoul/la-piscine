NAME = rush-02

GCC = gcc -Wall -Wextra -Werror

SRC_DIR = ./srcs
INCLUDE_DIR = ./includes

SRCS = main.c number_handler.c dict_handler.c print_number.c
OBJS = $(SRCS:.c=.o)

OBJS_WITH_DIR = $(patsubst %.o, $(SRC_DIR)/%.o, $(OBJS))

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(GCC) -I$(INCLUDE_DIR) -c $< -o $@

$(NAME) : $(OBJS_WITH_DIR)
	$(GCC) -I$(INCLUDE_DIR) -o $(NAME) $(OBJS_WITH_DIR)

.PHONY: all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS_WITH_DIR)

fclean : clean
	rm -f $(NAME)

re : fclean all
