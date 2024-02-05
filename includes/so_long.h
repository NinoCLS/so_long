/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:43:42 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/05 18:24:16 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>

/*MSG_ERROR*/
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
# define COLLECTIBLE_ERROR "Map error: Missing or incorrect \
	number of collectible"
# define EXIT_ERROR "Map error: Missing or incorrect number of exit"
# define COLLECTIBLE_PATH_ERROR "Map error : Collectible can't be reached"
# define EXIT_PATH_ERROR "Map error : exit can't be reached"
# define ESC_MSG "Quitting the game. Thank you for playing!"
# define WIN "Congratulations! You've successfully completed the level."
# define LOOSE "Game Over. Don't give up, try again!"

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
}				t_sprite;

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
	t_sprite	sprite;
}				t_game;

/*errors*/
void			show_errors(char *err);
void			free_map(char **map, t_game *game);
void			free_and_show_errors(char *err, t_game *game);
void			end_game(char *msg, t_game *game, int num);
int				red_cross(t_game *game);

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

/*moves*/
void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);
void			print_map_string(t_game *game);

/*hooks*/
int				key_handler(int key, t_game *game);

#endif