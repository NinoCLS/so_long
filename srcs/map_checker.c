/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:45:09 by nclassea          #+#    #+#             */
/*   Updated: 2024/01/17 16:11:53 by nclassea         ###   ########.fr       */
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
		show_errors(OPEN_ERROR);
	if (read(fd, &buf, 1) == -1)
	{
		close(fd);
		show_errors(READ_ERROR);
	}
	close(fd);
}

// //check if rectangle
// void	check_rectangle(t_game *game)
// {
	
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
}