NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar rcs

SRCDIR      := .
DEPDIR      := $(OBJDIR)/.deps
INCDIR      := includes

SRCFILES    := ft_printf.c do_operation.c operations.c
OBJS        := $(SRCFILES:.c=.o)
HEADER      := $(INCDIR)/libftprintf.h

# Dependency flags
DEPFLAGS    = $@ -MMD -MP $(DEPDIR)/$*.d

-include $(SRC:.c=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(DEPDIR):
	mkdir -p $(DEPDIR)

truc: 
	@echo $(OBJS)

clean:
	rm -rf $(OBJDIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f *out

re: fclean all

debug: re
	$(CC) main.c $(NAME) -g3 -o debug.out
	./debug.out

.PHONY: all clean fclean re debug truc