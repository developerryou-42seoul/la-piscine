NAME = ft_tail

GCC = gcc -Wall -Wextra -Werror

SRCS = main.c parser.c write_file.c string.c buffer_handler.c

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
