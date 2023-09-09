# ====================== VARIABLES ====================== #

# ---- Final Executable --- #

NAME			=	library.a

# ---- Directories and path data ---- #

INCLUDES		=	headers/

DIR_OBJS		=	.objs/

DIR_SRCS		=	${addprefix sources/, ${SRCS}}

SRCS			=	ft_dprintf/ft_dprintf.c\
					ft_dprintf/ft_check_args.c \
					ft_dprintf/ft_dprintf_char.c \
					ft_dprintf/ft_dprintf_nbr.c \
					\
					get_next_line/get_next_line_utils.c \
					get_next_line/get_next_line.c \
					\
					libft/char/ft_isalnum.c \
					libft/char/ft_isalpha.c \
					libft/char/ft_isascii.c \
					libft/char/ft_isdigit.c \
					libft/char/ft_isprint.c \
					libft/char/ft_tolower.c \
					libft/char/ft_toupper.c \
					\
					libft/mem/ft_memchr.c \
					libft/mem/ft_memcmp.c \
					libft/mem/ft_memcpy.c \
					libft/mem/ft_memmove.c \
					libft/mem/ft_memset.c \
					\
					libft/str/ft_atoi.c \
					libft/str/ft_bzero.c \
					libft/str/ft_calloc.c \
					libft/str/ft_free_array.c \
					libft/str/ft_itoa.c \
					libft/str/ft_split.c \
					libft/str/ft_strchr.c \
					libft/str/ft_strcmp.c \
					libft/str/ft_strdup.c \
					libft/str/ft_striteri.c \
					libft/str/ft_strjoin.c \
					libft/str/ft_strlcat.c \
					libft/str/ft_strlcpy.c \
					libft/str/ft_strlen.c \
					libft/str/ft_strmapi.c \
					libft/str/ft_strncmp.c \
					libft/str/ft_strndup.c \
					libft/str/ft_strnstr.c \
					libft/str/ft_strchr.c \
					libft/str/ft_strtrim.c \
					libft/str/ft_substr.c

HEADERS 		=	${INCLUDES}ft_dprintf.h \
					${INCLUDES}get_next_line.h \
					${INCLUDES}libft.h \
					${INCLUDES}library.h

OBJS			=	${addprefix ${DIR_OBJS},${DIR_SRCS:.c=.o}}

# ---- Compilation ---- #

CC				= cc

CFLAGS 			= -Wall -Wextra -Werror

# ---- Commands ---- #

RMF				=	rm -rf

# ====================== RULES ====================== #

# ---- Compiled rules ---- #

all:			${NAME}

${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

${DIR_OBJS}%.o: %.c ${HEADERS}
	@ mkdir -p ${dir $@}
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

# ---- Clean rules ---- #

clean:
	${RMF} ${OBJS} ${DIR_OBJS}

fclean:	clean
	${RMF} ${NAME}

re:	fclean
	${MAKE} all

.PHONY:	all clean fclean re