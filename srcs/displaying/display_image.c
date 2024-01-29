/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:46:21 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/29 17:31:40 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_image(t_game *game, void **image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, image, (y * SIZE), (x * SIZE));
}

// recuperer les mouvements et les afficher
void	move_player(t_game *game)
{
	// move up 
	// move down
	// move right
	// move left 
}
