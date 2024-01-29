/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:43:42 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/29 17:44:42 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

// add MSG ERROR 
# define ARG_ERROR1 "Miss one argument ! Please provide a .ber file."
# define ARG_ERROR2 "Too many arguments."
# define EXTENSION_NAME_ERROR "Invalid map file. Please provide a .ber file."
# define READ_ERROR "The argument must be a file."
# define OPEN_ERROR "The file can't be open"
# define EMPTY_ERROR "The file is empty"
# define MALLOC_ERRORS "Malloc allocation failed"
# define MAP_ERROR_EMPTY "Map Error : Empty or uninitialized map"
# define MAP_ERROR_RECTANGLE "Map Error : Map is not rectangle"
# define WALL_ERROR "Map error: Map is not enclosed by walls"
# define PLAYER_ERROR "Map error: Missing or incorrect number of player"
# define COLLECTIBLE_ERROR "Map error: Missing or incorrect number of collectible"
# define EXIT_ERROR "Map error: Missing or incorrect number of exit"
# define COLLECTIBLE_PATH_ERROR "Map error : Collectible can't be reached"
# define EXIT_PATH_ERROR "Map error : exit can't be reached"

// window
# define WINDOW_NAME "Game"

// keycode
# define ESC 65307
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97


// state
# define SIZE 50

// struct image
typedef struct s_sprite
{
	void	**base;
	void	**wall;
	void	**ground;
	void	**exit;
	void	**character;
	void	**collectible;
	void	**up;
	void	**down;
	void	**right;
	void	**left;
	void	**arrow;
}	t_sprite;


// struct game

typedef struct s_game
{
	char	**map;
	char	**av;
	void	*window;
	void	*mlx;
	int		lines;
	int		columns;
	int		player_count;
	int		collectible_count;
	int		exit_count;
	int		moves;
	int		temp_collectible;
	int		arrow_position;
	int		fd;
	int		x;
	int		y;
	t_sprite sprite;
}	t_game;

#endif

/*errors*/
void	show_errors(char *err);
void	free_map(char **map, t_game *game);
void	free_and_show_errors(char *err, t_game *game);

/*init game*/
void	init_game(t_game *game, char **av);
void	init_game_data(t_game *game);
void	init_window(t_game *game);
void	init_sprites(t_game *game);
void	init_map(t_game *game);

/*read map*/
void	read_map(char *av, t_game *game);

/*check map*/
void	check_map(char *av, t_game *game);
void	check_path(t_game *game);

// mlx
void	put_image(t_game *game, void **image, int x, int y);