/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:43:42 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/17 17:19:58 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>

// add MSG ERROR 
# define ARG_ERROR1 "Miss one argument ! Please provide a .ber file."
# define ARG_ERROR2 "Too many arguments."
# define EXTENSION_NAME_ERROR "Invalid map file. Please provide a .ber file."
# define READ_ERROR "The argument must be a file."
# define OPEN_ERROR "The file can't be open"
# define EMPTY_ERROR "empty" // a redefinir 


// struct image 





// struct game

typedef struct s_game
{
	char	**map;
	char 	**av;
	void	*window;
	void	*mlx;
	int		lines;
	int		columns;
	int		player_num;
	int		collect_num;
	int		exit_num;
	int		moves;
	int		temp;
	int		fd;
	int		arrow_position;
	int		x;
	int		y;
}	t_game;

#endif

/*errors*/
void	show_errors(char *err);
void	free_map(char **map, t_game *game);
void	free_and_show_errors(char *err, t_game *game);
void	free_close_and_show_errors(char *err, t_game *game, int option);


/*init game*/
void	init_game(t_game *game, char **av);
void	init_game_data(t_game *game);

/*read map*/
void	read_map(char *av, t_game *game);

/*check map*/
void	check_map(char *av, t_game *game);
