# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 12:33:09 by lciullo           #+#    #+#              #
#    Updated: 2023/10/18 12:47:06 by lciullo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- Variables ---- #

NAME		=	cub3D
OS			=	$(shell uname)
RMF		=	rm -rf

# ---- Libraries ---- #

DIR_LIB		=	library/

LIB			=	$(DIR_LIB)library.a

ifeq ($(OS), Darwin)
DIR_MLX	=	mlx/mlx_mac
else ifeq ($(OS), Linux)
DIR_MLX	=	mlx/mlx_linux
endif

# ---- Directories ---- #

DIR_HEADERS	=	headers/

HEADERS		= 	$(DIR_HEADERS)cub3D.h \
				$(DIR_LIB)/headers/library.h
				
DIR_OBJS	=	.objs/

DIR_SRCS	=	sources/

SRCS		=	$(DIR_SRCS)main.c \
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
				$(DIR_SRCS)parsing/clean/clean_parsing.c \
				$(DIR_SRCS)draw/draw_game.c \
				$(DIR_SRCS)draw/get_pixel_textures.c \
				$(DIR_SRCS)draw/draw_square.c \
				$(DIR_SRCS)draw/my_mlx_pixel_put.c \
				$(DIR_SRCS)game/hook.c \
				$(DIR_SRCS)game/launch_game.c \
				$(DIR_SRCS)game/mini_map.c \
				$(DIR_SRCS)game/move.c \
				$(DIR_SRCS)game/raycasting.c \
				$(DIR_SRCS)game/render_next_frame.c \
				$(DIR_SRCS)game/set_start_value.c \
				$(DIR_SRCS)print_error.c \
				$(DIR_SRCS)quit.c


# ---- Flags ---- #

CFLAGS		=	-Wall -Wextra -Werror -O3 -g3 -Wno-deprecated-declarations -I $(DIR_LIB) -I $(DIR_MLX) -I $(DIR_HEADERS)

# ---- MLX ---- #

MLX_FLAGS	=	-L$(DIR_MLX) -lm

ifeq ($(OS), Darwin)
MLX_FLAGS 	+= -lmlx -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
MLX_FLAGS 	+= -lmlx -lX11 -lXext -L$(DIR_MLX)
endif

OBJS	=	$(addprefix $(DIR_OBJS),$(SRCS:.c=.o))

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