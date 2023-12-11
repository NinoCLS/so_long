/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:18:08 by nclassea          #+#    #+#             */
/*   Updated: 2023/11/16 11:51:19 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*source;
	char	*destination;

	i = 0;
	source = (char *)src;
	destination = (char *)dest;
	if (destination == NULL && source == NULL)
		return (destination);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
