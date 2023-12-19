/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:43:42 by nclassea          #+#    #+#             */
/*   Updated: 2023/12/19 15:03:02 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"

// add MSG ERROR 
# define ARG_ERROR1 "Missing map (maps/*.ber)"


// struct image 





// struct game

typedef struct s_game
{
	char	**map;
	char	**av;
	void	*window;
	void	*mlx;
	int		lines;
	int		columns;
	int		player_num;
	int		collect_num;
	int		exit_num;
	int		moves;
	int		temp;
	int		fd;
	int		arrow_position;
	int		x;
	int		y;
}	t_game;

#endif


/*init game*/


/*read map*/

/*check map*/