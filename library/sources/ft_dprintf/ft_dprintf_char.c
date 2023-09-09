/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprint_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:04:58 by cllovio           #+#    #+#             */
/*   Updated: 2023/08/23 15:01:34 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

void	ft_putchar_fd(int c, int *count, int fd)
{
	if (*count != -1)
	{
		if (write(fd, &c, 1) != -1)
			*count = *count + 1;
		else
			*count = -1;
	}
}

void	ft_putstr_fd(char *s, int *count, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_fd("(null)", count, fd);
		return ;
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], count, fd);
		i++;
	}
}
