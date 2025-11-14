NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar rcs

SRCDIR      := .
DEPDIR      := $(SRCDIR)/.deps
INCDIR      := includes

SRCFILES    := ft_printf.c do_operation.c operations.c
OBJS        := $(SRCFILES:.c=.o)
HEADER      := $(INCDIR)/ft_printf.h

DEPFLAGS = -MMD -MP -MF $(DEPDIR)/$*.d

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	@mkdir -p $(DEPDIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(SRCFILES:%.c=$(DEPDIR)/%.d)

clean:
	rm -rf $(DEPDIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *out

re: fclean all

debug: re
	$(CC) main.c $(NAME) -g3 -o debug.out
	./debug.out

.PHONY: all clean fclean re debug