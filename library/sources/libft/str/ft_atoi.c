/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:09:33 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/12 10:47:40 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		if (result != (result * 10 + (str[i] - 48)) / 10 && sign == -1)
			return (0);
		if (result != (result * 10 + (str[i] - 48)) / 10 && sign == 1)
			return (-1);
		i++;
	}
	return ((int)(result * sign));
}
