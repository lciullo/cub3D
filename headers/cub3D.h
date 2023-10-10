#ifndef CUB3D_H
# define CUB3D_H

/*======================= LIBRAIRIES =======================*/

# include "../library/headers/library.h"
# include "../mlx/mlx_linux/mlx.h"
# include "../mlx/mlx_mac/mlx.h"

/*======================= COULEUR =======================*/

# define END "\033[0m"
# define RED "\033[1;31m"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

/*======================= ENUMERATION =======================*/

enum {
	SUCCESS,
	FAILURE,
	ERROR = -1,
};

enum {
	MLX,
};

/*======================= DEFINE =======================*/

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

/*======================= STRUCTURES =======================*/

typedef struct	s_draw {
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
	t_draw		*N_texture;
	t_draw		*S_texture;
	t_draw		*W_texture;
	t_draw		*E_texture;
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


# include "lisa.h"
# include "clem.h"
# include "../library/headers/library.h"

#endif