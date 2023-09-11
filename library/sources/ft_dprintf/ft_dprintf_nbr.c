/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisa <lisa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:05:21 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/11 12:12:33 by lisa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

// static int	ft_strlen(char *str);

void	ft_putnbr_fd(int n, int *count, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", count, fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', count, fd);
		ft_putnbr_fd(n * (-1), count, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, count, fd);
		ft_putnbr_fd(n % 10, count, fd);
	}
	if (n >= 0 && n <= 9)
		ft_putchar_fd(n + '0', count, fd);
}

void	ft_putnbr_base_fd(unsigned long nbr, char *base, int *count, int fd)
{
	unsigned long	base_size;

	base_size = (unsigned long)ft_strlen(base);
	if ((long long)nbr < 0)
	{
		ft_putchar_fd('-', count, fd);
		nbr = nbr * -1;
		ft_putnbr_base_fd(nbr, base, count, fd);
	}
	else if (nbr / base_size)
	{
		ft_putnbr_base_fd(nbr / base_size, base, count, fd);
		ft_putchar_fd(base[nbr % base_size], count, fd);
	}
	else
		ft_putchar_fd(base[nbr], count, fd);
}

// static int	ft_strlen(char *str)
// {
// 	int	len;

// 	len = 0;
// 	while (str[len])
// 		len++;
// 	return (len);
// }
