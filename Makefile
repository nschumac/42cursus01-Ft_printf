NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c

LIBFT = ./42cursus00-Libft

SOURCES =	sources/disect.c			\
			sources/ft_printf.c			\
			sources/padding.c			\
			sources/specifier_c.c		\
			sources/specifier_di.c		\
			sources/specifier_p.c		\
			sources/specifier_s.c		\
			sources/specifier_s.c		\
			sources/specifier_xX.c		\
			sources/utilities.c			\

OBJECTS = $(SOURCES:.c=.o)

%.o: %.c
	@$(CC) $(CCFLAGS) -o $@ -c $<

all: $(NAME)

$(NAME): $(OBJECTS)
	@Make bonus --directory=$(LIBFT)
	@cp libft/libft.a $(NAME)
	@ar -crs $(NAME) $(OBJECTS)
	@echo libftprintf Compiled!

clean:
	@make clean --directory=$(LIBFT)
	@rm -rf $(OBJECTS)

fclean: clean
	@make fclean --directory=$(LIBFT)
	@rm -rf $(NAME)

re: fclean all
