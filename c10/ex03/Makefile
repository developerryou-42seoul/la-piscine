NAME = ft_hexdump

GCC = gcc -Wall -Wextra -Werror

SRCS = main.c parser.c string1.c string2.c buffer_handler.c hex_handler.c

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
