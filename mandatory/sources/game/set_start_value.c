/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_start_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:35:08 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 15:04:59 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	set_start_direction(t_data *data);
static int	init_texture(t_draw *texture, char *texture_path, void *mlx);

int	set_start_value(t_data *data)
{
	data->px_map = (data->x_p * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	data->py_map = (data->y_p * SQUARE_SIZE) + (SQUARE_SIZE / 2);
	if (init_texture(&data->n_texture, data->path.north, data->mlx) == FAILURE)
		return (quit_game_error_image(data), FAILURE);
	if (init_texture(&data->s_texture, data->path.south, data->mlx) == FAILURE)
	{
		mlx_destroy_image(data->mlx, data->n_texture.img);
		return (quit_game_error_image(data), FAILURE);
	}
	if (init_texture(&data->w_texture, data->path.west, data->mlx) == FAILURE)
	{
		mlx_destroy_image(data->mlx, data->n_texture.img);
		mlx_destroy_image(data->mlx, data->s_texture.img);
		return (quit_game_error_image(data), FAILURE);
	}
	if (init_texture(&data->e_texture, data->path.east, data->mlx) == FAILURE)
	{
		mlx_destroy_image(data->mlx, data->n_texture.img);
		mlx_destroy_image(data->mlx, data->s_texture.img);
		mlx_destroy_image(data->mlx, data->w_texture.img);
		return (quit_game_error_image(data), FAILURE);
	}
	set_start_direction(data);
	return (SUCCESS);
}

static void	set_start_direction(t_data *data)
{
	if (data->direction.n == true)
		data->direction.n = false;
	else if (data->direction.s == true)
	{
		data->direction.s = false;
		data->angle += M_PI;
	}
	else if (data->direction.w == true)
	{
		data->direction.w = false;
		data->angle += M_PI_2;
	}
	else if (data->direction.e == true)
	{
		data->direction.e = false;
		data->angle -= M_PI_2;
	}
}

static int	init_texture(t_draw *texture, char *texture_path, void *mlx)
{
	int		size_1;
	t_img	*image;

	size_1 = IMG_SIZE;
	image = mlx_xpm_file_to_image(mlx, texture_path, &size_1, &size_1);
	if (!(image))
		return (print_error_mlx(), FAILURE);
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
	if (!(texture->addr))
	{
		mlx_destroy_image(mlx, texture->img);
		return (print_error_mlx(), FAILURE);
	}
	return (SUCCESS);
}
