/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:49:46 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 16:19:47 by lciullo          ###   ########.fr       */
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
		buffer[0] = '\0';
		return (NULL);
	}
	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if (ft_strlen_gnl(buffer) != 0)
	{
		stash = ft_strdup_gnl(buffer);
		if (!(stash))
			return (NULL);
	}
	stash = ft_read(fd, buffer, stash);
	if (stash)
		ft_new_buffer(buffer);
	else
		*buffer = 0;
	if (!stash || !ft_strlen_gnl(stash))
		return (NULL);
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
			return (free(stash), NULL);
		if (read_bytes == 0)
			buffer[0] = '\0';
		buffer[read_bytes] = '\0';
		stash = ft_strjoin_gnl(stash, buffer, 0);
		if (!(stash))
			return (NULL);
	}
	line = ft_full_line(stash, 0, 0);
	return (line);
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

char	*ft_new_buffer(char	*buffer)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n' && i < BUFFER_SIZE)
		i++;
	if (buffer[i] == '\n')
	{
		while (buffer[i + 1] && j < BUFFER_SIZE)
		{
			buffer[j] = buffer[i + 1];
			j++;
			i++;
		}
	}
	buffer[j] = '\0';
	return (buffer);
}

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
	return (free(stash), line);
}
