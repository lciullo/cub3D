/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cllovio <cllovio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:22:54 by lciullo           #+#    #+#             */
/*   Updated: 2023/09/12 10:47:48 by cllovio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	*ft_calloc(size_t nb_elements, size_t size)
{
	void	*ptr;

	if (!nb_elements || !size)
		return (malloc(0));
	if (size != 0 && nb_elements > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nb_elements * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nb_elements * size);
	return (ptr);
}
