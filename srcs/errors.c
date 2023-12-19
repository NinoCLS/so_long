/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:32:50 by nclassea          #+#    #+#             */
/*   Updated: 2023/12/19 15:35:04 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	show_errors(char *err)
{
	ft_putstr_fd("ERROR -", 2);
	ft_putstr_fd(err, 2);
	// exit() add something to exit program 
}