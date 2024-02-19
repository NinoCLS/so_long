/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:30:55 by nclassea          #+#    #+#             */
/*   Updated: 2024/02/19 16:44:05 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_point	get_screen_size(t_game *game)
{
	t_point	point;

	mlx_get_screen_size(game->mlx, &point.size_x, &point.size_y);
	return (point);
}

void	check_window(t_game *game)
{
	t_point	screen_size;

	screen_size = get_screen_size(game);
	if (((game->columns * SIZE) > screen_size.size_x) || ((game->lines
				* SIZE) > screen_size.size_y))
		end_game(SCREEN_ERROR, game, 2);
}

char	*ft_strstr(char *haystack, char *needle)
{
	size_t	haystack_len;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	i = 0;
	while (i <= haystack_len - needle_len)
	{
		j = 0;
		while (j < needle_len)
		{
			if (haystack[i + j] != needle[j])
				break ;
			j++;
		}
		if (j == needle_len)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
