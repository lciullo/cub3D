#include "cub3D.h"

static double vertical_col_pos(t_raycasting *raycasting, t_pointf *xy);
static double vertical_col_neg(t_raycasting *raycasting, t_pointf *xy);

double	vertical_col(t_raycasting *raycasting, t_pointf *xy)
{
    double  distance;

    distance = 0;
	if (raycasting->cos_angle > 0)
		distance = vertical_col_pos(raycasting, xy);
	else if (raycasting->cos_angle < 0)
		distance = vertical_col_neg(raycasting, xy);
    return (distance);
}

static double vertical_col_pos(t_raycasting *raycasting, t_pointf *xy)
{
	float		depth_y;
	float		delta_depth;

	xy->y = 0;
    xy->x = 0;
	depth_y = 0;
	while (xy->x <= raycasting->data->px_map)
		xy->x += SQUARE_SIZE;
	depth_y = (xy->x - raycasting->data->px_map) / raycasting->cos_angle;
	xy->y = raycasting->data->py_map + depth_y * raycasting->sin_angle;
	delta_depth = (SQUARE_SIZE / raycasting->cos_angle) * raycasting->sin_angle;
	while ((xy->x / SQUARE_SIZE)  > 0 && (xy->y / SQUARE_SIZE)  > 0 && \
	(xy->y / SQUARE_SIZE)  < raycasting->data->size_map && \
	(xy->x / SQUARE_SIZE)  < raycasting->data->len_line[(int)(xy->y / SQUARE_SIZE)] && \
	raycasting->data->map[(int)(xy->y / SQUARE_SIZE) ][(int)(xy->x / SQUARE_SIZE) ] != '1')
	{
		xy->y += delta_depth;
		xy->x += SQUARE_SIZE;
	}
    return(sqrt(powf((raycasting->data->px_map - xy->x), 2) + \
    powf((raycasting->data->py_map -  xy->y), 2)));
}

static double vertical_col_neg(t_raycasting *raycasting, t_pointf *xy)
{
	float		depth_y;
	float		delta_depth;

	xy->y = 0;
	xy->x = 0;
	depth_y = 0;
	while (xy->x <= raycasting->data->px_map)
		xy->x += SQUARE_SIZE;
    xy->x -= SQUARE_SIZE;
	depth_y = (xy->x - raycasting->data->px_map) / raycasting->cos_angle + 0.000000001;
	xy->y = raycasting->data->py_map + depth_y * raycasting->sin_angle;
	delta_depth = (SQUARE_SIZE / -raycasting->cos_angle) * raycasting->sin_angle;
	while (((xy->x - 0.000000001) / SQUARE_SIZE)  > 0 && ((xy->y - 0.000000001) / SQUARE_SIZE)  > 0 && \
	((xy->y - 0.000000001) / SQUARE_SIZE)  < raycasting->data->size_map && \
	((xy->x - 0.000000001) / SQUARE_SIZE)  < raycasting->data->len_line[(int)((xy->y - 0.000000001) / SQUARE_SIZE)] && \
	raycasting->data->map[(int)((xy->y - 0.000000001) / SQUARE_SIZE) ][(int)((xy->x - 0.000000001) / SQUARE_SIZE) ] != '1')
	{
		xy->y += delta_depth;
		xy->x -= SQUARE_SIZE;
	}
    return(sqrt(powf((raycasting->data->px_map - xy->x), 2) + \
    powf((raycasting->data->py_map -  xy->y), 2)));
}
