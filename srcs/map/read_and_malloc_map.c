/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_malloc_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:09:47 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/06 17:41:41 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void read_lines(t_game *game)
{
	char *line;
	int line_len;

	game->lines = 0;
	game->columns = 0;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break;
		line_len = ft_strlen(line);
		if (line_len > game->columns)
			game->columns = line_len;

		game->lines++;
		free(line);
	}
	game->columns -= 1;
	close(game->fd);
}

static void allocate_lines(t_game *game)
{
	game->map = (char **)malloc(sizeof(char *) * game->lines);
	if (!game->map)
		free_and_display_errors(MALLOC_ERRORS, game);
}

static void malloc_lines(char *av, t_game *game)
{
	game->fd = open(av, O_RDONLY);
	if (game->fd < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	read_lines(game);
	allocate_lines(game);
}

static void	malloc_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->lines)
	{
		game->map[i] = (char *)malloc(sizeof(char) * (game->columns + 1));
		if (!game->map[i])
			free_and_display_errors(MALLOC_ERRORS, game);
		i++;
	}
}

void	read_map(char *av, t_game *game)
{
	char	*line;
	int		i;

	malloc_lines(av, game);
	malloc_columns(game);
	i = 0;
	game->fd = open(av, O_RDONLY);
	if (game->fd < 0)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(game->fd)) && i < game->lines)
	{
		ft_strlcpy(game->map[i], line, game->columns + 1);
		free(line);
		i++;
	}
	close(game->fd);
}
