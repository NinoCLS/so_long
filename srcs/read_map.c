/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:09:47 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/17 17:22:09 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	malloc_lines(char *av, t_game *game)
{
	game->fd = open(av, O_RDONLY);
	if (game->fd < 0)
	{
		free_and_show_errors(OPEN_ERROR, game);
		close(game->fd);
	}
	while(get_next_line(game->fd))
		game->lines++;
	if (game->lines == 0)
	{
		free_and_show_errors(EMPTY_ERROR, game);
		close(game->fd);
	}
	if (game->lines > 100)
	{
		free_and_show_errors("trop grand // a definir", game);
		close(game->fd);
	}
	game->map = (char **)malloc(sizeof(char **) * game->lines);
	close(game->fd);
}

// void	malloc_lines(char *av, t_game *game)
// {
	
// }

// malloc lines and columns and use gnl to read map file and copie its content to game->map
void	read_map(char *av, t_game *game)
{
	int	i;

	i = 0;
	// malloc columns
	malloc_columns(&av[1], game);
	// malloc lines 
	// game->fd open 
	// while game->lines > i ====> memcpy gam->map[i]
	// close
}