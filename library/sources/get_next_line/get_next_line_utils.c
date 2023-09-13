/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:49:35 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/13 17:41:47 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

size_t	ft_strlen_gnl(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *stash, char *buffer)
{
	int		i;
	int		k;
	char	*new_s;

	i = 0;
	k = 0;
	if (!(stash))
	{
		stash = malloc(sizeof(char));
		if (!(stash))
			return (NULL);
		stash[0] = '\0';
	}
	if (!(buffer))
		return (free(stash), NULL);
	new_s = malloc(sizeof(char) * (ft_strlen_gnl(stash) + ft_strlen_gnl(buffer) + 1));
	if (!new_s)
		return (free(stash), NULL);
	while (stash[i])
		new_s[k++] = stash[i++];
	i = 0;
	while (buffer[i])
		new_s[k++] = buffer[i++];
	new_s[k] = '\0';
	free(stash);
	return (new_s);
}

char	*ft_strdup_gnl(char *buffer)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen_gnl(buffer);
	dest = malloc(sizeof(char) * (len + 1));
	if (!(dest))
		return (NULL);
	while (buffer[i])
	{
		dest[i] = buffer[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
