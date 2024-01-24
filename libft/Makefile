NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isalnum.c ft_isprint.c  ft_putchar_fd.c ft_split.c ft_strncmp.c \
		ft_atoi.c ft_isalpha.c ft_itoa.c ft_memcpy.c  ft_putendl_fd.c \
		ft_strchr.c  ft_strlcpy.c ft_strnstr.c ft_tolower.c ft_bzero.c \
		ft_isascii.c ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c \
		ft_strrchr.c ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memset.c  \
		ft_putstr_fd.c  ft_strjoin.c ft_print_hex.c ft_print_ptr.c \
		ft_print_unsigned_nb.c ft_printf_helpers.c ft_printf.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

AR = ar rc

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all