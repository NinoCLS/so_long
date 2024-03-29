/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:45:09 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/28 15:46:08 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_extension(char *av)
{
	int	i;
	int	fd;

	i = (ft_strlen(av) - 4);
	if (ft_strncmp(".ber", &av[i], 4) != 0)
		display_errors(EXTENSION_NAME_ERROR);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		display_errors(OPEN_ERROR);
	close(fd);
}

static void	check_rectangle(t_game *game)
{
	size_t	first_line_length;
	int		i;

	if (game->lines <= 0 || game->map == NULL || game->map[0] == NULL)
	{
		end_game(MAP_ERROR_EMPTY, game, 1);
		return ;
	}
	i = 1;
	first_line_length = ft_strlen(game->map[0]);
	while (i < game->lines)
	{
		if (ft_strlen(game->map[i]) != first_line_length)
		{
			end_game(MAP_ERROR_RECTANGLE, game, 1);
			return ;
		}
		i++;
	}
}

static void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->columns)
	{
		if (game->map[0][i] != '1' || game->map[game->lines - 1][i] != '1')
			end_game(WALL_ERROR, game, 1);
		i++;
	}
	i = 0;
	while (i < game->lines)
	{
		if (game->map[i][0] != '1' || game->map[i][game->columns - 1] != '1')
			end_game(WALL_ERROR, game, 1);
		i++;
	}
}

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
			else if (game->map[x][y] != '1' && game->map[x][y] != '0')
				end_game(ELEMENT_ERROR, game, 1);
			y++;
		}
		x++;
	}
}

void	check_map(char *av, t_game *game)
{
	check_extension(av);
	read_map(av, game);
	check_rectangle(game);
	check_walls(game);
	check_elements(game);
	if (game->player_count != 1)
		end_game(PLAYER_ERROR, game, 1);
	if (game->collectible_count < 1)
		end_game(COLLECTIBLE_ERROR, game, 1);
	if (game->exit_count != 1)
		end_game(EXIT_ERROR, game, 1);
	check_path(game);
}
