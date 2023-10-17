DIR_SRCS	=	sources/

SRCS		= 	$(DIR_SRCS)main.c \
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
				$(DIR_SRCS)parsing/clean/clean_parsing.c 				