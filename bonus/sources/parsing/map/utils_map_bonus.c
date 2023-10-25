/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:13:49 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/19 15:29:43 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	is_map(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (FALSE);
	while (line[i])
	{
		if (is_valid(line[i]) == TRUE)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	is_valid(char c)
{
	if ((c == '1') || (c == '0') || (c == ' ') || (c == 'W') || \
		(c == 'S') || (c == 'N') || (c == 'E') || (c == '\n'))
		return (TRUE);
	return (FALSE);
}

int	is_empty_line(char *line)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if ((line[i] == '\n') || (line[i] == ' ') || (line[i] == '\t'))
			count++;
		i++;
	}
	if (ft_strlen(line) == count)
		return (TRUE);
	return (FALSE);
}

char	**ft_copy_map(t_data *data)
{
	int		y;
	char	**copy_map;

	y = 0;
	if (!data->map)
		return (NULL);
	copy_map = (char **)ft_calloc((data->size_map + 1), sizeof(char *));
	if (!copy_map)
	{
		ft_dprintf(2, "Error\nMalloc failed in ft_copy_map\n");
		return (NULL);
	}
	while (data->map[y])
	{
		copy_map[y] = ft_strdup(data->map[y]);
		if (!copy_map[y])
		{
			secure_free_array(copy_map, data->size_map);
			ft_dprintf(2, "Error\nMalloc failed in ft_copy_map\n");
			return (NULL);
		}
		y++;
	}
	copy_map[y] = NULL;
	return (copy_map);
}
