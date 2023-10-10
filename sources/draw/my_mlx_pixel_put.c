/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:39 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/10 17:47:34 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_draw *draw, int x, int y, int color)
{
	if ((x >= 0 && x < SIZE_X) && (y >= 0 && y < SIZE_Y))
		((int *)draw->addr)[y * (draw->line_length >> 2) + x] = color;
}

#include "stdio.h"

int	my_mlx_pixel_get(t_draw *img, int x, int y)
{
	char	*dst;

	if ((x >= 0 && x < 100) && (y >= 0 && y < 100))
		dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	else
		return (0);
	return (*(unsigned int *)dst);
}
