/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_malloc_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:09:47 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/30 18:45:21 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static char *ft_strjoin_read(char *s1, char const *s2)
{
	size_t s1_len = s1 ? ft_strlen(s1) : 0;
	size_t s2_len = s2 ? ft_strlen(s2) : 0;
	char *join = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!join)
		return (NULL);
	if (s1)
		ft_strlcpy(join, s1, s1_len + 1);
	if (s2)
		ft_strlcpy(join + s1_len, s2, s2_len + 1);
	free(s1);
	return (join);
}

static char *read_and_concatenate_file(const char *av, int *fd)
{
	char	*line;
	char	*join_map = NULL;

	join_map = NULL;
	*fd = open(av, O_RDONLY);
	if (*fd < 0)
		return NULL;
	while ((line = get_next_line(*fd)) != NULL)
	{
		char *temp = ft_strjoin_read(join_map, line);
		free(line);
		join_map = temp;
	}
	ft_printf("fd = %d\n", *fd);
	return join_map;
}


static void calculate_dimensions(const char *join_map, size_t *line_count, size_t *max_line_length) 
{
	*line_count = 0;
	*max_line_length = 0;
	size_t line_length;
	size_t	i;

	i = 0;
	line_length = 0;
	while (join_map && join_map[i])
	{
		if (join_map[i] == '\n' || join_map[i+1] == '\0')
		{
			if (join_map[i] == '\n')
				line_length++;
			if (line_length > *max_line_length)
				*max_line_length = line_length;
			line_length = 0;
			(*line_count)++;
		} 
		else
			line_length++;
		i++;
	}
}


static void assign_map_to_game(t_game *game, char *join_map, size_t line_count, size_t max_line_length)
{
	if (join_map) 
	{
		game->map = ft_split(join_map, '\n');
		free(join_map);
	}
	game->lines = line_count;
	game->columns = max_line_length - 1;
}

void read_map(char *av, t_game *game) 
{
	int fd;
	size_t line_count;
	size_t max_line_length;
	char *join_map;
	
	join_map = read_and_concatenate_file(av, &fd);
	if (!join_map) 
	{
		free_and_show_errors("OPEN_ERROR", game);
		return;
	}
	calculate_dimensions(join_map, &line_count, &max_line_length);
	assign_map_to_game(game, join_map, line_count, max_line_length);
	close(fd);
}