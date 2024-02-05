/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:46:21 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/05 18:23:52 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void put_image(t_game *game, void **image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, image, (y * SIZE), (x * SIZE));
}

static void draw_sprite(t_game *game, char tile, int x, int y) 
{
	if (tile == 'P')
		put_image(game, game->sprite.current, x, y);
	else if (tile == 'C')
		put_image(game, game->sprite.collectible, x, y);
	else if (tile == '1')
		put_image(game, game->sprite.wall, x, y);
	else if (tile == '0')
		put_image(game, game->sprite.ground, x, y);
	else if (tile == 'E' && game->collectible_count == 0)
		put_image(game, game->sprite.open_exit, x, y);
	else if (tile == 'E')
		put_image(game, game->sprite.exit, x, y);
	else if (tile == 'M')
		put_image(game, game->sprite.monster, x, y);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->lines)
	{
		y = 0;
		while (y < game->columns)
		{
			draw_sprite(game, game->map[x][y], x, y);
			y++;
		}
		x++;
	}
}

void	print_map_string(t_game *game)
{
	char	*string;

	string = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 4,
		(35), 0xFFFFFF, "Movements: ");
	mlx_string_put(game->mlx, game->window, 68,
		(35), 0xFFFFFF, string);
	free(string);
	string = NULL;
	return ;
}
