/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:05:59 by nclassea          #+#    #+#             */
/*   Updated: 2023/11/14 10:53:09 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_nb_size(int nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len += 1;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	long	nb;

	nb = n;
	size = ft_nb_size(nb);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[size] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
	}
	size--;
	while (nb)
	{
		str[size] = ((nb % 10) + '0');
		size--;
		nb /= 10;
	}
	return (str);
}

// int	main(void)
// {
// 	__builtin_printf("%s", ft_itoa(18437));
// }
