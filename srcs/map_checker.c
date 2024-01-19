/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nino <nino@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:45:09 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/19 18:03:18 by nino             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// doest the map file exist / is there someting in the map file 
void	check_extension(char *av)
{
	int	i;
	int fd;
	void *buf;
	
	// check the last 4 char
	i = (ft_strlen(av) - 4);
	if (ft_strncmp(".ber", &av[i], 4) != 0)
		show_errors(EXTENSION_NAME_ERROR);
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		show_errors(OPEN_ERROR);
	}
	if (read(fd, &buf, 1) == -1)
	{
		close(fd);
		show_errors(READ_ERROR);
	}
	close(fd);
}

//check if rectangle
// static void	check_rectangle(t_game *game)
// {
// 	size_t	first_line_length;
// 	int	i;

// 	if (game->lines <= 0 || game->map == NULL || game->map[0] == NULL)
// 	{
// 		free_and_show_errors("Map Error : Empty or uninitialized map", game);
// 		return;
// 	}
// 	i = 1;
// 	first_line_length = ft_strlen(game->map[0]);
// 	while (i < game->lines)
// 	{
// 		if (ft_strlen(game->map[i]) != first_line_length)
// 		{
// 			free_and_show_errors("Map Error : Map is not rectangle", game);
// 			return;
// 		}
// 		i++;
// 	}

// }

// // is the map enclosed in walls / check the firt and last lines columns, they sould all be 1
// void	check_walls(t_game *game)
// {

// }
// // check exit / characters, position, collectible ... 
// void	check_charaters(t_game *game)
// {

// }
// check ber extension 

// validate map 
void	check_map(char *av, t_game *game)
{
	check_extension(av);
	// read and malloc map
	read_map(av, game);
	// check_rectangle(game);
}