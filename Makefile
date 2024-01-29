NAME = so_long
CC = cc 
FLAG = -Wall -Wextra -Werror
LIBFT_PATH = ./libft/
LIBFT = libft.a
MLX_FILE = minilibx-linux/libmlx.a
# MLX_PATH = ./minilibx-linux/
MLX_FLAG = -Lmlx -lXext -lX11
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT))
# MLX_LIB = $(addprefix $(MLX_PATH), $(MLX_FILE))
# MLX_EX = $(MLX_LIB) $(MLX_FLAG)
C_FILES = so_long.c ./map/map_checker.c ./map/init.c errors.c ./map/read_and_malloc_map.c \
			./map/check_path.c ./displaying/display_image.c ./displaying/init_image.c
GNL_FILES = get_next_line.c get_next_line_utils.c
SRCS_DIR = ./srcs/
GNL_DIR = ./gnl/
INC_DIR = ./include/
SRC = $(addprefix $(SRCS_DIR), $(C_FILES))
GNL_SRC = $(addprefix $(GNL_DIR), $(GNL_FILES))
OBJ = $(patsubst %.c,%.o,$(SRC) $(GNL_SRC))

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) $(FLAG) $(OBJ) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(MLX_FILE) $(MLX_FLAG) -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I$(INC_DIR) -c $< -o $@

lib:
	@make -C $(LIBFT_PATH)

# mlx: @make -C $(MLX_PATH) @make clean -sC $(MLX_PATH) @make fclean -C $(MLX_PATH) || true

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH) || true

re: fclean all

.PHONY: all clean fclean re
