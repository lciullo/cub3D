#include paths/sources_lisa.mk
#include paths/sources_clem.mk

# ---- Variables ---- #
NAME		=	cub3D
OS			=	$(shell uname)
DEBUG		=	no

# ---- Directories ---- #

DIR_SRCS	=	sources/mandatory/

SRCS		= 	$(DIR_SRCS)draw/draw_game.c\
				$(DIR_SRCS)draw/draw_square.c\
				$(DIR_SRCS)draw/my_mlx_pixel_put.c\
				$(DIR_SRCS)game/hook.c\
				$(DIR_SRCS)game/launch_game.c\
				$(DIR_SRCS)game/mini_map.c\
				$(DIR_SRCS)game/move.c\
				$(DIR_SRCS)game/raycasting.c\
				$(DIR_SRCS)game/render_next_frame.c\
				$(DIR_SRCS)game/set_start_value.c\
				$(DIR_SRCS)print_error.c\
				$(DIR_SRCS)quit.c \
				$(DIR_SRCS)main.c \
				$(DIR_SRCS)structure.c \
				$(DIR_SRCS)parsing/parsing.c \
				$(DIR_SRCS)parsing/file/file.c \
				$(DIR_SRCS)parsing/map/is_map_closed.c \
				$(DIR_SRCS)parsing/map/check_around.c \
				$(DIR_SRCS)parsing/map/is_valid_player.c \
				$(DIR_SRCS)parsing/map/utils_map.c \
				$(DIR_SRCS)parsing/map/fill_map.c \
				$(DIR_SRCS)parsing/map/map_size.c \
				$(DIR_SRCS)parsing/asset/is_right_format.c \
				$(DIR_SRCS)parsing/asset/fill_asset.c \
				$(DIR_SRCS)parsing/asset/get_color.c \
				$(DIR_SRCS)parsing/asset/asset_utils.c \
				$(DIR_SRCS)fill/find_textures.c  \
				$(DIR_SRCS)parsing/clean/clean_asset.c \
				$(DIR_SRCS)parsing/clean/clean_gnl.c 
	
DIR_OBJS	=	.objs/
DIR_HEADERS	=	headers/mandatory/
DIR_LIB		=	library/
LIB			=	$(DIR_LIB)library.a

# ---- Flags ---- #
CFLAGS		=	-Wall -Wextra -Werror -O3 -g3 -I $(DIR_LIB) -I $(DIR_MLX) -I $(DIR_HEADERS)
CFLAGS		+=	-Wno-deprecated-declarations
MLX_FLAGS	=	-L$(DIR_MLX) -lm


ifeq ($(OS), Darwin)
MLX_FLAGS 	+= -lmlx -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
MLX_FLAGS 	+= -lmlx -lX11 -lXext -L$(DIR_MLX)
endif

# ---- mlx ---- #
ifeq ($(OS), Darwin)
DIR_MLX	=	mlx/mlx_mac
else ifeq ($(OS), Linux)
DIR_MLX	=	mlx/mlx_linux
endif

# ---- Files ---- #
HEADERS	=	$(DIR_HEADERS)cub3D.h \
			$(DIR_LIB)/headers/library.h 

OBJS	=	$(addprefix $(DIR_OBJS),$(SRCS:.c=.o))

# ---- Command ---- #
RMF		=	rm -rf

# ====================== RULES ====================== #

# ---- Compilation rules ---- #

all:		$(NAME)

${NAME}:	$(LIB) ${OBJS}
			make -C $(DIR_MLX)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_FLAGS) -o $(NAME)

$(DIR_OBJS)%.o: %.c	$(HEADERS)
			@ mkdir -p ${dir $@}
			$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)

# ---- Library rule ---- #
$(LIB) :
			$(MAKE) -C $(DIR_LIB)

# ---- Norm rule ---- #
norm:
			clear
			norminette $(DIR_SRCS) $(DIR_HEADERS) $(DIR_LIB)

# ---- Clean rules ---- #
re :		fclean all

clean:
			${RMF} ${OBJS} ${DIR_OBJS}
			$(MAKE) clean -C $(DIR_LIB)

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C $(DIR_LIB)

.PHONY :	all debug norm re clean fclean 