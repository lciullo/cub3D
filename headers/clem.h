#ifndef CLEM_H
# define CLEM_H

# include <math.h>

# define SIZE_X				1920
# define SIZE_Y				1080
# define SQUARE_SIZE		40

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

typedef struct	s_draw {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_draw;

typedef struct s_draw_vector {
	t_data	*data;
	t_draw	*draw;
	float	px_map;
	float	py_map;
	float	c_angle;
	float	s_angle;
	float	decalage;
	int		x;
}	t_draw_vector;

/*======================= PROTOTYPES =======================*/

/* ---- draw/draw_direction.c ----*/
void	draw_direction_vector(t_data *data, t_draw *draw);

/* ---- draw/draw_rectangle.c ----*/
void	draw_frame(t_draw *draw, int color);

/* ---- draw/draw_rectangle.c ----*/
void	draw_vertical_rectangle(t_draw *draw, int x, int y, int color);
void	draw_horizontal_rectangle(t_draw *draw, int x, int y, int color);

/* ---- draw/draw_sqaure.c ----*/
void	draw_square(t_draw *draw, int x, int y, int color, int size);

/* ---- draw/my_mlx_pixel_put.c ----*/
void	my_mlx_pixel_put(t_draw *data, int x, int y, int color);

/* ---- hook.c ----*/
void	hook(t_data *data);
int		key_hook(int key_code, t_data *data);

/* ---- launch_mlx.c ----*/
int		launch_mlx(t_data *data);
void	generate_image(t_data *data);
int		render_next_frame(t_data *data);

/* ---- move.c ----*/
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

/* ---- quit.c ----*/
int		quit_game(t_data *data);

/* ---- utils.c ----*/
void	print_error_messages(int error_code);

void    mini_map(t_data *data, t_draw *draw);
int		find_len_max(int *len_line, int size_map);
void 	find_direction(t_data *data);

int    collision_front(t_data *data);

#endif