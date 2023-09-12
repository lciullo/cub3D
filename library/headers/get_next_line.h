/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:39:21 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/12 11:36:30 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*======================= BUFFER_SIZE =======================*/
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/*======================= PROTOTYPES =======================*/

/* ---- get_next_line.c ----*/
char	*get_next_line(int fd);
char	*ft_read(int fd, char *buffer, char *stash);
char	*ft_new_buffer(char	*buffer);
int		ft_check_line(char *buffer);
char	*ft_full_line(char *stash, int i, int j);

/* ---- get_next_line_utils.c ----*/
size_t	ft_strlen_gnl(char *s);
char	*ft_strjoin_gnl(char *stash, char *buffer);
char	*ft_strdup_gnl(char *buffer);

#endif