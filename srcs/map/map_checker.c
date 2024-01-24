/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:45:09 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/24 16:59:53 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// doest the map file exist / is there someting in the map file 
void	check_extension(char *av)
{
	int	i;
	int fd;
	// void *buf;
	
	// check the last 4 char
	i = (ft_strlen(av) - 4);
	if (ft_strncmp(".ber", &av[i], 4) != 0)
		show_errors(EXTENSION_NAME_ERROR);
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		show_errors(OPEN_ERROR);
	}
	close(fd);
}

// check if rectangle
static void	check_rectangle(t_game *game)
{
	size_t	first_line_length;
	int	i;

	if (game->lines <= 0 || game->map == NULL || game->map[0] == NULL)
	{
		free_and_show_errors(MAP_ERROR_EMPTY, game);
		return;
	}
	i = 1;
	first_line_length = ft_strlen(game->map[0]);
	while (i < game->lines)
	{
		if (ft_strlen(game->map[i]) != first_line_length)
		{
			free_and_show_errors(MAP_ERROR_RECTANGLE, game);
			return;
		}
		i++;
	}
}

// // is the map enclosed in walls
static void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	// check first and last line
	while (i < game->columns)
	{
		if (game->map[0][i] != '1' || game->map[game->lines - 1][i] != '1')
			free_and_show_errors(WALL_ERROR, game);
		i++;
	}
	i = 0;
	// check first and last column
	while (i < game->lines)
	{
		if (game->map[i][0] != '1' || game->map[i][game->columns - 1] != '1')
			free_and_show_errors(WALL_ERROR, game);
		i++;
	}
}

//check exit, char position, collectible ... 
static void	check_elements(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->lines)
	{
		y = 0;
		while (y < game->columns)
		{
			if (game->map[x][y] == 'P')
			{
				game->player_count++;
				game->x = x;
				game->y = y;
			}
			else if (game->map[x][y] == 'C')
				game->collectible_count++;
			else if (game->map[x][y] == 'E')
				game->exit_count++;
			y++;
		}
		x++;
	}
}


// validate map 
void	check_map(char *av, t_game *game)
{
	// check .ber
	check_extension(av);
	// read and malloc map
	read_map(av, game);
	// check if rectangle
	check_rectangle(game);
	// check walls
	check_walls(game);
	// check elements
	check_elements(game);
	if (game->player_count != 1)
		free_and_show_errors(PLAYER_ERROR, game);
	if (game->collectible_count < 1)
		free_and_show_errors(COLLECTIBLE_ERROR, game);
	if (game->exit_count != 1)
		free_and_show_errors(EXIT_ERROR, game);
	// check path
	check_path(game);
}
