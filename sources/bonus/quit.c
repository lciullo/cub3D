/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:43:32 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/10 13:36:55 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

#ifdef __linux__

int	quit_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	secure_free_array(data->map, data->size_map);
	free_textures(data);
	free(data->mlx);
	exit(0);
	return (0);
}

#elif __APPLE__

int	quit_game(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	secure_free_array(data->map, data->size_map);
	free_textures(data);
	exit(0);
	return (0);
}

#endif
