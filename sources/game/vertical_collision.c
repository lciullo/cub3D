#include "cub3D.h"

void	vertical_collision_neg(t_raycasting *raycasting, t_col_point *vertical);
void	vertical_collision_pos(t_raycasting *raycasting, t_col_point *vertical);

void    vertical_collision(t_raycasting *raycasting, t_col_point *vertical)
{
    if (raycasting->cos_angle > 0)
		vertical_collision_neg(raycasting, vertical);
	else if (raycasting->cos_angle < 0)
		vertical_collision_pos(raycasting, vertical);
}

void	vertical_collision_neg(t_raycasting *raycasting, t_col_point *vertical)
{
	float	y;
	float	x;
	float	pow_x;
	float	pow_y;
	float	x_shift;
	float	y_shift;
	float	distance;

	y = 0;
	x = 0;
	pow_x = 0;
	pow_y = 0;
	x_shift = 0;
	distance = 0;
	while (x <= raycasting->data->px_map)
		x += SQUARE_SIZE;
	x -= SQUARE_SIZE;
	x_shift = (x - raycasting->data->px_map) / raycasting->cos_angle;
	y = raycasting->data->py_map + x_shift * raycasting->sin_angle;
	y_shift = (SQUARE_SIZE / raycasting->cos_angle) * raycasting->sin_angle; 
	pow_x = pow((raycasting->data->px_map - x), 2);
	pow_y = pow((raycasting->data->py_map - y), 2);
	vertical->x = x;
	vertical->y = y;
	vertical->distance = sqrt(pow_x + pow_y);
}

void	vertical_collision_pos(t_raycasting *raycasting, t_col_point *vertical)
{
	float	y;
	float	x;
	float	pow_x;
	float	pow_y;
	float	x_shift;
	float	distance;

	y = 0;
	x = 0;
	pow_x = 0;
	pow_y = 0;
	x_shift = 0;
	distance = 0;;
	while (x <= raycasting->data->px_map)
		x += SQUARE_SIZE;
	x_shift = (x - raycasting->data->px_map) / raycasting->cos_angle;
	y = raycasting->data->py_map + x_shift * raycasting->sin_angle;
	pow_x = pow((raycasting->data->px_map - x), 2);
	pow_y = pow((raycasting->data->py_map - y), 2);
	vertical->x = x;
	vertical->y = y;
	vertical->distance = sqrt(pow_x + pow_y);
}