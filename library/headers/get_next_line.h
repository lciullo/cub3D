/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:39:21 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/12 10:45:46 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*======================= BUFFER_SIZE =======================*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*======================= PROTOTYPES =======================*/

/* ---- get_next_line_utils.c ----*/
unsigned int	next_line_len(char *buffer);
void			*ft_memmove_gnl(void *dst, const void *src, size_t len);
char			*ft_strjoin_gnl(char *s1, char *s2);

/* ---- get_next_line_utils.c ----*/
char			*get_next_line(int fd);
char			*read_the_line(char *buffer, int *end_file, int fd);
char			*next_line(char *buffer, int *end_file, int *i, int fd);
void			clean_buf(char *buffer, int *end_file);
char			*first_read(char *buffer, int *i);

#endif