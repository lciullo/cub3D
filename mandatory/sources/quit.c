/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:43:32 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 13:01:31 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	quit_game_error_image(t_data *data)
{
	if (data->len_line)
		free(data->len_line);
	secure_free_array(data->map, data->size_map);
	free_textures(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

int	quit_game(t_data *data)
{
	secure_free_array(data->map, data->size_map);
	free_textures(data);
	mlx_destroy_image(data->mlx, data->N_texture.img);
	mlx_destroy_image(data->mlx, data->S_texture.img);
	mlx_destroy_image(data->mlx, data->W_texture.img);
	mlx_destroy_image(data->mlx, data->E_texture.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
