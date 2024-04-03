CC				= cc
CFLAGS			= -Wall -Wextra  -Werror 
RM   			= rm -rf

NAME			= libftprintf.a
SOURCE_FILES 	= ft_printf.c conversion_check.c ft_putchar.c ft_putnbr.c ft_hexa.c
OBJECTS			= $(SOURCE_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -rcs $@ $^

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean
	make all

.PHONY: all clean re fclean