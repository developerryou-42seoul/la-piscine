NAME = ft_cat

GCC = gcc -Wall -Wextra -Werror

SRCS = main.c string.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(GCC) -c $< -o $@

$(NAME) : $(OBJS)
	$(GCC) -o $(NAME) $(OBJS)

.PHONY: all clean fclean re

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
