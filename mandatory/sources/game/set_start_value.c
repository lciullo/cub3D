/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:35:08 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 10:46:36 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_start_direction(t_data *data);
static int	init_texture(t_draw *texture, char *texture_path, void *mlx);

int	set_start_value(t_data *data)
{
	data->px_map = (data->x_pers * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	data->py_map = (data->y_pers * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	if (init_texture(&data->N_texture, data->north_path, data->mlx) == FAILURE)
		return (quit_game(data), FAILURE);
	if (init_texture(&data->S_texture, data->south_path, data->mlx) == FAILURE)
	{
		mlx_destroy_image(data->mlx, data->N_texture.img);
		return (quit_game(data), FAILURE);
	}
	if (init_texture(&data->W_texture, data->west_path, data->mlx) == FAILURE)
	{
		mlx_destroy_image(data->mlx, data->N_texture.img);
		mlx_destroy_image(data->mlx, data->S_texture.img);
		return (quit_game_error_image(data), FAILURE);
	}
	if (init_texture(&data->E_texture, data->east_path, data->mlx) == FAILURE)
	{
		mlx_destroy_image(data->mlx, data->N_texture.img);
		mlx_destroy_image(data->mlx, data->S_texture.img);
		mlx_destroy_image(data->mlx, data->W_texture.img);
		return (quit_game(data), FAILURE);
	}
	set_start_direction(data);
	return (SUCCESS);
}

static void	set_start_direction(t_data *data)
{
	if (data->N == true)
		data->N = false;
	else if (data->S == true)
	{
		data->S = false;
		data->angle += M_PI;
	}
	else if (data->W == true)
	{
		data->W = false;
		data->angle += M_PI_2;
	}
	else if (data->E == true)
	{
		data->E = false;
		data->angle -= M_PI_2;
	}
}

static int	init_texture(t_draw *texture, char *texture_path, void *mlx)
{
	int		size_1;
	t_img	*image;

	size_1 = IMG_SIZE;
	image = mlx_xpm_file_to_image(mlx, texture_path, &size_1, &size_1);
	if (image->width != IMG_SIZE || image->height != IMG_SIZE)
	{
		mlx_destroy_image(mlx, image);
		ft_dprintf(2, "Error\nWrong size image\n");
		return (FAILURE);
	}
	mlx_destroy_image(mlx, image);
	texture->img = mlx_xpm_file_to_image(mlx, texture_path, &size_1, &size_1);
	if (!(texture->img))
		return (print_error_mlx(), FAILURE);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
	&texture->line_length, &texture->endian);
	if (!(texture->img))
		return (print_error_mlx(), FAILURE);
	return (SUCCESS);
}
