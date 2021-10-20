COMMAND = gcc -Wall -Wextra -Werror -c

INCLUDES = -I ft_printf.h -I libft/libft.h
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

LIBFT = ./libft

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	Make bonus --directory=$(LIBFT)
	cp libft/libft.a $(NAME)
	ar -crs $(NAME) $(OBJECTS) 

%.o: %.c $(INCLUDES)
	$(COMMAND) $< $(INCLUDES)

clean:
	make clean --directory=$(LIBFT)
	rm -rf $(OBJECTS)

fclean:
	make fclean --directory=$(LIBFT)
	rm -rf $(OBJECTS) $(NAME)

re:
	Make fclean
	Make all
