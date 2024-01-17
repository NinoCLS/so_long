/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:04:25 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/17 16:07:03 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// function start game 
void	start_game(t_game *game)
{
	init_game_data(game);
	check_map(game->av[1], game);
}

int main (int ac, char **av)
{
	t_game game;

	// check args
	if (ac == 1)
		show_errors(ARG_ERROR1);
	if (ac > 2)
		show_errors(ARG_ERROR2);
	
	// initialiser la game
	init_game(&game, av);
	// start la game
	start_game(&game);
}