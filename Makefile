NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = cc

SRCFILES = ft_printf.c

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJECTS = $(SRCFILES:.c=.o)

HEADER = libft.h libftprintf.h

all : $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME) : $(OBJECTS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS)
	@touch $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I./includes -I$(LIBFT_DIR) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f *.out

re: fclean all

.PHONY: all clean fclean re