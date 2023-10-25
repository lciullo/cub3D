/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:31 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 15:28:02 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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
