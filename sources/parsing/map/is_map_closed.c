/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:10:54 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/09 17:43:59 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_map_closed(t_data *data, t_parsing *utils)
{
	char	**copy_map;

	copy_map = ft_copy_map(data);
	if (!copy_map)
	{
		secure_free_array(data->map, data->size_map);
		if (data->len_line)
			free(data->len_line);
		free_textures(utils);
		return (FAILURE);
	}
	if (move_on_map(data, data->y_pers, data->x_pers, copy_map) == FAILURE)
	{
		ft_dprintf(2, "Error\nMap isn't closed\n");
		secure_free_array(copy_map, data->size_map);
		secure_free_array(data->map, data->size_map);
		if (data->len_line)
			free(data->len_line);
		free_textures(utils);
		return (FAILURE);
	}
	secure_free_array(copy_map, data->size_map);
	if (data->len_line)
		free(data->len_line);
	return (SUCCESS);
}

int	move_on_map(t_data *data, int y, int x, char **copy)
{
	copy[y][x] = '1';
	if (check_around(data, y, x, copy) == FAILURE)
		return (FAILURE);
	if (check_up(data, y, x, copy) == SUCCESS && \
		move_on_map(data, y - 1, x, copy) == FAILURE)
		return (FAILURE);
	if (check_down(data, y, x, copy) == SUCCESS && \
		move_on_map(data, y + 1, x, copy) == FAILURE)
		return (FAILURE);
	if (check_right(data, y, x, copy) == SUCCESS \
		&& move_on_map(data, y, x + 1, copy) == FAILURE)
		return (FAILURE);
	if (check_left(y, x, copy) == SUCCESS \
		&& move_on_map(data, y, x - 1, copy) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
