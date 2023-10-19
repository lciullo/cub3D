/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lciullo <lciullo@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:07:03 by cllovio           #+#    #+#             */
/*   Updated: 2023/10/19 16:19:59 by lciullo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY_H
# define LIBRARY_H

/*======================= INCLUDE =======================*/
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <limits.h>
# include <stdarg.h>

/*======================= DEFINE =======================*/
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*======================= ENUMERATION =======================*/
enum {
	PRINT,
	DO_NOT,
};

enum {
	EMPTY,
	NOT_EMPTY,
};

enum {
	TRUE = 1,
	FALSE = 0,
};

/*======================= PROTOTYPES =======================*/

/* ---- ft_dprintf/ft_d_printf.c ----*/
int		ft_dprintf(int fd, const char *format, ...);

/* ---- ft_dprintf/ft_chek_args.c ----*/
void	ft_check_args(char format, va_list args, int *count, int fd);

/* ---- ft_dprintf/ft_dprintf_char.c ----*/
void	ft_putchar_fd(int c, int *count, int fd);
void	ft_putstr_fd(char *s, int *count, int fd);

/* ---- ft_dprintf/ft_dprintf_nbr.c ----*/
void	ft_putnbr_fd(int n, int *count, int fd);
void	ft_putnbr_base_fd(unsigned long nbr, char *base, int *count, int fd);

/* ---- get_next_line/get_next_line.c ----*/
char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer, char *stash);
char	*ft_new_buffer(char	*buffer);
int		ft_check_line(char *buffer);
char	*ft_full_line(char *stash, int i, int j);

/* ---- get_next_line/get_next_line_utils.c ----*/
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *stash, char *buffer, int i);
char	*ft_strdup_gnl(char *buffer);

/* ---- libft/char/ ----*/
bool	ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(char *line);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* ---- libft/mem/ ----*/
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/* ---- libft/str/ ----*/
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nb_elements, size_t size);
void	free_array(char **arr);
void	secure_free_array(char **arr, size_t line);
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *str, int c);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
char	*ft_strcpy(char *dest, const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strndup(char *dest, char *src, unsigned int n);
char	*ft_strnstr(const char *str, const char *search, size_t n);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif