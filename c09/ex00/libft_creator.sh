gcc -Wall -Wextra -Werror -c *.c
ar -crs libft.a *.o
find . -name "*.o" -delete
