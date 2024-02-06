/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:36:42 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/06 17:16:03 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	move_player(t_game *game, int next_x, int next_y)
{
	if (next_x < 0 || next_x >= game->lines || next_y < 0
		|| next_y >= game->columns || game->map[next_x][next_y] == '1')
		return ;
	if (game->map[next_x][next_y] == 'C')
		game->collectible_count--;
	else if (game->map[next_x][next_y] == 'E' && game->collectible_count == 0)
		end_game(WIN, game, 2);
	else if (game->map[next_x][next_y] == 'M')
		end_game(LOOSE, game, 3);
	if (game->map[next_x][next_y] != 'E' || game->collectible_count == 0)
	{
		game->map[game->x][game->y] = '0';
		game->map[next_x][next_y] = 'P';
		game->x = next_x;
		game->y = next_y;
		game->moves += 1;
	}
	draw_map(game);
}

void	move_up(t_game *game)
{
	move_player(game, game->x - 1, game->y);
}

void	move_down(t_game *game)
{
	move_player(game, game->x + 1, game->y);
}

void	move_right(t_game *game)
{
	move_player(game, game->x, game->y + 1);
}

void	move_left(t_game *game)
{
	move_player(game, game->x, game->y - 1);
}
