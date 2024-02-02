/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:55:20 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/02 16:44:14 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// key handler
int key_handler(int key, t_game *game)
{
	if (key == ESC)
		end_game(ESC_MSG, game, 2);
	else if (key == UP)
		move_up(game);
	else if (key == DOWN)
		move_down(game);
	else if (key == RIGHT)
		move_right(game);
	else if (key == LEFT)
		move_left(game);
	ft_putstr_fd("\rMovements : ", 1);
	ft_putnbr_fd(game->moves, 1);
	return (0);
}
