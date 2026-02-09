NAME = push_swap

SRC = \
	main.c \
	src/input_checking.c \
	src/all_operations.c \
	src/radix_sort.c \
	src/tiny_sort.c \
	src/assign_index.c \
    src/utils.c

OFILES = $(SRC:.c=.o)

LIBFT_DIR = include/42-libft
PRINTF_DIR = include/ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

.c.o:
	cc -Wall -Werror -Wextra -c $< -o $(<:.c=.o)

$(NAME): $(OFILES) $(LIBFT) $(PRINTF)
	cc -Wall -Werror -Wextra $(OFILES) $(LIBFT) $(PRINTF) -o $(NAME)

all: $(NAME)

# -------- LIBFT --------
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# -------- FT_PRINTF --------
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
