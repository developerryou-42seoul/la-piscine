# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jayang <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 13:49:26 by jayang            #+#    #+#              #
#    Updated: 2022/02/22 08:51:02 by sryou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = bsq
SRCS = srcs/main.c srcs/stdinput_handler.c srcs/file_handler.c srcs/valid_handler.c srcs/global_handler.c srcs/map_handler.c srcs/string.c srcs/stack.c srcs/algorithm.c
OBJS = ${SRCS:.c=.o}
HEADER = ./includes

%.o : %.c
	${CC} ${CFLAGS} -I${HEADER} -c $< -o $@

${NAME} : ${OBJS}
	${CC} ${CHLAGS} $^ -o $@

.PHONY: all clean fclean re

all : ${NAME}

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all
