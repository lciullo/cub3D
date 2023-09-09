/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 11:05:45 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/09 12:37:12 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

# include "library.h"

/*======================= DEFINE =======================*/
# define HEXA_LOW "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

/*======================= PROTOTYPES =======================*/

/* ---- ft_d_printf.c ----*/
int		ft_dprintf(int fd, const char *format, ...);

/* ---- ft_chek_args.c ----*/
void	ft_check_args(char format, va_list args, int *count, int fd);

/* ---- ft_dprintf_char.c ----*/
void	ft_putchar_fd(int c, int *count, int fd);
void	ft_putstr_fd(char *s, int *count, int fd);

/* ---- ft_dprintf_nbr.c ----*/
void	ft_putnbr_fd(int n, int *count, int fd);
void	ft_putnbr_base_fd(unsigned long nbr, char *base, int *count, int fd);

#endif