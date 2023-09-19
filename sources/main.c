#include "cub3D.h"

int	main(int ac, char **av)
{
	t_data	data;
	t_draw	draw;

	(void)av;
	(void)draw;
	if (ac != 2)
	{
		ft_dprintf(2, "Error\nWrong number of arguments\n");
		return (FAILURE);
	}
	init_struct(&data);
	if (parsing(av[1], &data) == FAILURE)
		return (FAILURE);
	/*if (launch_mlx(&data, &draw) == FAILURE)
		return (FAILURE);*/
	return (0);
}

int	launch_mlx(t_data *data, t_draw *draw)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	data->win = mlx_new_window(data->mlx, 1920, 1080, "cubi_rose");
	if (data->win == NULL)
		return (print_error_messages(MLX), quit_game(data), FAILURE);
	draw->img = mlx_new_image(data->mlx, 1920, 1080);
	draw->addr = mlx_get_data_addr(draw->img, &draw->bits_per_pixel, &draw->line_length, &draw->endian);
	mlx_put_image_to_window(data->mlx, data->win, draw->img, 0, 0);
	mlx_destroy_image(data->mlx, draw->img);
	hook(data);
	mlx_loop(data->mlx);
	return (SUCCESS);
}

void	draw_square(t_draw *draw, int x, int y, int color, int size)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	(void)color;
	while (j < size)
	{
		i = 0;
		x = 550;
		while (i < size)
		{
			my_mlx_pixel_put(draw, x, y, H_RED);
			x++;
			i++;
		}
		j++;
		y++;
	}
}