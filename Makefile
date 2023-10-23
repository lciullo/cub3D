# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lciullo <lciullo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 12:33:09 by lciullo           #+#    #+#              #
#    Updated: 2023/10/20 08:58:41 by lciullo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---- Variables ---- #

NAME			=	cub3D

OS				=	$(shell uname)

R_BONUS			= 	no

RMF				=	rm -rf

# ---- Libraries ---- #

DIR_LIB			=	library/

LIB				=	$(DIR_LIB)library.a

DIR_MLX	=	mlx/mlx_linux

# ---- Directories  mandatory ---- #

DIR_HEADERS		=	mandatory/headers/

HEADERS			= 	$(DIR_HEADERS)cub3D.h \
					$(DIR_LIB)/headers/library.h
				
DIR_MANDATORY	=	mandatory/sources/

MANDATORY		=	$(DIR_MANDATORY)draw/draw_game.c\
					$(DIR_MANDATORY)draw/draw_square.c\
					$(DIR_MANDATORY)draw/get_pixel_textures.c\
					$(DIR_MANDATORY)draw/my_mlx_pixel_get.c\
					$(DIR_MANDATORY)draw/my_mlx_pixel_put.c\
					$(DIR_MANDATORY)game/raycasting/horizontal_col.c\
					$(DIR_MANDATORY)game/raycasting/raycasting.c\
					$(DIR_MANDATORY)game/raycasting/vertical_col.c\
					$(DIR_MANDATORY)game/check_collision.c\
					$(DIR_MANDATORY)game/hook.c\
					$(DIR_MANDATORY)game/launch_game.c\
					$(DIR_MANDATORY)game/move.c\
					$(DIR_MANDATORY)game/render_next_frame.c\
					$(DIR_MANDATORY)game/set_start_value.c\
					$(DIR_MANDATORY)parsing/asset/asset_utils.c\
					$(DIR_MANDATORY)parsing/asset/copy_asset_utils.c\
					$(DIR_MANDATORY)parsing/asset/fill_asset.c\
					$(DIR_MANDATORY)parsing/asset/get_color.c\
					$(DIR_MANDATORY)parsing/asset/is_right_format.c\
					$(DIR_MANDATORY)parsing/clean/clean_parsing.c\
					$(DIR_MANDATORY)parsing/file/file.c\
					$(DIR_MANDATORY)parsing/map/check_around.c\
					$(DIR_MANDATORY)parsing/map/fill_map.c\
					$(DIR_MANDATORY)parsing/map/is_map_closed.c\
					$(DIR_MANDATORY)parsing/map/is_valid_player.c\
					$(DIR_MANDATORY)parsing/map/map_size.c\
					$(DIR_MANDATORY)parsing/map/utils_map.c\
					$(DIR_MANDATORY)parsing/parsing.c\
					$(DIR_MANDATORY)main.c\
					$(DIR_MANDATORY)quit.c\
					$(DIR_MANDATORY)structure.c

# ---- Directories  bonus ---- #

DIR_H_BONUS		=	bonus/headers/

H_BONUS			= 	$(DIR_H_BONUS)cub3D_bonus.h \
					$(DIR_LIB)/headers/library.h

DIR_BONUS		=	bonus/sources/

