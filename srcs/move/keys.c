/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:55:20 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/06 15:31:04 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	print_moves(t_game *game)
{
	ft_putstr_fd("\rMovements : ", 1);
	ft_putnbr_fd(game->moves, 1);
	print_map_string(game);
}

int key_handler(int key, t_game *game)
{
	if (key == ESC)
		end_game(ESC_MSG, game, 2);
	else if (key == UP)
	{
		game->sprite.current = game->sprite.up;
		move_up(game);
	}
	else if (key == DOWN)
	{
		game->sprite.current = game->sprite.down;
		move_down(game);
	}
	else if (key == RIGHT)
	{
		game->sprite.current = game->sprite.right;
		move_right(game);
	}
	else if (key == LEFT)
	{
		game->sprite.current = game->sprite.left;
		move_left(game);
	}
	print_moves(game);
	return (0);
}
