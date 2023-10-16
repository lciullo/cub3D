/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:31:19 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/16 10:35:06 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_mlx(t_data *data);

int	launch_game(t_data *data)
{
	if (init_mlx(data) == FAILURE)
		return (FAILURE);
	hook(data);
	return (SUCCESS);
}

static int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (print_error_mlx(), quit_game(data), FAILURE);
	if (set_start_value(data) == FAILURE)
		return (FAILURE);
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cubi_rose");
	if (data->win == NULL)
		return (print_error_mlx(), quit_game(data), FAILURE);
	return (SUCCESS);
}
