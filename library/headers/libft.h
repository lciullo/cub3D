/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:01:44 by lciullo           #+#    #+#             */
/*   Updated: 2023/09/12 10:45:53 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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

/* ---- char/ ----*/
bool	ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(char *line);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/* ---- mem/ ----*/
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/* ---- str/ ----*/
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
