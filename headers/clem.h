/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clem.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:44:54 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/14 13:40:31 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEM_H
# define CLEM_H

# include <math.h>

# define SIZE_X				1920
# define SIZE_Y				1080
# define SQUARE_SIZE		32
# define IMG_SIZE			256

# define H_WHITE			0xffffff
# define H_BLACK			0x000000
# define H_RED				0xff0000
# define H_GREEN			0x00ff00
# define H_DARKGREEN		0x01452c
# define H_BLUE				0x0000ff
# define H_YELLOW			0xffff00
# define H_ORANGE			0xffa500
# define H_PINK				0xffc0cb
# define H_PURPLE			0x800080
# define H_GREY				0x808080

typedef struct s_raycasting {
	t_data	*data;
	t_draw	*draw;
	float	cos_angle;
	float	sin_angle;
	float	shift;
	int		x;
}	t_raycasting;

/*======================= PROTOTYPES =======================*/

/* ---- draw/draw_game.c ----*/
void	draw_game(t_raycasting *raycasting, double distance);

/* ---- draw/draw_square.c ----*/
void	draw_square(t_draw *draw, int x, int y, int color);

/* ---- draw/my_mlx_pixel_put.c ----*/
void	my_mlx_pixel_put(t_draw *draw, int x, int y, int color);
int		my_mlx_pixel_get(t_draw *img, int x, int y);

/* ---- game/hook.c ----*/
void	hook(t_data *data);

/* ---- game/launch_mlx.c ----*/
int		launch_game(t_data *data);

/* ---- game/mini_map.c ----*/
void	mini_map(t_data *data, t_draw *draw);

/* ---- game/move.c ----*/
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

/* ---- game/raycasting.c ----*/
void	raycasting(t_data *data, t_draw *draw);

/* ---- game/render_next_frame.c ----*/
int		render_next_frame(t_data *data);

/* ---- game/set_start_value.c ----*/
int		set_start_value(t_data *data);

/* ---- print_eroor.c ----*/
void	print_error_mlx(void);

/* ---- quit.c ----*/
int		quit_game(t_data *data);

/* ---- structure.c ----*/
void	init_struct(t_data *data, t_parsing *utils);
void	init_struct_raycasting(t_raycasting *raycasting, t_data *data, \
		t_draw *draw);

#endif