NAME = so_long
CC = cc 
FLAG = -Wall -Wextra -Werror
LIBFT_PATH = ./libft/
LIBFT = libft.a
GNL_PATH = ./gnl/
MLX_FILE = libmlx.a
MLX_PATH = ./minilibx-linux/
MLX_FLAG = -Lmlx -lmlx -lXext -lX11
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT))
MLX_LIB = $(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX = $(MLX_LIB) $(MLX_FLAG)
C_FILES = so_long.c map_checker.c
GNL_FILES = gnl_get_next_line.c gnl_get_next_line_utils.c
SRCS_DIR = ./srcs/
GNL_DIR = ./gnl/
INC_DIR = ./include/
SRC = $(addprefix $(SRCS_DIR), $(C_FILES))
GNL_SRC = $(addprefix $(GNL_DIR), $(GNL_FILES))
OBJ = $(patsubst %.c,%.o,$(SRC) $(GNL_SRC))

all: $(NAME)

$(NAME): lib mlx $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I$(INC_DIR) -c $< -o $@

lib:
	@make -C $(LIBFT_PATH)

mlx:
	@make -C $(MLX_PATH)

clean:
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(MLX_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@make fclean -C $(MLX_PATH)

re: fclean all

.PHONY: all clean fclean re
