/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:32:50 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/30 14:41:36 by nclassea         ###   ########.fr       */
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

void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprite.collectible);
	mlx_destroy_image(game->mlx, game->sprite.wall);
	mlx_destroy_image(game->mlx, game->sprite.down);
	mlx_destroy_image(game->mlx, game->sprite.ground);
	mlx_destroy_image(game->mlx, game->sprite.exit);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_map(game->map, game);
	free(game->mlx);
	exit(1);
}




	// game->sprite.base = xpm_to_img(game, "./img/wall/base.xpm");
	// game->sprite.collectible = xpm_to_img(game, "./img/item/arrow.xpm");
	// game->sprite.wall = xpm_to_img(game, "./img/wall/wall.xpm");
	// game->sprite.down = xpm_to_img(game, "./img/character/char_down.xpm");
	// game->sprite.ground = xpm_to_img(game, "./img/ground/ground.xpm");
	// game->sprite.exit = xpm_to_img(game, "./img/exit/exit.xpm");