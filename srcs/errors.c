/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:32:50 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/31 14:21:38 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_errors(char *err)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(err, 2);
	exit(1);
}

// free map 
void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < game->lines)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_and_show_errors(char *err, t_game *game)
{
	free_map(game->map, game);
	show_errors(err);
}





	// game->sprite.base = xpm_to_img(game, "./img/wall/base.xpm");
	// game->sprite.collectible = xpm_to_img(game, "./img/item/arrow.xpm");
	// game->sprite.wall = xpm_to_img(game, "./img/wall/wall.xpm");
	// game->sprite.down = xpm_to_img(game, "./img/character/char_down.xpm");
	// game->sprite.ground = xpm_to_img(game, "./img/ground/ground.xpm");
	// game->sprite.exit = xpm_to_img(game, "./img/exit/exit.xpm");