/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:18:39 by nclassea          #+#    #+#             */
/*   Updated: 2023/11/14 16:15:40 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c, int start)
{
	int	i;
	int	count;

	i = start;
	count = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	*ft_getword(char const *s, char c, int start)
{
	char	*word;
	int		len;
	int		i;
	int		j;

	i = start;
	j = 0;
	len = ft_word_len(s, c, start);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

static void	fill_tab(char **split, char const *s, char c, int word_count)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (word < word_count)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			split[word] = ft_getword(s, c, i++);
		while (s[i] != c && s[i] != '\0')
			i++;
		word++;
	}
	split[word] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**res;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	fill_tab(res, s, c, words);
	return (res);
}

// int main ()
// {
//    char const *s = "Bonjour, comment ça va ?";
//    char c = ' ';

//    char **res = ft_split(s, c);

//    if (res)
//    {
//        int i = 0;
//        while (res[i])
//        {
//            __builtin_printf("%s\n", res[i]);
//            free(res[i]);
//            i++;
//        }
//        free(res);
//    }

//    return (0);
// }
