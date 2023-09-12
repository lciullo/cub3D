/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 12:30:48 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/12 16:06:24 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i] && count != -1)
	{
		if (format[i] == '%')
		{
			i++;
			ft_check_args(format[i], args, &count, fd);
			if (!format[i])
				break ;
		}
		else
			ft_putchar_fd(format[i], &count, fd);
		i++;
	}
	va_end(args);
	return (count);
}
