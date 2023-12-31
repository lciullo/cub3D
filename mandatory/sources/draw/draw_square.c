/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:31 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 12:33:50 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	get_size(int color);

void	draw_square(t_draw *draw, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;
	int	x_value;

	i = 0;
	j = 0;
	x_value = x;
	size = get_size(color);
	while (j < size)
	{
		i = 0;
		x = x_value;
		while (i < size)
		{
			my_mlx_pixel_put(draw, x, y, color);
			x++;
			i++;
		}
		j++;
		y++;
	}
}

static int	get_size(int color)
{
	if (color == H_PINK || color == H_GREY)
		return (SQUARE_SIZE / 2);
	else if (color == H_PURPLE)
		return ((SQUARE_SIZE / 2) / 2);
	return (0);
}
