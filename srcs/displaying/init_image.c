/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:05:58 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/30 18:26:48 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// init windows
void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (SIZE * game->columns),
		(SIZE * game->lines), WINDOW_NAME);
	// check if open worked 
}

void	**xpm_to_img(t_game *game, char *path)
{
	int	size;
	int	fd;
	void	**image;

	size = SIZE;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		mlx_clear_window(game->mlx, game->window);
	image = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	close(fd);
	return (image);
}

// init sprites 
void	init_sprites(t_game *game)
{
	game->sprite.collectible = xpm_to_img(game, "./img/item/arrow.xpm");
	game->sprite.wall = xpm_to_img(game, "./img/wall/wall.xpm");
	game->sprite.down = xpm_to_img(game, "./img/character/char_down.xpm");
	game->sprite.ground = xpm_to_img(game, "./img/ground/ground.xpm");
	game->sprite.exit = xpm_to_img(game, "./img/exit/exit.xpm");
}

// init map and put image
void	init_map(t_game *game)
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
				put_image(game, game->sprite.down, x, y);
			else if (game->map[x][y] == 'C')
				put_image(game, game->sprite.collectible, x, y);
			else if (game->map[x][y] == '1')
				put_image(game, game->sprite.wall, x, y);
			else if (game->map[x][y] == '0')
				put_image(game, game->sprite.ground, x, y);
			else if (game->map[x][y] == 'E')
				put_image(game, game->sprite.exit, x, y);
			y++;
		}
		x++;
	}
}