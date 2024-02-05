/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:40:19 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/05 17:54:41 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_errors(char *err)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(err, 2);
	exit(1);
}

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

static void	destroy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprite.collectible);
	mlx_destroy_image(game->mlx, game->sprite.wall);
	mlx_destroy_image(game->mlx, game->sprite.down);
	mlx_destroy_image(game->mlx, game->sprite.up);
	mlx_destroy_image(game->mlx, game->sprite.right);
	mlx_destroy_image(game->mlx, game->sprite.left);
	mlx_destroy_image(game->mlx, game->sprite.ground);
	mlx_destroy_image(game->mlx, game->sprite.exit);
	mlx_destroy_image(game->mlx, game->sprite.open_exit);
	mlx_destroy_image(game->mlx, game->sprite.monster);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free_map(game->map, game);
	free(game->mlx);
	exit(1);
}
void	end_game(char *msg, t_game *game, int num)
{
	if (num == 1)
	{
		free_map(game->map, game);
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd(msg, 1);
		exit(1);
	}
	else if (num == 2)
	{
		ft_putstr_fd("\n\n", 1);
		ft_putstr_fd(msg, 1);
		destroy_image(game);
		exit(0);
	}
}