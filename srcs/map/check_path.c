/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:50:30 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/08 16:11:29 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char	**duplicate_game_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = ft_calloc(game->lines, sizeof(char *));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (i < game->lines)
	{
		map_copy[i] = (char *)malloc(sizeof(char) * game->columns + 1);
		if (!map_copy[i])
		{
			while (i-- < 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		ft_strlcpy(map_copy[i], game->map[i], game->columns + 1);
		i++;
	}
	return (map_copy);
}

void	valid_path(char **map, int x, int y, t_game *game)
{
	if (x < 0 || x >= game->lines || y < 0 || y >= game->columns)
		return ;
	if (map[x][y] == 'E')
		game->exit_count = 1;
	while (map[x][y] != '1' && map[x][y] != 'V' && map[x][y] != 'M'
		&& map[x][y] != 'E')
	{
		if (map[x][y] == 'C')
			game->temp_collectible--;
		map[x][y] = 'V';
		valid_path(map, x + 1, y, game);
		valid_path(map, x - 1, y, game);
		valid_path(map, x, y + 1, game);
		valid_path(map, x, y - 1, game);
	}
}

void	check_path(t_game *game)
{
	char	**map_copy;
	int		i;

	i = 0;
	game->exit_count = 0;
	game->temp_collectible = game->collectible_count;
	map_copy = duplicate_game_map(game);
	valid_path(map_copy, game->x, game->y, game);
	free_map(map_copy, game);
	if (game->temp_collectible != 0)
		end_game(COLLECTIBLE_PATH_ERROR, game, 1);
	if (game->exit_count != 1)
		end_game(EXIT_PATH_ERROR, game, 1);
}
