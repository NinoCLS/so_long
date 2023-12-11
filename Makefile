NAME = so_long
CC = cc 
FLAG = -Wall -Wextra -Werror
LIBFT_PATH = ./libft/
LIBFT = libft.a
MLX_FILE = libmlx.a
MLX_PATH = ./minilbx-linux/
MLX_FLAG = -Lmlx -lmlx -L/usr/lib/x11 -lXext -lX11
LIBFT_LIB= $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MIX_LIB = $(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX = $(MLX_LIB) $(MLX_FLAG)
C_FILES = map.c \
		map_checker.c
SRCS_DIR = ./srcs/
INC_DIR = ./include/
SRC = $(addprefix $(SRC_DIR), $(C_FILES))
OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(FLAG) -c $< -o $@
              
lib: 
	@make -C $(LIBFT_PATH)

mlx:
	@(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

clean:
	@make clean -sC $(MLX_PATH)
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ)

fclean:
	@rm -rf $(NAME)
	@make flclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re
