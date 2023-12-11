/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:32:04 by nino              #+#    #+#             */
/*   Updated: 2023/11/14 10:38:07 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*data;
	unsigned char	val;

	i = 0;
	data = s;
	val = (unsigned char)c;
	while (i < n)
	{
		data[i] = val;
		i++;
	}
	return (data);
}
