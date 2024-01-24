/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:53:14 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/24 17:29:13 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// initialize the t_game struct witout malloc
void	init_game(t_game *game, char **av)
{
	ft_memset(game, 0, sizeof(t_game));
	game->av = av;
}
// init data 
void	init_game_data(t_game *game)
{
	game->lines = 0;
	game->columns = 0;
	game->player_count = 0;
	game->collectible_count= 0;
	game->exit_count = 0;
	game->moves = 0;
}

// init windows
void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (SIZE * game->columns),
		(SIZE * game->lines), WINDOW_NAME);
	// check if open worked 
}

// void	**convert_xpm_to_img(t_game *game)
// {
	
// }

// init sprites 
// void	init_sprite(t_game *game)
// {
// 	game->sprite.wall = // mlx_xpm_to_img
// }

// init map and put image
