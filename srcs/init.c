/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:53:14 by nclassea          #+#    #+#             */
/*   Updated: 2023/12/19 14:55:28 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// initialize the t_game struct witout malloc and save av in it
void	init_game(t_game game, char **av)
{
	ft_memset(game, 0, sizeof(t_game));
	game->av = av;
}