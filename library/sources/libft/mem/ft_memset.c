/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:53:54 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/12 10:47:30 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*new_b;

	i = 0;
	new_b = (unsigned char *) b;
	while (i < len)
	{
		new_b[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
