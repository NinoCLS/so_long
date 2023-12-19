/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:07:26 by nclassea          #+#    #+#             */
/*   Updated: 2023/12/14 14:47:48 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	char_c;

	i = 0;
	char_c = (char)c;
	while (s[i])
	{
		if (s[i] == char_c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && char_c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;
	size_t i;
	size_t j;

	if (!s1)
		s1 = malloc(1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc((len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		str[i] = s1[i];
	j = -1;
	while (++j < len_s2)
		str[i + j] = s2[j];
	str[len_s1 + len_s2] = '\0';
	free((void *)s1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}