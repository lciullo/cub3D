/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:42:04 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/17 13:22:14 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	is_it_a_direction(char c);

void	mini_map(t_data *data, t_draw *draw)
{
	int	x;
	int	y;
	int	x_square;
	int	y_square;

	y = 0;
	y_square = 0;
	while (data->map[y])
	{
		x = 0;
		x_square = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1' || data->map[y][x] == ' ')
				draw_square(draw, x_square / 2, y_square / 2, H_PINK);
			else if (is_it_a_direction(data->map[y][x]) == true)
				draw_square(draw, x_square / 2, y_square / 2, H_GREY);
			x++;
			x_square += SQUARE_SIZE;
		}
		y++;
		y_square += SQUARE_SIZE;
	}
	draw_square(draw, ((data->px_map - ((SQUARE_SIZE / 2)) + 8) / 2), \
	((data->py_map - ((SQUARE_SIZE / 2)) + 8) / 2), H_PURPLE);
}

static bool	is_it_a_direction(char c)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}
