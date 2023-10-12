
# ---- Variables ---- #
NAME		=	cub3D
OS			=	$(shell uname)
BONUS		= 	no

# ---- Includes ---- #

DIR_LIB		=	library/

LIB			=	$(DIR_LIB)library.a

ifeq ($(OS), Darwin)
DIR_MLX	=	mlx/mlx_mac
else ifeq ($(OS), Linux)
DIR_MLX	=	mlx/mlx_linux
endif

DIR_HEADERS		=	headers/mandatory/

DIR_HEADERS_BONUS = headers/bonus/

HEADERS		=	$(DIR_HEADERS)cub3D.h \
				$(DIR_HEADERS_BONUS)cub3D.h \
				$(DIR_LIB)/headers/library.h 

# ---- Sources ---- #

DIR_MANDATORY	=	sources/mandatory/

MANDATORY		= 	$(DIR_MANDATORY)draw/draw_game.c\
					$(DIR_MANDATORY)draw/draw_square.c\
					$(DIR_MANDATORY)draw/my_mlx_pixel_put.c\
					$(DIR_MANDATORY)game/hook.c\
					$(DIR_MANDATORY)game/launch_game.c\
					$(DIR_MANDATORY)game/mini_map.c\
					$(DIR_MANDATORY)game/move.c\
					$(DIR_MANDATORY)game/raycasting.c\
					$(DIR_MANDATORY)game/render_next_frame.c\
					$(DIR_MANDATORY)game/set_start_value.c\
					$(DIR_MANDATORY)print_error.c\
					$(DIR_MANDATORY)quit.c \
					$(DIR_MANDATORY)main.c \
					$(DIR_MANDATORY)structure.c \
					$(DIR_MANDATORY)parsing/parsing.c \
					$(DIR_MANDATORY)parsing/file/file.c \
					$(DIR_MANDATORY)parsing/map/is_map_closed.c \
					$(DIR_MANDATORY)parsing/map/check_around.c \
					$(DIR_MANDATORY)parsing/map/is_valid_player.c \
					$(DIR_MANDATORY)parsing/map/utils_map.c \
					$(DIR_MANDATORY)parsing/map/fill_map.c \
					$(DIR_MANDATORY)parsing/map/map_size.c \
					$(DIR_MANDATORY)parsing/asset/is_right_format.c \
					$(DIR_MANDATORY)parsing/asset/fill_asset.c \
					$(DIR_MANDATORY)parsing/asset/get_color.c \
					$(DIR_MANDATORY)parsing/asset/asset_utils.c \
					$(DIR_MANDATORY)fill/find_textures.c  \
					$(DIR_MANDATORY)parsing/clean/clean_asset.c \
					$(DIR_MANDATORY)parsing/clean/clean_gnl.c 

DIR_BONUS		=	sources/bonus/

BONUS			= 	$(DIR_BONUS)draw/draw_game.c\
					$(DIR_BONUS)draw/draw_square.c\
					$(DIR_BONUS)draw/my_mlx_pixel_put.c\
					$(DIR_BONUS)game/hook.c\
					$(DIR_BONUS)game/launch_game.c\
					$(DIR_BONUS)game/mini_map.c\
					$(DIR_BONUS)game/move.c\
					$(DIR_BONUS)game/raycasting.c\
					$(DIR_BONUS)game/render_next_frame.c\
					$(DIR_BONUS)game/set_start_value.c\
					$(DIR_BONUS)print_error.c\
					$(DIR_BONUS)quit.c \
					$(DIR_BONUS)main.c \
					$(DIR_BONUS)structure.c \
					$(DIR_BONUS)parsing/parsing.c \
					$(DIR_BONUS)parsing/file/file.c \
					$(DIR_BONUS)parsing/map/is_map_closed.c \
					$(DIR_BONUS)parsing/map/check_around.c \
					$(DIR_BONUS)parsing/map/is_valid_player.c \
					$(DIR_BONUS)parsing/map/utils_map.c \
					$(DIR_BONUS)parsing/map/fill_map.c \
					$(DIR_BONUS)parsing/map/map_size.c \
					$(DIR_BONUS)parsing/asset/is_right_format.c \
					$(DIR_BONUS)parsing/asset/fill_asset.c \
					$(DIR_BONUS)parsing/asset/get_color.c \
					$(DIR_BONUS)parsing/asset/asset_utils.c \
					$(DIR_BONUS)fill/find_textures.c  \
					$(DIR_BONUS)parsing/clean/clean_asset.c \
					$(DIR_BONUS)parsing/clean/clean_gnl.c 
	

# ---- Objs directory ---- #

DIR_OBJS	=	.objs/

OBJS		=	$(addprefix $(DIR_OBJS),$(MANDATORY:.c=.o))

# ---- Flags ---- #
CFLAGS		=	-Wall -Wextra -Werror -O3 -g3 -Wno-deprecated-declarations -I $(DIR_LIB) -I $(DIR_MLX) -I $(DIR_HEADERS)

# ---- MLX ---- #

MLX_FLAGS	=	-L$(DIR_MLX) -lm

ifeq ($(OS), Darwin)
MLX_FLAGS 	+= -lmlx -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
MLX_FLAGS 	+= -lmlx -lX11 -lXext -L$(DIR_MLX)
endif



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

# ---- Clean rules ---- #

clean:
			$(MAKE) -C $(DIR_LIB) clean
			$(RMF) $(DIR_OBJS)

fclean:		clean
			$(MAKE) -C $(DIR_LIB) fclean
			$(RMF)  $(NAME)

re :		fclean 
			$(MAKE) all

.PHONY :	all lib clean fclean re