BONUS			=	$(DIR_BONUS)draw/draw_game_bonus.c\
					$(DIR_BONUS)draw/draw_square_bonus.c\
					$(DIR_BONUS)draw/get_pixel_textures_bonus.c\
					$(DIR_BONUS)draw/my_mlx_pixel_get_bonus.c\
					$(DIR_BONUS)draw/my_mlx_pixel_put_bonus.c\
					$(DIR_BONUS)game/raycasting/horizontal_col_bonus.c\
					$(DIR_BONUS)game/raycasting/raycasting_bonus.c\
					$(DIR_BONUS)game/raycasting/vertical_col_bonus.c\
					$(DIR_BONUS)game/check_collision_bonus.c\
					$(DIR_BONUS)game/hook_bonus.c\
					$(DIR_BONUS)game/launch_game_bonus.c\
					$(DIR_BONUS)game/mini_map_bonus.c\
					$(DIR_BONUS)game/mouse_move_bonus.c\
					$(DIR_BONUS)game/move_bonus.c\
					$(DIR_BONUS)game/render_next_frame_bonus.c\
					$(DIR_BONUS)game/set_start_value_bonus.c\
					$(DIR_BONUS)parsing/asset/asset_utils_bonus.c\
					$(DIR_BONUS)parsing/asset/copy_asset_utils_bonus.c\
					$(DIR_BONUS)parsing/asset/fill_asset_bonus.c\
					$(DIR_BONUS)parsing/asset/get_color_bonus.c\
					$(DIR_BONUS)parsing/asset/is_right_format_bonus.c\
					$(DIR_BONUS)parsing/clean/clean_parsing_bonus.c\
					$(DIR_BONUS)parsing/file/file_bonus.c\
					$(DIR_BONUS)parsing/map/check_around_bonus.c\
					$(DIR_BONUS)parsing/map/fill_map_bonus.c\
					$(DIR_BONUS)parsing/map/is_map_closed_bonus.c\
					$(DIR_BONUS)parsing/map/is_valid_player_bonus.c\
					$(DIR_BONUS)parsing/map/map_size_bonus.c\
					$(DIR_BONUS)parsing/map/utils_map_bonus.c\
					$(DIR_BONUS)parsing/parsing_bonus.c\
					$(DIR_BONUS)main_bonus.c\
					$(DIR_BONUS)quit_bonus.c\
					$(DIR_BONUS)structure_bonus.c
					
DIR_OBJS	    =	.objs/

# ---- Flags ---- #

ifeq ($(R_BONUS), no)
CFLAGS		=	-Wall -Wextra -Werror -O3  -Wno-deprecated-declarations -I $(DIR_LIB) -I $(DIR_MLX) -I $(DIR_HEADERS)
else
CFLAGS		=	-Wall -Wextra -Werror -O3  -Wno-deprecated-declarations -I $(DIR_LIB) -I $(DIR_MLX) -I $(DIR_H_BONUS)
endif

# ---- MLX ---- #

MLX_FLAGS		=	-L$(DIR_MLX) -lm

MLX_FLAGS 	+= -lmlx -lX11 -lXext -L$(DIR_MLX)

# ---- Directory  objs ---- #

ifeq ($(R_BONUS), no)
OBJS		=	$(addprefix $(DIR_OBJS),$(MANDATORY:.c=.o))
else
OBJS		=	$(addprefix $(DIR_OBJS),$(BONUS:.c=.o))
endif

# ====================== RULES ====================== #

# ---- Compilation rules ---- #

all:		
			${MAKE} lib
			${MAKE} ${NAME}

${NAME}:	$(LIB) ${OBJS}
			make -C $(DIR_MLX)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_FLAGS) -o $(NAME)

ifeq ($(R_BONUS), no)
$(DIR_OBJS)%.o: %.c	$(HEADERS)
			@ mkdir -p ${dir $@}
			$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)
else
$(DIR_OBJS)%.o: %.c	$(H_BONUS)
			@ mkdir -p ${dir $@}
			$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_H_BONUS)
endif

# ---- Library rule ---- #

$(LIB) :	
			$(MAKE) -C $(DIR_MLX)
			$(MAKE) -C $(DIR_LIB)
						
bonus:
			$(MAKE) R_BONUS=yes

# ---- Clean rules ---- #

re :		fclean 
			$(MAKE) all
clean:
		$(MAKE) -C $(DIR_LIB) clean
		$(MAKE) -C $(DIR_MLX) clean
		$(RMF) $(DIR_OBJS)

fclean:
		$(MAKE) clean
		$(MAKE) -C $(DIR_LIB) fclean
		$(RMF) $(NAME)

.PHONY :	all lib clean fclean  bonus re	