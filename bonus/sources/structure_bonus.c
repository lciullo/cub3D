/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:17:09 by lciullo           #+#    #+#             */
/*   Updated: 2023/10/19 15:46:33 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

static void	init_struct_parsing(t_parsing *utils);
static void	init_struct_data(t_data *data);
static void	init_struct_key_hook(t_data *data);

void	init_struct(t_data *data, t_parsing *utils)
{
	init_struct_data(data);
	init_struct_parsing(utils);
	init_struct_key_hook(data);
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
	data->x_p = 0;
	data->y_p = 0;
	data->celling = 0;
	data->floor = 0;
	data->px_map = 0;
	data->py_map = 0;
	data->angle = M_PI_2;
	data->x_dir = 0;
	data->y_dir = 0;
	data->path.north = NULL;
	data->path.west = NULL;
	data->path.east = NULL;
	data->path.south = NULL;
	data->direction.n = false;
	data->direction.s = false;
	data->direction.w = false;
	data->direction.e = false;
	data->horizontal = false;
}

static void	init_struct_key_hook(t_data *data)
{
	data->key_hook.rotate_left = 0;
	data->key_hook.rotate_right = 0;
	data->key_hook.move_up = 0;
	data->key_hook.move_down = 0;
	data->key_hook.move_left = 0;
	data->key_hook.move_right = 0;
	data->key_hook.escape = 0;
	data->key_hook.left_mouse = 0;
	data->key_hook.right_mouse = 0;
	data->key_hook.mini_map = 1;
}

void	init_struct_raycasting(t_raycasting *raycasting, \
		t_data *data, t_draw *draw)
{
	raycasting->distance = 0;
	raycasting->draw = draw;
	raycasting->data = data;
	raycasting->opp = HALF_WIDTH;
	raycasting->adj = raycasting->opp / tan(M_PI / 6);
	raycasting->angle = (M_PI / 6) + data->angle;
}
