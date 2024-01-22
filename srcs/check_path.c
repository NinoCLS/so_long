/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:50:30 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/22 17:43:00 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**duplicate_game_map(t_game *game)
{
	char	**map_copy;
	int	i;

	map_copy = ft_calloc(game->lines, 1);
	if (!map_copy)
		return NULL;
	
	i = 0;
	while (i < game->lines)
	{
		map_copy[i] = (char *)malloc(sizeof(char) * game->columns + 1);
		if (!map_copy[i])
		{
			while (i-- < 0)
				free(map_copy[i]);
			free(map_copy);
			return NULL;
		}
		ft_strlcpy(map_copy[i], game->map[i], game->columns + 1);
		i++;
	}
	return map_copy;
}

void	flood_fill(char **map, int x, int y, t_game *game)
{
	if (map[y][x] == 'C')
		game->temp_collectible--;
	else if (map[y][x] == 'E')
		game->exit_count--;
	map[y][x] = 'X';
}


void	check_path(t_game *game)
{
	char **map_copy;

	game->temp_collectible = game->collectible_count;
	map_copy = duplicate_game_map(game);
	flood_fill(map_copy, game->x, game->y, game);
}


/// test map_copy 

// if (map_copy) 
// 	{
// 		__builtin_printf("ici");
// 		for (int i = 0; i < game->lines; i++)
// 			__builtin_printf("Original: %s\nCopied: %s\n\n", game->map[i], map_copy[i]);
// 	}

// 	// Libérer la mémoire allouée pour la carte copiée
// 	for (int i = 0; i < game->lines; i++) {
// 		free(map_copy[i]);
// 	}
// 	free(map_copy);