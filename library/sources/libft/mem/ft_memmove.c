/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:52:36 by cllovio           #+#    #+#             */
/*   Updated: 2023/09/12 10:47:25 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*vdest;
	const char	*vsrc;

	vdest = (char *)dest;
	vsrc = (const char *)src;
	if (vdest <= vsrc)
		ft_memcpy(dest, src, len);
	else
	{
		while (len > 0)
		{
			vdest[len - 1] = vsrc[len - 1];
			len--;
		}
	}
	return (dest);
}
