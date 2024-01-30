/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:40:19 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/30 18:44:41 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void	end_game(char *msg, t_game *game, int num)
{
	if (num == 1)
	{
		free_map(game->map, game);
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd(msg, 1);
		exit(1);
	}
	else if (num == 2)
	{
		ft_putstr_fd(msg, 1);
		destroy_image(game);
		exit(0);
	}
}