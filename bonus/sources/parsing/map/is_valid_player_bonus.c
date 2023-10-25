/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_player_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:11:23 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/19 15:29:34 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	count_nb_player(t_data *data, t_parsing *utils);
static	void	fill_player_directions(t_data *data, int y, int x);

int	is_one_player(t_data *data, t_parsing *utils)
{
	count_nb_player(data, utils);
	if (utils->nb_player != 1)
	{
		free_textures(data);
		secure_free_array(data->map, data->size_map);
		free(data->len_line);
		ft_dprintf(2, "Error\nYou must add one player\n");
		return (FAILURE);
	}
	return (SUCCESS);
}

static void	count_nb_player(t_data *data, t_parsing *utils)
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
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || \
					data->map[y][x] == 'E' || data->map[y][x] == 'W')
				utils->nb_player++;
			x++;
		}
		y++;
	}
}

void	get_player_position(t_data *data)
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
				fill_player_directions(data, y, x);
			x++;
		}
		y++;
	}
}

static	void	fill_player_directions(t_data *data, int y, int x)
{
	data->y_p = y;
	data->x_p = x;
	if (data->map[y][x] == 'N')
		data->direction.n = TRUE;
	else if (data->map[y][x] == 'S')
		data->direction.s = TRUE;
	else if (data->map[y][x] == 'E')
		data->direction.e = TRUE;
	else if (data->map[y][x] == 'W')
		data->direction.w = TRUE;
}
