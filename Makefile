NAME	= bito
CC	= cc
CFLAGS	= -Wall -Wextra -Werror -pedantic -std=c99 -Iincludes/

SRCS	= $(wildcard srcs/*.c) bito.c
OBJS	= $(SRCS:.c=.o)


all: $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	make clean
	./$(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
