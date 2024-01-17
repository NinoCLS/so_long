/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:32:50 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/15 14:36:42 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_errors(char *err)
{
	ft_putstr_fd("ERROR - ", 2);
	ft_putstr_fd(err, 2);
	exit(1); // add something in exit 
}

// free map 
void	free_map(char **map, t_game *game)
{
	int	i;

	i = 0;
	while (game->lines > i)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (map)
	{
		free(map);
		map = NULL;
	}
}

void	free_and_show_errors(char *err, t_game *game)
{
	free_map(game->map, game);
	show_errors(err);
}

void	free_close_and_show_errors(char *err, t_game *game, int option)
{
	// free lines 
	if (option == 0)
	{
		free(game->map);
		game->map = NULL;
	}
	// free map
	else if (option == 1)
		free_map(game->map, game);
	close(game->fd);
	show_errors(err);
}