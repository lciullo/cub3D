/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:36:07 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/12 15:59:40 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static double	get_wall_distance(t_raycasting *raycasting);
static void		init_angle_struct_raycasting(int i, t_raycasting *raycasting, \
				t_data *data);
// static bool		did_we_reach_a_wall(t_raycasting *raycasting, float x, float y);


#include <stdio.h>

void	raycasting(t_data *data, t_draw *draw)
{
	int				i;
	t_col_point		vertical;
	t_col_point		horizontal;
	t_raycasting	raycasting;

	i = 1;
	
	init_struct_raycasting(&raycasting, data, draw);
	// while (i <= SIZE_X)
	// {
		init_angle_struct_raycasting(i, &raycasting, data);
		vertical_collision(&raycasting, &vertical);
		horizontal_collision(&raycasting, &horizontal);
		if (horizontal.distance < vertical.distance)
			my_mlx_pixel_put(raycasting.draw, (horizontal.x / 2), (horizontal.y / 2), H_WHITE);
		else
			my_mlx_pixel_put(raycasting.draw, (vertical.x / 2), (vertical.y / 2), H_GREEN);
		// draw_game(&raycasting, distance);
		i++;
		// raycasting.x--;
	// }
}

static void	init_angle_struct_raycasting(int i, t_raycasting *raycasting, \
			t_data *data)
{
	data->collision_cor[0] = 0;
	data->collision_cor[1] = 0;
	raycasting->shift = ((float)i / SIZE_X) + 1;
	raycasting->cos_angle = -cosf(raycasting->shift * (M_PI / 3) + data->angle);
	raycasting->sin_angle = sinf(raycasting->shift * (M_PI / 3) + data->angle);
	raycasting->shift = (raycasting->shift - 1.5) * (M_PI / 3);
}

/*static bool	did_we_reach_a_wall(t_raycasting *raycasting, float x, float y)
{
	if (raycasting->data->map[(int)(y)][(int)(x)] == '1')
		return (true);
	return (false);
}*/
