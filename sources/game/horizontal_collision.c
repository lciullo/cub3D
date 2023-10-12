#include "cub3D.h"

void	horizontal_collision_neg(t_raycasting *raycasting, t_col_point *horizontal);
void	horizontal_collision_pos(t_raycasting *raycasting, t_col_point *horizontal);

void    horizontal_collision(t_raycasting *raycasting, t_col_point *horizontal)
{
    if (raycasting->sin_angle < 0)
		horizontal_collision_neg(raycasting, horizontal);
    else if (raycasting->sin_angle > 0)
		horizontal_collision_pos(raycasting, horizontal);
}

void	horizontal_collision_neg(t_raycasting *raycasting, t_col_point *horizontal)
{
	float	y;
	float	x;
	float	pow_x;
	float	pow_y;
	float	y_shift;
	float	distance;
	
	y = 0;
	x = 0;
	pow_x = 0;
	pow_y = 0;
	y_shift = 0;
	distance = 0;
	while (y <= raycasting->data->py_map)
		y += SQUARE_SIZE;
	y_shift = (y - raycasting->data->py_map) / raycasting->sin_angle;
	x = raycasting->data->px_map + y_shift * raycasting->cos_angle;
	pow_x = pow((raycasting->data->px_map - x), 2);
	pow_y = pow((raycasting->data->py_map - y), 2);
	distance = sqrt(pow_x + pow_y);
	horizontal->x = x;
	horizontal->y = y;
	horizontal->distance = sqrt(pow_x + pow_y);
}

void	horizontal_collision_pos(t_raycasting *raycasting, t_col_point *horizontal)
{
	float	y;
	float	x;
	float	pow_x;
	float	pow_y;
	float	y_shift;
	float	distance;
	
	y = 0;
	x = 0;
	pow_x = 0;
	pow_y = 0;
	y_shift = 0;
	distance = 0;
	while (y <= raycasting->data->py_map)
		y += SQUARE_SIZE;
	y -= SQUARE_SIZE;
	y_shift = (y - raycasting->data->py_map) / raycasting->sin_angle;
	x = raycasting->data->px_map + y_shift * raycasting->cos_angle;
	pow_x = pow((raycasting->data->px_map - x), 2);
	pow_y = pow((raycasting->data->py_map - y), 2);
	horizontal->x = x;
	horizontal->y = y;
	horizontal->distance = sqrt(pow_x + pow_y);
}