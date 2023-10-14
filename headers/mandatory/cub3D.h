#ifndef CUB3D_H
# define CUB3D_H

/*======================= LIBRAIRIES =======================*/

# include "../../library/headers/library.h"
# include "../../mlx/mlx_linux/mlx.h"
# include "../../mlx/mlx_mac/mlx.h"
# include <math.h>
/*======================= COULEUR =======================*/

# define END "\033[0m"
# define RED "\033[1;31m"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif



/*======================= DEFINE =======================*/

# define SIZE_X				1920
# define SIZE_Y				1080
# define SQUARE_SIZE		64

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

# ifdef __linux__
	# define LEFT_KEY	65361
	# define RIGHT_KEY	65363
	# define UP_KEY		65362
	# define DOWN_KEY	65364
	# define A_KEY		97
	# define W_KEY		119
	# define S_KEY		115
	# define D_KEY		100
	# define ESC		65307
# elif __APPLE__
	# define LEFT_KEY	123
	# define RIGHT_KEY	124
	# define UP_KEY		126
	# define DOWN_KEY	125
	# define A_KEY		0
	# define W_KEY		13
	# define S_KEY		1
	# define D_KEY		2
	# define ESC		53
# endif

# define ON_KEYDOWN		2
# define ON_KEYUP		3
# define ON_MOUSEDOWN	4
# define ON_MOUSEUP		5
# define ON_MOUSEMOVE	6
# define ON_EXPOSE		12
# define ON_DESTROY		17

/*======================= ENUMERATION =======================*/

enum {
	SUCCESS,
	FAILURE,
	ERROR = -1,
};

enum {
	MLX,
};

/*======================= STRUCTURES =======================*/

typedef struct s_draw {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_draw;


typedef struct s_data {
	void		*mlx;
	void		*win;
	char		**map;
	int			size_map;
	int			*len_line;
	int			gap;
	int			x_pers;
	int			y_pers;
	int			celling;
	int			floor;
	float		px_map;
	float		py_map;
	float		angle;
	float		xf_p;
	float		yf_p;
	float		x_dir;
	float		y_dir;	
	char		*north_path;
	char		*south_path;
	char		*east_path;
	char		*west_path;
	bool		N;
	bool		S;
	bool		W;
	bool		E;
	t_draw		N_texture;
	t_draw		S_texture;
	t_draw		W_texture;
	t_draw		E_texture;
	int			collision_cor[2];
	bool		horizontal;
	int			left_mouse;
	int			right_mouse;
	int			right;
	int			left;
	int			top;
	int			down;
	int			rot_left;
	int			rot_right;
}	t_data;

typedef struct s_parsing {
	int			nb_colors;
	int			nb_directions;
	int			nb_player;
	int			east;
	int			west;
	int			north;
	int			south;
	int			c_color;
	int			f_color;
	char		*color_c_path;
	char		*color_f_path;
	int			r;
	int			g;
	int			b;
	t_draw		texture_no;
	t_draw		texture_so;
	t_draw		texture_we;
	t_draw		texture_ea;
}	t_parsing;

typedef struct s_raycasting {
	t_data	*data;
	t_draw	*draw;
	float	cos_angle;
	float	sin_angle;
	float	shift;
	int		x;
}	t_raycasting;

//===================== PARSING =====================

int		parsing(char *file, t_data *data, t_parsing *utils);

//==== File ====

int		type_file_check(char *file);
int		ft_open(char *path);
int		is_empty_map(char *file, char *line);

//==== Map ====

// --- Utils map ---
int		is_map(char *line);
int		is_empty_line(char *line);
int		is_valid(char c);
char	**ft_copy_map(t_data *data);

// --- Fill map ---
int		get_size_map(char *path, t_data *data, char *line);
int		fill_map(char *path, t_data *data, char *line);
int		fill_len_line_array(t_data *data);

//--- Is valid map ---
int		is_one_player(t_data *data, t_parsing *utils);

//--- Get position ---
void	get_player_position(t_data *data);

//--- Is Map Closed ---
int		is_map_closed(t_data *data);
int		check_around(t_data *data, int y, int x, char **copy);
int		check_up(t_data *data, int y, int x, char **copy);
int		check_down(t_data *data, int y, int x, char **copy);
int		check_left(int y, int x, char **copy);
int		check_right(t_data *data, int y, int x, char **copy);
int		move_on_map(t_data *data, int y, int x, char **copy);

//==== Textures ====

// --- Read map ---
int		read_to_get_asset(char *path, t_parsing *utils, t_data *data);
int		is_right_asset_number(char *path, t_parsing *utils);
int		type_texture_check(t_parsing *utils, t_data *data);
int		asset_line_len(char *s);
char	*copy_asset(char *texture, char *s);
int		get_colors(t_parsing *utils, t_data *data);

// --- Free textures ---

void	free_textures(t_data *data);
void	clean_gnl(int fd, char *line);
void	free_asset(t_parsing *utils, t_data *data);
void	free_texture(char *texture);
void	free_all_colors(t_parsing *utils);


/*======================= GAME =======================*/

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