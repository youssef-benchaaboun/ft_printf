NAME = libftprintf.a

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

SRC = ft_print_char.c ft_printf.c ft_print_hex.c \
      ft_print_number.c ft_print_pointer.c ft_print_string.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
