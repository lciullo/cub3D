/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:17:09 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/09 14:44:08 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_struct_data(t_data *data);
static void	init_struct_parsing(t_parsing *utils);

void	init_struct(t_data *data, t_parsing *utils)
{
	init_struct_data(data);
	init_struct_parsing(utils);
}

static void	init_struct_parsing(t_parsing *utils)
{
	utils->nb_player = 0;
	utils->north = 0;
	utils->south = 0;
	utils->east = 0;
	utils->west = 0;
	utils->c_color = 0;
	utils->f_color = 0;
	utils->north_path = NULL;
	utils->west_path = NULL;
	utils->east_path = NULL;
	utils->south_path = NULL;
	utils->color_c_path = NULL;
	utils->color_f_path = NULL;
}

static void	init_struct_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->map = NULL;
	data->size_map = 0;
	data->len_line = 0;
	data->gap = 10;
	data->x_pers = 0;
	data->y_pers = 0;
	data->celling = 0;
	data->floor = 0;
	data->px_map = 0;
	data->py_map = 0;
	data->angle = 0;
	data->xf_p = 0;
	data->yf_p = 0;
	data->x_dir = 0;
	data->y_dir = 0;
	data->N = false;
	data->S = false;
	data->W = false;
	data->E = false;
}

void	init_struct_raycasting(t_raycasting *raycasting, \
		t_data *data, t_draw *draw)
{
	raycasting->x = SIZE_X - 1;
	raycasting->draw = draw;
	raycasting->data = data;
}
