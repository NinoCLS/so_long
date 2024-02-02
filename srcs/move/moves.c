/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:36:42 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/02 16:41:17 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_up(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->x - 1;
	next_y = game->y;
	if (next_x >= 0 && game->map[next_x][next_y] != '1')
	{
		if (game->map[next_x][next_y] == 'C')
			game->collectible_count--;
		else if (game->map[next_x][next_y] == 'E'
			&& game->collectible_count == 0)
			end_game("GG", game, 2);
		if (game->map[next_x][next_y] != 'E' || game->collectible_count == 0)
		{
			game->map[game->x][game->y] = '0';
			game->x = next_x;
			game->map[game->x][game->y] = 'P';
		}
		game->moves += 1;
		draw_map(game);
	}
}

void	move_down(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->x + 1;
	next_y = game->y;
	if (next_x >= 0 && game->map[next_x][next_y] != '1')
	{
		if (game->map[next_x][next_y] == 'C')
			game->collectible_count--;
		else if (game->map[next_x][next_y] == 'E'
			&& game->collectible_count == 0)
			end_game("GG", game, 2);
		if (game->map[next_x][next_y] != 'E' || game->collectible_count == 0)
		{
			game->map[game->x][game->y] = '0';
			game->x = next_x;
			game->map[game->x][game->y] = 'P';
		}
		game->moves += 1;
		draw_map(game);
	}
}

void	move_right(t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->x;
	next_y = game->y + 1;
	if (next_y >= 0 && game->map[next_x][next_y] != '1')
	{
		if (game->map[next_x][next_y] == 'C')
			game->collectible_count--;
		else if (game->map[next_x][next_y] == 'E'
			&& game->collectible_count == 0)
			end_game("GG", game, 2);
		if (game->map[next_x][next_y] != 'E' || game->collectible_count == 0)
		{
			game->map[game->x][game->y] = '0';
			game->y = next_y;
			game->map[game->x][game->y] = 'P';
		}
		game->moves += 1;
		draw_map(game);
	}
}

void	move_left(t_game *game)
{
	int next_x;
	int next_y;

	next_x = game->x;
	next_y = game->y - 1;

	if (next_y >= 0 && game->map[next_x][next_y] != '1')
	{
		if (game->map[next_x][next_y] == 'C')
			game->collectible_count--;
		else if (game->map[next_x][next_y] == 'E'
			&& game->collectible_count == 0)
			end_game("GG", game, 2);
		if (game->map[next_x][next_y] != 'E' || game->collectible_count == 0)
		{
			game->map[game->x][game->y] = '0';
			game->y = next_y;
			game->map[game->x][game->y] = 'P';
		}
		game->moves += 1;
		draw_map(game);
	}
}