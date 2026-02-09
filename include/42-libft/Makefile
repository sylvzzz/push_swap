NAME = libft.a
SRC = \
    ft_atoi.c \
    ft_isalnum.c \
    ft_isascii.c \
    ft_isprint.c \
    ft_memmove.c \
    ft_strchr.c \
    ft_strlcpy.c \
    ft_strrchr.c \
    ft_toupper.c \
    ft_bzero.c \
    ft_isalpha.c \
    ft_isdigit.c \
    ft_memcpy.c \
    ft_memcmp.c \
    ft_memset.c \
    ft_strlcat.c \
    ft_strlen.c \
    ft_memchr.c \
    ft_strncmp.c \
    ft_calloc.c \
    ft_strnstr.c \
    ft_strdup.c \
    ft_substr.c \
    ft_strjoin.c \
    ft_strmapi.c \
    ft_strtrim.c \
    ft_striteri.c \
    ft_split.c \
    ft_itoa.c \
    ft_tolower.c
BSRC = \
    ft_lstnew_bonus.c \
    ft_lstadd_front_bonus.c \
    ft_lstadd_back_bonus.c \
    ft_lstsize_bonus.c \
    ft_lstlast_bonus.c \
    ft_lstdelone_bonus.c \
    ft_lstclear_bonus.c \
    ft_lstiter_bonus.c \
    ft_lstmap_bonus.c

OFILES = $(SRC:.c=.o) 
OBONUS = $(BSRC:.c=.o)

.c.o:
	cc -Wall -Werror -Wextra -c $< -o $(<:.c=.o)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

all: $(NAME)

bonus: $(OFILES) $(OBONUS)
	ar rcs $(NAME) $(OFILES) $(OBONUS)
	@touch bonus

clean:
	rm -f $(OFILES) $(OBONUS)
	@touch bonus
	@rm bonus

fclean: clean
	rm -f $(NAME) 

re: fclean all


.PHONY: all clean fclean re