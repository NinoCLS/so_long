/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_malloc_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:09:47 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/22 15:09:40 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	malloc_lines(char *av, t_game *game)
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
	if (game->lines >= 78) // definir le heigh
	{
		free_and_show_errors("Map is invalid - Heigh is too big for your screen", game);
		close(game->fd);
	}
	game->map = (char **)malloc(sizeof(char **) * game->lines);
	if (!game->map)
		free_and_show_errors(MALLOC_ERRORS, game);
	close(game->fd);
}

static void	malloc_columns(char *av, t_game *game)
{
	int	i;

	i = 0;
	game->fd = open(av, O_RDONLY);
	if (game->fd < 0)
	{
		free_and_show_errors(OPEN_ERROR, game);
		close(game->fd);
	}
	game->columns = ft_strlen(get_next_line(game->fd)) - 1;
	// definir le Max 
	while (i < game->lines)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (game->columns + 1));
		i++;
	}
	close(game->fd);
}

// malloc lines and columns and use gnl to read map file and copie its content to game->map
void	read_map(char *av, t_game *game)
{
	int	i;
	char *line;

	i = 0;
	// malloc lines
	malloc_lines(av, game);
	// malloc columns
	malloc_columns(av, game);
	game->fd = open(av, O_RDONLY);
	if (game->fd < 0)
		free_and_show_errors(OPEN_ERROR, game); 
	while (i < game->lines && (line = get_next_line(game->fd)) != NULL)
	{
		game->map[i] = line;
		i++;
	}
	close(game->fd);
}