/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:02:43 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/19 16:08:04 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	mouse_move(t_data *data)
{
	if (data->key_hook.left_mouse == 1)
	{
		data->angle += M_PI / 64;
		data->key_hook.left_mouse = 0;
		mlx_mouse_move(data->mlx, data->win, HALF_WIDTH, HALF_HEIGHT);
	}
	else if (data->key_hook.right_mouse == 1)
	{
		data->angle -= M_PI / 64;
		data->key_hook.right_mouse = 0;
		mlx_mouse_move(data->mlx, data->win, HALF_WIDTH, HALF_HEIGHT);
	}
}
