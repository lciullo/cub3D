#include "cub3D.h"

static double horizontal_col_pos(t_raycasting *raycasting, t_pointf *xy);
static double horizontal_col_neg(t_raycasting *raycasting, t_pointf *xy);

double	horizontal_col(t_raycasting *raycasting, t_pointf *xy)
{
    double  distance;

    distance = 0;
	if (raycasting->sin_angle < 0)
		distance = horizontal_col_pos(raycasting, xy);
	else if (raycasting->sin_angle >= 0)
		distance = horizontal_col_neg(raycasting, xy);
    return (distance);
}

static double horizontal_col_pos(t_raycasting *raycasting, t_pointf *xy)
{
	float		depth_x;
	float		delta_depth;

	xy->y = 0;
	depth_x = 0;
	while (xy->y <= raycasting->data->py_map)
		xy->y += SQUARE_SIZE;
	xy->y -= SQUARE_SIZE;
	depth_x = (xy->y - raycasting->data->py_map) / raycasting->sin_angle;
	xy->x = raycasting->data->px_map + depth_x * raycasting->cos_angle + 0.000000001;
	delta_depth = (SQUARE_SIZE / -raycasting->sin_angle) * raycasting->cos_angle;
	while (((xy->x - 0.000000001) / SQUARE_SIZE)  > 0 && ((xy->y - 0.000000001) / SQUARE_SIZE)  > 0 && \
	((xy->y - 0.000000001) / SQUARE_SIZE)  < raycasting->data->size_map && \
	((xy->x - 0.000000001) / SQUARE_SIZE)  < raycasting->data->len_line[(int)((xy->y - 0.000000001) / SQUARE_SIZE)] && \
	(raycasting->data->map[(int)((xy->y - 0.000000001) / SQUARE_SIZE) ][(int)((xy->x - 0.000000001) / SQUARE_SIZE) ] != '1'))
	{
		xy->x += delta_depth;
		xy->y -= SQUARE_SIZE;
	}
    return(sqrt(powf((raycasting->data->px_map - xy->x), 2) + \
    powf((raycasting->data->py_map -  xy->y), 2)));
}

static double horizontal_col_neg(t_raycasting *raycasting, t_pointf *xy)
{
	float		depth_x;
	float		delta_depth;

	xy->y = 0;
	xy->x = 0;
	depth_x = 0;
	while (xy->y <= raycasting->data->py_map)
		xy->y += SQUARE_SIZE;
	depth_x = (xy->y - raycasting->data->py_map) / raycasting->sin_angle;
	xy->x = raycasting->data->px_map + depth_x * raycasting->cos_angle;
	delta_depth = (SQUARE_SIZE / raycasting->sin_angle) * raycasting->cos_angle;
	while ((xy->x / SQUARE_SIZE) > 0 && (xy->y / SQUARE_SIZE) > 0 && \
	(xy->y / SQUARE_SIZE) < raycasting->data->size_map && \
	(xy->x / SQUARE_SIZE) < raycasting->data->len_line[(int)(xy->y / SQUARE_SIZE)] && \
	(raycasting->data->map[(int)(xy->y / SQUARE_SIZE)][(int)(xy->x / SQUARE_SIZE)] != '1'))
	{
		xy->x += delta_depth;
		xy->y += SQUARE_SIZE;
	}
    return(sqrt(powf((raycasting->data->px_map - xy->x), 2) + \
    powf((raycasting->data->py_map -  xy->y), 2)));
}
