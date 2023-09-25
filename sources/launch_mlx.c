#include "cub3D.h"

void	find_pers(t_data *data);

int	launch_mlx(t_data *data)
{
	data->gap = 10;
	data->N = true;
	data->S = false;
	data->W = false;
	data->E = false;
	find_pers(data);
	data->square_x = data->x_pers * (SIZE_X / find_len_max(data->len_line, data->size_map));
	data->square_y = data->y_pers * (SIZE_X / find_len_max(data->len_line, data->size_map));
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	data->win = mlx_new_window(data->mlx, SIZE_X, SIZE_Y, "cubi_rose");
	if (data->win == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	hook(data);
	return (SUCCESS);
}

void	generate_image(t_data *data)
{
	t_draw	map;

	map.img = mlx_new_image(data->mlx, SIZE_X, SIZE_Y);
	map.addr = mlx_get_data_addr(map.img, &map.bits_per_pixel, \
	&map.line_length, &map.endian);
	mini_map(data, &map);
	mlx_put_image_to_window(data->mlx, data->win, map.img, 0, 0);
	mlx_destroy_image(data->mlx, map.img);
}

void	find_pers(t_data *data)
{
	int	x;
	int y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'W' || data->map[y][x] == 'E')
			{
				data->x_pers = x;
				data->y_pers = y;
				break ;
			}
			x++;
		}
		y++;
	}
}

int	render_next_frame(t_data *data)
{
	generate_image(data);
	mlx_do_sync(data->mlx);
	return (0);
}