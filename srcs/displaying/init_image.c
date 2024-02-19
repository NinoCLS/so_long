/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:05:58 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/12 16:57:12 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (SIZE * game->columns), (SIZE
				* game->lines), WINDOW_NAME);
}

void	**xpm_to_img(t_game *game, char *path)
{
	int		size;
	int		fd;
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
	game->sprite.collectible = xpm_to_img(game, "./textures/item/item.xpm");
	game->sprite.wall = xpm_to_img(game, "./textures/wall/wall.xpm");
	game->sprite.down = xpm_to_img(game, "./textures/character/char_down.xpm");
	game->sprite.current = game->sprite.down;
	game->sprite.up = xpm_to_img(game, "./textures/character/char_up.xpm");
	game->sprite.right = xpm_to_img(game,
			"./textures/character/char_right.xpm");
	game->sprite.left = xpm_to_img(game, "./textures/character/char_left.xpm");
	game->sprite.ground = xpm_to_img(game, "./textures/ground/ground.xpm");
	game->sprite.exit = xpm_to_img(game, "./textures/exit/exit.xpm");
	game->sprite.open_exit = xpm_to_img(game, "./textures/exit/open_exit.xpm");
	game->sprite.monster = xpm_to_img(game, "./textures/monster/monster.xpm");
}

int	red_cross(t_game *game)
{
	end_game("", game, 2);
	return (0);
}
