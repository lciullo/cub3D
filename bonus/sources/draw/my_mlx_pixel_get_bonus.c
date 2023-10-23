/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_get_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:36:20 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 15:28:08 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	my_mlx_pixel_get(t_draw *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (!(x >= 0 && x < 256) || !(y >= 0 && y < 256))
		return (*(uint32_t *)(img->addr + (255 * img->line_length + 255 * \
		(img->bits_per_pixel / 8))));
	return (*(uint32_t *)dst);
}
