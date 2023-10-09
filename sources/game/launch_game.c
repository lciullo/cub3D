/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:31:19 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/09 17:09:23 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	init_mlx(t_data *data);
void init_texture(t_data *data);

int	launch_game(t_data *data)
{
	if (init_mlx(data) == FAILURE)
		return (FAILURE);
	set_start_value(data);
	hook(data);
	return (SUCCESS);
}

static int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (print_error_mlx(), quit_game(data), FAILURE);
	init_texture(data);
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cubi_rose");
	if (data->win == NULL)
		return (print_error_mlx(), quit_game(data), FAILURE);
	return (SUCCESS);
}

void init_texture(t_data *data)
{
	int	size_1;
	int	size_2;

	size_1 = 100;
	size_2 = 100;
	data->N_texture = malloc(sizeof(t_draw));
	if (!(data->N_texture))
		return ;
	data->N_texture->img = mlx_xpm_file_to_image(data->mlx, "./textures/north.xpm", &size_1, &size_2);
	if ((data->N_texture->img))
		return ;
	data->N_texture->addr = mlx_get_data_addr(data->N_texture->img, &data->N_texture->bits_per_pixel, &data->N_texture->line_length, &data->N_texture->endian);
	if (!(data->N_texture->img))
		return ;
}
