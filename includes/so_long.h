/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:43:42 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/28 15:46:27 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

/*MSG_ERROR*/
# define ARG_ERROR1 "Error\n\nMiss one argument ! Please provide a .ber file."
# define ARG_ERROR2 "Error\n\nToo many arguments."
# define EXTENSION_NAME_ERROR "Error\n\nInvalid map file. \
	Please provide a .ber file."
# define READ_ERROR "Error\n\nThe argument must be a file."
# define OPEN_ERROR "Error\n\nThe file can't be open"
# define EMPTY_ERROR "Error\n\nThe file is empty"
# define MALLOC_ERRORS "Error\n\nMalloc allocation failed"
# define MAP_ERROR_EMPTY "Error\n\nEmpty or uninitialized map"
# define MAP_ERROR_RECTANGLE "Error\n\nMap is not rectangle"
# define WALL_ERROR "Error\n\nMap is not enclosed by walls"
# define PLAYER_ERROR "Error\n\nMissing or incorrect number of player"
# define COLLECTIBLE_ERROR "Error\n\nMissing or incorrect \
	number of collectible"
# define ELEMENT_ERROR "Error\n\nMap must contain at least one of each element"
# define EXIT_ERROR "Error\n\nMissing or incorrect number of exit"
# define COLLECTIBLE_PATH_ERROR "Error\n\nCollectible can't be reached"
# define EXIT_PATH_ERROR "Error\n\nExit can't be reached"
# define SCREEN_ERROR "Error\n\nMap size is bigger than display resolution"
# define ENV "Error\n\nNo env variable"
# define XPM_ERROR "Error\n\nXPM file error"
# define ESC_MSG "\n\nQuitting the game. Thank you for playing!"
# define WIN "\n\nCongratulations! You've successfully completed the level."
# define LOOSE "\n\nGame Over. Don't give up, try again!"

/*window*/
# define WINDOW_NAME "so_long"

/*keycode*/
# define ESC 65307
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97

/*state*/
# define SIZE 60
# define SIZE_GAME_OVER 300

/*key*/
# define DESTROY_NOTIF 17
# define NO_EVENT_MASK 0

/*struct image*/
typedef struct s_sprite
{
	void		**wall;
	void		**ground;
	void		**exit;
	void		**open_exit;
	void		**character;
	void		**collectible;
	void		**current;
	void		**up;
	void		**down;
	void		**right;
	void		**left;
	void		**monster;
	void		**game_over;
	void		**death_1;
}				t_sprite;

typedef struct s_point
{
	int	size_x;
	int	size_y;
}	t_point;

/*struct game*/
typedef struct s_game
{
	char		**map;
	char		**av;
	void		*window;
	void		*mlx;
	int			lines;
	int			columns;
	int			player_count;
	int			collectible_count;
	int			exit_count;
	int			moves;
	int			temp_collectible;
	int			fd;
	int			x;
	int			y;
	int			x_position;
	int			y_position;
	t_sprite	sprite;
}				t_game;

/*errors*/
void			display_errors(char *err);
void			free_map(char **map, t_game *game);
void			end_game(char *msg, t_game *game, int num);
int				red_cross(t_game *game);
void			display_death(t_game *game);
void			display_death2(t_game *game);
void			display_death3(t_game *game);
void			display_game_over(t_game *game);

/*utils*/
char			*ft_strstr(char *haystack, char *needle);

/*init game*/
void			init_game(t_game *game, char **av);
void			init_game_data(t_game *game);
void			init_window(t_game *game);
void			init_sprites(t_game *game);
void			draw_map(t_game *game);

/*read map*/
void			read_map(char *av, t_game *game);

/*check map*/
void			check_map(char *av, t_game *game);
void			check_path(t_game *game);
void			check_window(t_game *game);

/*moves*/
void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			print_moves_on_map(t_game *game);

/*hooks*/
int				key_handler(int key, t_game *game);

/*mlx*/
void			**xpm_to_img(t_game *game, char *path);

#endif