/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:53:14 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/08 14:22:03 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_game(t_game *game, char **av)
{
	ft_memset(game, 0, sizeof(t_game));
	game->av = av;
}

void	init_game_data(t_game *game)
{
	game->lines = 0;
	game->columns = 0;
	game->player_count = 0;
	game->collectible_count = 0;
	game->exit_count = 0;
	game->moves = 0;
}
