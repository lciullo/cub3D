/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:13:49 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/05 12:08:36 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		if ((line[i] == '\n') || (line[i] == ' '))
			count++;
		i++;
	}
	if (ft_strlen(line) == count)
		return (TRUE);
	return (FALSE);
}

void	get_pos(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' \
				|| data->map[y][x] == 'E' || data->map[y][x] == 'W')
			{
				data->y_pers = y;
				data->x_pers = x;
				data->yf_p = y + 0.5;
				data->xf_p = x + 0.5;
				if (data->map[y][x] == 'N')
					data->N = TRUE;
				else if (data->map[y][x] == 'S')
					data->S = TRUE;
				else if (data->map[y][x] == 'E')
					data->E = TRUE;
				else if (data->map[y][x] == 'W')
					data->W = TRUE;
			}
			x++;
		}
		y++;
	}
}

char	**ft_copy_map(t_data *data)
{
	int		y;
	char	**copy_map;

	y = 0;
	copy_map = (char **)ft_calloc((data->size_map + 1), sizeof(char *));
	if (!copy_map)
		return (NULL);
	while (data->map[y])
	{
		copy_map[y] = ft_strdup(data->map[y]);
		if (!copy_map[y])
			return (NULL);
		y++;
	}
	copy_map[y] = NULL;
	return (copy_map);
}
