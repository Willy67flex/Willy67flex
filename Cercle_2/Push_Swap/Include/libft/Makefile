

NAME=libft.a

CC=cc

CFLAGS=-Wall -Wextra -Werror

SRCS=./ft_atoi.c ./ft_bzero.c ./ft_calloc.c ./ft_isalnum.c ./ft_isalpha.c ./ft_isascii.c ./ft_isdigit.c ./ft_isprint.c ./ft_itoa.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c ./ft_memset.c ./ft_putchar_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./ft_putstr_fd.c ./ft_split.c ./ft_strchr.c ./ft_strdup.c ./ft_striteri.c ./ft_strjoin.c ./ft_strlcat.c ./ft_strlcpy.c ./ft_strlen.c ./ft_strmapi.c ./ft_strncmp.c ./ft_strnstr.c ./ft_strrchr.c ./ft_strtrim.c ./ft_substr.c ./ft_tolower.c ./ft_toupper.c ./ft_intsize.c ft_printf.c ft_print_str_count.c ft_puthex_ptr.c ft_putnbr_base.c ft_put_unsigned_nbr_fd.c ft_unsigned_intsize.c ft_write_count.c get_next_line_bonus.c \
get_next_line_utils_bonus.c

SRCS_BONUS= ./ft_lstadd_back.c ./ft_lstadd_front.c ./ft_lstclear.c ./ft_lstdelone.c ./ft_lstiter.c ./ft_lstnew.c ./ft_lstsize.c ./ft_lstlast.c ./ft_lstmap.c

OBJS= ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

INCLUDE= .

all: $(NAME)

$(NAME): $(OBJS)
	ar r -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

bonus: $(OBJS_BONUS)
	ar r -o $(NAME) $(OBJS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
