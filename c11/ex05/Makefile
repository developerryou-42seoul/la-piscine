NAME = do-op

GCC = gcc -Wall -Wextra -Werror

SRCS = main.c calculator.c string.c ft_atoi.c ft_putnbr.c ft_cal.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(GCC) -c $< -o $@

$(NAME) : $(OBJS)
	$(GCC) -o $(NAME) $(OBJS)

.PHONY: all clean fclean re test

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

test : re
	./$(NAME)
	./$(NAME) 42amis - --+-20toto12
	./$(NAME) 1 p 1
	./$(NAME) 1 + toto3
	./$(NAME) toto3 + 4
	./$(NAME) foo plus bar
	./$(NAME) 25 / 0
	./$(NAME) 25 "%" 0
	./$(NAME) 12 + 33
	./$(NAME) 12 "*" 5
	./$(NAME) 90 "/" 5
	./$(NAME) 44 "%" 5
	
