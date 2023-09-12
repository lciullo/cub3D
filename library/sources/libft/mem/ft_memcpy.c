/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:06:08 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/12 10:47:22 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*vdest;
	const char	*vsrc;

	if (dest == NULL && src == NULL)
		return (NULL);
	vdest = (char *) dest;
	vsrc = (const char *) src;
	i = 0;
	while (i < n)
	{
		vdest[i] = vsrc[i];
		i++;
	}
	return (dest);
}
