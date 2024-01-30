/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:55:20 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/30 18:41:22 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

// key handler 
int	key_handler(int	key, t_game *game)
{
	if (key == ESC)
		end_game(ESC_MSG, game, 2);
	// else if (key == UP)
	// 	//
	// else if (key == DOWN)
	// 	//
	// else if (key == RIGHT)
	// 	//
	// else if (key == LEFT)
	// 	//
	return (0);
}
