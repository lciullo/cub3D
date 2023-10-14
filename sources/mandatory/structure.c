/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:17:09 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/14 11:28:53 by lciullo          ###   ########.fr       */
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
	data->north_path = NULL;
	data->west_path = NULL;
	data->east_path = NULL;
	data->south_path = NULL;
	data->N = false;
	data->S = false;
	data->W = false;
	data->E = false;
	data->horizontal = false;
	data->right = 0;
	data->left = 0;
	data->top = 0;
	data->down = 0;
	data->rot_left = 0;
	data->rot_right = 0;
}

void	init_struct_raycasting(t_raycasting *raycasting, \
		t_data *data, t_draw *draw)
{
	raycasting->x = SIZE_X - 1;
	raycasting->draw = draw;
	raycasting->data = data;
}
