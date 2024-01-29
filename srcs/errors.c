/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:32:50 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/29 10:02:31 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_errors(char *err)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(err, 2);
	exit(1); // add something in exit 
}

// free map 
void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (game->lines > i)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (map)
	{
		free(map);
		map = NULL;
	}
}

void	free_and_show_errors(char *err, t_game *game)
{
	free_map(game->map, game);
	show_errors(err);
}

// void	destroy_image(t_game *game)
// {
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_window(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_image(game->mlx);
// 	mlx_destroy_display(game->mlx);
// 	free_map(game);
// 	free(game->mlx_pointer);
// 	return ;
// }