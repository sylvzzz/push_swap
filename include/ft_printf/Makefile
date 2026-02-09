NAME = libftprintf.a
SRC = \
    ft_putstr_fd.c \
	ft_putchar_fd.c \
	ft_puthex.c \
	ft_puthex_m.c \
	ft_putptr.c \
	ft_putnbr_u_fd.c \
	ft_printf.c \
	ft_strchr.c \
	ft_strlen.c \
    ft_putnbr_fd.c

OFILES = $(SRC:.c=.o) 

.c.o:
	cc -Wall -Werror -Wextra -c $< -o $(<:.c=.o)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

all: $(NAME)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME) 

re: fclean all


.PHONY: all clean fclean re