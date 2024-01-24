/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclassea <nclassea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 19:37:08 by nino              #+#    #+#             */
/*   Updated: 2024/01/23 18:23:54 by nclassea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strduplicate(char *s);
void	*ft_free(char *ptr);
char	*ft_strappend(char *line, char c)
{
	char	*new_line;
	int		i;

	if (!line)
	{
		new_line = malloc(2);
		if (!new_line)
			return (NULL);
		new_line[0] = c;
		new_line[1] = '\0';
	}
	else
	{
		for (i = 0; line[i]; i++);
		new_line = malloc(i + 2);
		if (!new_line)
			return (NULL);
		for (i = 0; line[i]; i++)
			new_line[i] = line[i];
		new_line[i++] = c;
		new_line[i] = '\0';
		free(line);
	}
	return (new_line);
}

void	*ft_free(char *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line = NULL;
	int		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while ((bytes_read = read(fd, &buffer, 1)) > 0)
	{
		line = ft_strappend(line, buffer);
		if (!line)
			return (NULL);
		if (buffer == '\n')
			break;
	}
	if (bytes_read < 0)
		return (ft_free(line));

	if (bytes_read == 0 && (!line || *line == '\0'))
		return (ft_free(line));

	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// int main(int argc, char **argv)
// {
//     int fd;
//     char *line;
// 	(void)argc;

//     fd = open(argv[1], O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("%s", line);
//         free(line);  
//     }

//     close(fd);
//     return (0);
// }