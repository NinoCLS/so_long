/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:43:23 by nclassea          #+#    #+#             */
/*   Updated: 2023/11/10 11:50:13 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char const	*data;
	unsigned char		val;

	i = 0;
	data = (unsigned char *)s;
	val = (unsigned char)c;
	while (i < n)
	{
		if (data[i] == val)
			return ((void *)&s[i]);
		i++;
	}
	return (NULL);
}
