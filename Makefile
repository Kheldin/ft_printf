NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRCFILES = ft_printf.c do_operation.c operations.c

OBJECTS = $(SRCFILES:.c=.o)

HEADER = libftprintf.h

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
	@touch $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I./includes -c $< -o $@ fdhrtgfyhtg

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -f *.out

re: fclean all

debug: re
	cc main.c libftprintf.a -g3 ; ./a.out

.PHONY: all clean fclean re debug