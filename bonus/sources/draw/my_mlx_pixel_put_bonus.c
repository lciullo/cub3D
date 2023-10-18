/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:20:39 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/18 16:14:33 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	my_mlx_pixel_put(t_draw *draw, int x, int y, int color)
{
	if ((x >= 0 && x < SIZE_X) && (y >= 0 && y < SIZE_Y))
		((int *)draw->addr)[y * (draw->line_length >> 2) + x] = color;
}

int	my_mlx_pixel_get(t_draw *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (!(x >= 0 && x < 256) || !(y >= 0 && y < 256))
		return (*(uint32_t *)(img->addr + (255 * img->line_length + 255 * \
		(img->bits_per_pixel / 8))));
	return (*(uint32_t *)dst);
}
