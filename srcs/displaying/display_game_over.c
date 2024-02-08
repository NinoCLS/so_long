/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game_over.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 18:24:50 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/08 14:23:27 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	display_game_over(t_game *game)
{
	int	window_width;
	int	window_height;
	int	sprite_width;
	int	sprite_height;

	window_width = game->columns * SIZE;
	window_height = game->lines * SIZE;
	game->sprite.game_over = xpm_to_img(game,
			"./textures/game_over/game_over.xpm");
	game->sprite.death_1 = xpm_to_img(game, "./textures/game_over/death1.xpm");
	sprite_width = SIZE_GAME_OVER;
	sprite_height = SIZE_GAME_OVER;
	game->x_position = (window_width - sprite_width) / 2;
	game->y_position = (window_height - sprite_height) / 2;
	mlx_put_image_to_window(game->mlx, game->window, game->sprite.death_1,
		game->x_position, game->y_position);
	mlx_do_sync(game->mlx);
	sleep(2);
	mlx_destroy_image(game->mlx, game->sprite.death_1);
	draw_map(game);
	mlx_put_image_to_window(game->mlx, game->window, game->sprite.game_over,
		game->x_position, game->y_position);
	mlx_do_sync(game->mlx);
	sleep(2);
	mlx_destroy_image(game->mlx, game->sprite.game_over);
}
