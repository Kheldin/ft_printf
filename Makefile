NAME        := libftprintf.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar rcs

# Directories
SRCDIR      := .
OBJDIR      := obj
DEPDIR      := $(OBJDIR)/.deps
INCDIR      := includes

# Source files
SRCFILES    := ft_printf.c do_operation.c operations.c
OBJS        := $(addprefix $(OBJDIR)/, $(SRCFILES:.c=.o))
DEPS        := $(addprefix $(DEPDIR)/, $(SRCFILES:.c=.d))
HEADER      := $(INCDIR)/libftprintf.h

# Dependency flags
DEPFLAGS    = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "✅  Archive created: $(NAME)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER) | $(OBJDIR) $(DEPDIR)
	@$(CC) $(CFLAGS) $(DEPFLAGS) -I$(INCDIR) -c $< -o $@
	@echo "🔧  Compiled: $<"

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(DEPDIR):
	@mkdir -p $(DEPDIR)

clean:
	@rm -rf $(OBJDIR)
	@echo "🧹  Cleaned object and dependency files"

fclean: clean
	@rm -f $(NAME)
	@rm -f *.out
	@echo "🧹  Cleaned executables"

re: fclean all

debug: re
	@$(CC) main.c $(NAME) -g3 -o debug.out
	@./debug.out

.PHONY: all clean fclean re debug

-include $(DEPS)