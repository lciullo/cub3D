# Constants
NAME		=	cub_3D
CFLAGS		=	-Wall -Wextra -Werror

# Directories path
DIR_SRCS	=	sources/
DIR_HEADERS	=	headers/
DIR_LIB		=	library/
LIB			=	$(DIR_LIB)library.a
DIR_MLX		=	mlx/

# Files path
HEADERS	=	$(DIR_HEADERS)clem.h \
			$(DIR_HEADERS)cub3D.h \
			$(DIR_LIB)/headers/library.h \
			$(DIR_HEADERS)lisa.h\

SRCS	=	$(DIR_SRCS)print.c

OBJS	=	$(SRCS:.c=.o)

# Rules
%.o: %.c	$(HEADERS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_HEADERS)

all:		$(NAME)

${NAME}:	$(LIB) ${OBJS}
			$(MAKE) -C $(DIR_MLX)
			$(CC) $(CFLAGS) $(OBJS) $(LIB) -Lmlx -lmlx -lX11 -lXext -L$(DIR_MLX) -o $(NAME)

$(LIB):
			$(MAKE) -C $(DIR_LIB)

clean:
			${RM} ${OBJS}
			$(MAKE) clean -C $(DIR_LIB)

fclean:		clean
			${RM} ${NAME}
			$(MAKE) fclean -C $(DIR_LIB)

re :		fclean all

.PHONY :	all clean fclean re mlx libft