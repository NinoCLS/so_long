/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:04:25 by nclassea          #+#    #+#             */
/*   Updated: 2023/12/19 15:35:38 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"




int main (int ac, char **av)
{
	t_game game;

	if (ac == 1)
		show_errors(ARG_ERROR1)
	if (ac > 2)
		show_errors(ARG_ERROR2)
	// check args
	// initialiser la game 
	init_game(&game, av);
	// start la game  
}















// errors managment =>
// display_error // freemap // 


// dossier parse => checkmap // fill_map //