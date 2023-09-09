/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:26:15 by cllovio           #+#    #+#             */
/*   Updated: 2023/08/23 15:00:57 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_check_args(char format, va_list args, int *count, int fd)
{
	if (format == 'c')
		ft_putchar_fd(va_arg(args, int), count, fd);
	else if (format == 's')
		ft_putstr_fd(va_arg(args, char *), count, fd);
	else if (format == 'p')
	{
		ft_putstr_fd("0x", count, fd);
		ft_putnbr_base_fd(va_arg(args, long long unsigned int), \
		HEXA_LOW, count, fd);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr_fd(va_arg(args, int), count, fd);
	else if (format == 'u')
		ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789", count, fd);
	else if (format == 'x')
		ft_putnbr_base_fd(va_arg(args, unsigned int), \
		HEXA_LOW, count, fd);
	else if (format == 'X')
		ft_putnbr_base_fd(va_arg(args, unsigned int),
			HEXA_UP, count, fd);
	else if (format == '%')
		ft_putchar_fd('%', count, fd);
}
