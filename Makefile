NAME = so_long
CC = cc
RM = rm -rf
CFLAG = -Wall -Wextra -Werror -g3
LIBFT_PATH = ./libft/
LIBFT = libft.a
MLX_PATH = ./minilibx-linux/
MLX_FILE = libmlx.a
MLX_FLAG = -Lmlx -lXext -lX11
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT))
MLX_LIB = $(addprefix $(MLX_PATH), $(MLX_FILE))
GNL_FILES = get_next_line.c get_next_line_utils.c
SRCS_DIR = ./srcs/
GNL_DIR = ./gnl/
INC_DIR = ./include/
MAP = $(addprefix map/, map_checker.c init.c read_and_malloc_map.c check_path.c check_utils.c)
DISPLAYING = $(addprefix displaying/, display_image.c init_image.c display_game_over.c)
MOVE = $(addprefix move/, moves.c  keys.c)
SRC = $(addprefix $(SRCS_DIR), $(MAP) $(DISPLAYING) $(MOVE) so_long.c end_game.c)
GNL_SRC = $(addprefix $(GNL_DIR), $(GNL_FILES))
OBJ = $(patsubst %.c,%.o,$(SRC) $(GNL_SRC))

all: minilibx-linux $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(MLX_PATH)
	$(RM) $(NAME)
	make all -C $(LIBFT_PATH)
	$(CC) $(CFLAG) $(OBJ) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAG) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAG) -I$(INC_DIR) -c $< -o $@

minilibx-linux:
	git clone https://github.com/42Paris/minilibx-linux.git $@

clean:
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(MLX_PATH)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re