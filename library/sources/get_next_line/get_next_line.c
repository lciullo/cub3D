/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:49:46 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/12 16:04:49 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1] = "\0";
	char		*stash;

	stash = NULL;
	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFFER_SIZE <= 0)
	{
		stash = NULL;
		buffer[0] = '\0';
		return (NULL);
	}
	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if (ft_strlen(buffer) != 0)
		stash = ft_strdup(buffer);
	stash = ft_read(fd, buffer, stash);
	if (stash)
		ft_new_buffer(buffer);
	else
		stash = NULL;
	return (stash);
}

char	*ft_read(int fd, char *buffer, char *stash)
{
	int		read_bytes;
	char	*line;

	read_bytes = 1;
	while (read_bytes != 0 && ft_check_line(buffer) == 1)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			if (stash != NULL)
				free(stash);
			return (NULL);
		}
		if (read_bytes == 0)
			buffer[0] = '\0';
		buffer[read_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	line = ft_full_line(stash, 0, 0);
	return (line);
}

char	*ft_new_buffer(char	*buffer)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		while (buffer[i + 1])
		{
			buffer[j] = buffer[i + 1];
			j++;
			i++;
		}
	}
	buffer[j] = '\0';
	return (buffer);
}

int	ft_check_line(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

// Dans mon so_long j'avas modifié mon gnl de manière à que si il y a un \n a
//la fin de la ligne il ne soit pas dans le char * renvoyé par le programme

// Actuellement c'est un gnl normal
// Si tu veux le remodifié comme pour mon so_long tu as juste a effacé les
// lignes 109, 110, 111, 120, 121, 122, 123, 124
char	*ft_full_line(char *stash, int i, int j)
{
	char	*line;

	if (!(stash[i]))
		return (free(stash), NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!(line))
		return (free(stash), NULL);
	while (stash[j] && stash[j] != '\n')
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[j] == '\n')
	{
		line[j] = '\n';
		j++;
	}
	line[j] = '\0';
	free(stash);
	return (line);
}
