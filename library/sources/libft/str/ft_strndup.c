/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 08:38:25 by lciullo           #+#    #+#             */
/*   Updated: 2023/09/12 10:48:25 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

char	*ft_strndup(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	dest = malloc(sizeof(char) * n + 1);
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
