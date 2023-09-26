include paths/sources_lisa.mk
include paths/sources_clem.mk

# ---- Variables ---- #
NAME		=	cub3D
OS			=	$(shell uname)
DEBUG		=	no

# ---- Directories ---- #
DIR_SRCS	=	sources/
DIR_OBJS	=	.objs/
DIR_HEADERS	=	headers/
DIR_LIB		=	library/
LIB			=	$(DIR_LIB)library.a

# ---- Flags ---- #
CFLAGS		=	-Wall -Wextra -Werror
CFLAGS		+=	-Wno-deprecated-declarations
<<<<<<< Updated upstream
DFLAGS		=	-g3	-fsanitize=address
MLX_FLAGS	=	-L$(DIR_MLX) -lm
=======
DFLAGS		=	-g3 -fsanitize=address
MLX_FLAGS	=	-L$(DIR_MLX)
>>>>>>> Stashed changes

ifeq ($(OS), Darwin)
MLX_FLAGS 	+= -lmlx -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
MLX_FLAGS 	+= -lmlx -lX11 -lXext -L$(DIR_MLX)
endif

ifeq ($(DEBUG), yes)
CFLAGS	+=	$(DFLAGS)
endif

# ---- mlx ---- #
ifeq ($(OS), Darwin)
DIR_MLX	=	mlx/mlx_mac
else ifeq ($(OS), Linux)
DIR_MLX	=	mlx/mlx_linux
endif

# ---- Files ---- #
HEADERS	=	$(DIR_HEADERS)clem.h \
			$(DIR_HEADERS)cub3D.h \
			$(DIR_LIB)/headers/library.h \
			$(DIR_HEADERS)lisa.h

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

# ---- Debug rule ---- #
debug:
			clear
			$(MAKE) re DEBUG=yes

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