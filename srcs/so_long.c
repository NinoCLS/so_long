/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:04:25 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/06 17:25:00 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(t_game *game)
{
	init_game_data(game);
	check_map(game->av[1], game);
	init_window(game);
	init_sprites(game);
	draw_map(game);
	mlx_hook(game->window, DESTROY_NOTIF, NO_EVENT_MASK, red_cross, game);
	mlx_key_hook(game->window, key_handler, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 1)
		display_errors(ARG_ERROR1);
	if (ac > 2)
		display_errors(ARG_ERROR2);
	init_game(&game, av);
	start_game(&game);
}
