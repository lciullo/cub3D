#ifndef CLEM_H
# define CLEM_H

# define H_WHITE            0xffffff
# define H_BLACK            0x000000
# define H_RED                0xff0000
# define H_GREEN            0x00ff00
# define H_DARKGREEN        0x01452c
# define H_BLUE                0x0000ff
# define H_YELLOW            0xffff00
# define H_ORANGE            0xffa500
# define H_PINK                0xffc0cb
# define H_PURPLE            0x800080
# define H_GREY                0x808080

typedef struct	s_draw {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_draw;

int		launch_mlx(t_data *data, t_draw *draw);
int		quit_game(t_data *data);
void	print_error_messages(int error_code);
void	hook(t_data *data);
int		key_hook(int key_code, t_data *data);
void    my_mlx_pixel_put(t_draw *data, int x, int y, int color);
void	draw_square(t_draw *draw, int x, int y, int color, int size);

#endif